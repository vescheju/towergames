#include "pch.h"
#include "Game.h"
#include "ItemRoad.h"
#include "ItemHouse.h"
#include "ItemTree.h"
#include "ItemOpen.h"
#include "BalloonRed.h"
#include "XmlLoader.h"
#include "RoadLinker.h"
#include "GoButton.h"
#include "Menu.h"
#include "ButtonVisitor.h"
#include "DamageVisitor.h"
#include "ItemRemover.h"
#include "GrabVisitor.h"
#include "BalloonBoss.h"
#include "VisibilityUpdater.h"
#include "LevelProgressor.h"

using namespace std;
using namespace xmlnode;
using namespace Gdiplus;


const int ScoreX = 1124;
const int ScoreY = 949;

/**
 * Add an item to the game
 * \param item New item to add
 */
void CGame::Add(std::shared_ptr<CItem> item)
{
    mItems.push_back(item);
}

/**
 * remove items from game
 * \param items Items to remove
 */
void CGame::Remove(std::vector<CItem*> items)
{
    //iterate through the items in items vector
    for (auto removeItem : items)
    {
        // iterate through mItems vector
        for (int i = 0; i < static_cast<int>(mItems.size()); ++i)
        {
            // if they are the same item (same address in memory),
            // remove it from mItems
            if (&(*removeItem) == &(*(mItems[i])))
            {
                mItems.erase(mItems.begin()+i);
                break;
            }
        }
    }
}

/**
 * Draw the game area
 * \param graphics The GDI+ graphics context to draw on
 * \param width Width of the client window
 * \param height Height of the client window
 */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
    // Fill the background with black
    SolidBrush brush(Color::Black);
    graphics->FillRectangle(&brush, 0, 0, width, height);

    
    //
    // Automatic Scaling
    //
    float scaleX = float(width) / float(mWidth);
    float scaleY = float(height) / float(mHeight);
    mScale = min(scaleX, scaleY);

    // Ensure it is centered vertically
    mYOffset = (float)((height - mHeight * mScale) / 2);
    
    graphics->TranslateTransform(mXOffset, mYOffset);
    graphics->ScaleTransform(mScale, mScale);

    // draw the items
    for (auto item : mItems)
    {
           item->Draw(graphics);
    }
    if (mMenu != nullptr)
    {
        mMenu->Draw(graphics);
    }
}

/**
 * Load the level from an XML file.
 *
 * passes the filename to the Xml Loader
 *
 * \param filename The filename of the level to load the level from.
 */
void CGame::Load(const std::wstring& filename)
{
    mButtonPressed = false;

    if (filename == L"level0.xml")
    {
        mLevel = L"Level 0";
        mLevelBalloons = 30;
    }
    else if (filename == L"level1.xml")
    {
        mLevel = L"Level 1";
        mLevelBalloons = 30;
    }
    else if (filename == L"level2.xml")
    {
        mLevel = L"Level 2";
        mLevelBalloons = 30;
    }
    else if (filename == L"level3.xml")
    {
        mLevel = L"Level 3";
        mLevelBalloons = 40;
    }

    // Open the document with the xml loader class
    CXmlLoader xmlLoader(this);
    xmlLoader.Load(filename);

    // Once we know it is open, clear the existing items
    Clear();

    // Set the mItems to the new ones from the file
    mItems = xmlLoader.GetItems();


    InitializeStart();

    // link all of the roads together
    CRoadLinker linker;
    Accept(&linker);
    linker.LinkRoads();

}

/**
 * Obtain information of the item clicked on.
 *
 * \param x An int of the x location
 * \param y an int of the y location
 * \return share_ptr of the object located at the location
 */
std::shared_ptr<CItem> CGame::HitTest(int x, int y)
{
    for (auto item : mItems)
    {
        if (item->HitTest((x - mXOffset) / mScale, (y - mYOffset) / mScale))
        {
            CGrabVisitor visitor;
            item->Accept(&visitor);
            if (visitor.IsTower())
            {
                return item;
            }
        }
    }
    return  nullptr;
}

/**
 * Clear the aquarium data.
 *
 * Deletes all known items in the aquarium.
 */
void CGame::Clear()
{
    mItems.clear();
}

/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CGame::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }

    if (mMenu != nullptr)
    {
        mMenu->Update(elapsed);
    }

    // apply appropriate damage to the balloons
    CDamageVisitor damager;
    Accept(&damager);
    damager.DealDamage();

    // incriment score for the popped ballons
    mScore += damager.GetScoreChange();

    // remove popped balloons and ballons that have made it through the level
    CItemRemover remover;
    Accept(&remover);
    Remove(remover.GetRemovedItems());

    // incriment score based off of how the balloons were removed
	mScore += remover.GetScoreChange();

    // update the visibility of the balloons
    CVisibilityUpdater updater;
    Accept(&updater);
    updater.UpdateVisibility();

    CLevelProgressor progressor;
    Accept(&progressor);
    if (mButtonPressed)
    {
        if (progressor.GetProgress()) 
        {
            ProgressLevel();
        }
    }

}

void CGame::ProgressLevel()
{
    if (mLevel == L"Level 0")
    {
        Load(L"level1.xml");
    }
    else if (mLevel == L"Level 1")
    {
        Load(L"level2.xml");
    }
    else if (mLevel == L"Level 2")
    {
        Load(L"level3.xml");
    }
    else if (mLevel == L"Level 3")
    {
        Load(L"level3.xml");
    }
}

/** Accept a visitor for the collection
 * \param visitor The visitor for the collection
 */
void CGame::Accept(CItemVisitor* visitor)
{
    for (auto tile : mItems)
    {
        tile->Accept(visitor);
    }
}


/**
 * Sets all balloon and road items at the beginning of the level to start the game
 */
void CGame::InitializeStart()
{
    // create a menu for the game
    mMenu = make_shared<CGameMenu>(this);
    // the starting y position of all starting roads
    int yStart = mStartY * mTileLength + mTileLength / 2;
    // the first starting x position
    int xStart = (mStartX - 1) * mTileLength + mTileLength / 2;

    // create a vector of roads that will be added to the game
    vector<CItemRoad* > startRoads;

    // the number of roads needed to hold mLevelBalloons balloons at mBalloonSpacing
    // int(30 * mBaloonSpacing / tileLength)) + 1
    // starting the balloons 2 full tile back so + 3
    int numBufferRoads = 2;
    int numRoads = (mLevelBalloons * mBalloonSpacing / mTileLength) + 1 + numBufferRoads;

    // the x position to add the road at
    int roadXPos = xStart;
    // add numRoads roads to the start road vector in the right position
    for (int i = 0; i < numRoads; ++i)
    {
        // create the road
        shared_ptr<CItemRoad> road = make_shared<CItemRoad>(this);
        // make it an EW road
        road->SetRoadDirection(L"EW");
        // set it in the right location
        road->SetLocation(roadXPos, yStart);
        // add the road to the game and the startRoads
        Add(road);
        // add the road as a raw ptr to the startRoads vector
        startRoads.push_back(&(*road));
        // update the x position for the next balloon added
        roadXPos -= mTileLength;
    }

    // the initial x position to add the balloon at
    int balloonXPos = xStart - 2 * mTileLength;
    // path to the image to use for all red balloons
    

    // add mLevelBalloons to the level 
    for (int i = 0; i < mLevelBalloons; ++i)
    {
        // find what road the balloon starts on/ the index of the startRoad
        int roadNumber = -1 * balloonXPos / mTileLength;

        auto road = startRoads[roadNumber];

        //initial heading of the ballon
        wstring heading = L"E";

        // create the balloon
        shared_ptr<CBalloonRed> balloon = make_shared<CBalloonRed>(this, road, heading);
        // set the image of the balloon
        balloon->SetImagePtr(GetImage(L"red-balloon.png"));
        // set the location of the balloon
        balloon->SetLocation(balloonXPos, yStart);
        // add the balloon
        Add(balloon);
        // update the next balloons location
        balloonXPos -= mBalloonSpacing;
    }
    
    // if it is level 3, add a boss balloon to the level
    if (mLevel == L"Level 2")
    {
        //initial heading of the ballon
        wstring heading = L"E";

        // boss is always on the first road
        auto road = startRoads[0];

        // create the balloon
        shared_ptr<CBalloonBoss> balloon = make_shared<CBalloonBoss>(this, road, heading);

        // set the image of the balloon
        balloon->SetImagePtr(GetImage(L"boss-balloon.png"));

        // set the location of the balloon
        balloon->SetLocation(xStart, yStart);

        // set the health of the balloon
        balloon->SetHealth(15);
        balloon->SetSpeed(80);

        balloon->InitializeCariers();
        // add it to the game
        Add(balloon);
    }

    mButtonPressed = false;

}



/**
 * Called when there is a left mouse button press
 * \param nFlags Flags associated with the mouse button press
 * \param point Where the button was pressed
*/
void CGame::OnLButtonDown(UINT nFlags, CPoint point)
{
    // Only use hit test if button has not yet been pressed.
    if (mButtonPressed == false)
    {
        mGrabbedItem = HitTest(point.x, point.y);
        // see if the item grabbed was in the game
        if (mGrabbedItem != nullptr)
        {
            // do something with the grabbed item
        }
        // see if the grabbed item was in the menu
        else if(point.x >= (GetGameWidth()* mScale) + mXOffset)
        {
            mGrabbedItem = mMenu->MenuHitTest((point.x - mXOffset) / mScale,
                (point.y - mYOffset) / mScale);
            if (mGrabbedItem != nullptr)
            {
                mGrabbedItem->SetLocation((point.x - mXOffset) / mScale,
                    (point.y - mYOffset) / mScale);
                Add(mGrabbedItem);
                
            }
        }
    }
}


/**
 * Called when the mouse is moved
 * \param nFlags Flags associated with the mouse movement
 * \param point Where the button was pressed
 */
void CGame::OnMouseMove(UINT nFlags, CPoint point)
{
    // See if an item is currently being moved by the mouse
    if (mGrabbedItem != nullptr)
    {
        // If an item is being moved, we only continue to 
        // move it while the left button is down.
        if (nFlags & MK_LBUTTON)
        {
            mGrabbedItem->SetLocation((point.x - mXOffset) / mScale,
                (point.y - mYOffset) / mScale);
        }
        else
        {
            // When the left button is released, we release the
            // item.
            mGrabbedItem = nullptr;
        }
    }
}


/**
 * Called when the left mouse button is released
 * \param nFlags Flags associated with the mouse button release
 * \param point Where the button was pressed
 */
void CGame::OnLButtonUp(UINT nFlags, CPoint point)
{
    OnMouseMove(nFlags, point);
}


/**
* gets a pointer to the image so imaegs only get loaded once
 * 
 * \param filename the image to get
 * \returns a pointer to the loaded image
 */
shared_ptr<Bitmap> CGame::GetImage(wstring filename)
{
    return mImages.GetImage(filename);
}