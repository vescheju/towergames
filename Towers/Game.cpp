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
#include "TileLocker.h"
#include "ItemRemover.h"
#include "GrabVisitor.h"
#include "BalloonBoss.h"
#include "ItemOpen.h"
#include "VisibilityUpdater.h"
#include "LevelProgressor.h"

#include <windows.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include <algorithm>
#pragma comment(lib, "Winmm.lib")

using namespace std;
using namespace xmlnode;
using namespace Gdiplus;


/// Score positioning X variable
const int ScoreX = 1124;

/// Score positioning Y variable
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
            if (&(*removeItem) == &(*(mItems[i])) && &(*mItems[i]) != &(*mGrabbedItem))
            {
                mItems.erase(mItems.begin()+i);
                break;
            }
        }
    }
}


/**
* Moves all towers to the front of the screen.
* For use after pressing go button
* 
* \param towers Vector of towers to move to the front of the screen
*/
void CGame::TowersToFrontOfScreen(std::vector<CTower*> towers)
{
    // Iterate through items in towers
    for (auto tower : towers)
    {
        // Iterate through items in mItems
        for (auto item : mItems)
        {
            // If they are at the same address in memory
            if (&(*item) == &(*tower)) 
            {
                // move to the front of the screen
                ToFrontOfScreen(item);
            }
        }
    }
}


/*
* Moves object to front of screen.
* 
* \param item Shared pointer to item moved to front of screen
*/
void CGame::ToFrontOfScreen(std::shared_ptr<CItem> item)
{
    // locate item in mItems
    auto locate = find(mItems.begin(), mItems.end(), item);
    if (locate != mItems.end())
    {
        // erase the item and push it to the back of mItems
        mItems.erase(locate);
        mItems.push_back(item);
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

    // draw the jump scare for 2 seconds
    if (mScare && mScareTime < 3)
    {

        std::shared_ptr<Gdiplus::Bitmap> scareImage = GetImage(L"scare.png");

        double wid = scareImage->GetWidth();
        double hit = scareImage->GetHeight();
        graphics->DrawImage(scareImage.get(),
            float(512 - wid / 2), float(512 - hit / 2),
            (float)scareImage->GetWidth(), (float)scareImage->GetHeight());
    }
    else if(mScare && mScareTime > 3)
    {
        // kill jump scare noise
        mciSendString(L"stop scare.mp3", NULL, 0, NULL);
        mciSendString(L"close scare.mp3", NULL, 0, NULL);

        // resume the monster mash
        mciSendString(L"resume music.mp3", NULL, 0, NULL);

        mScare = false;
        mScareTime = 0;
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
    mPumpkin = false;
	mciSendString(L"open \"audio\\Monster Mash.mp3\" type mpegvideo alias music.mp3", NULL, 0, NULL);
    if (filename == L"level0.xml")
    {
        SetGameLevel(0);
        mLevel = L"Level 0";
        mLevelBalloons = 30;
		mciSendString(L"stop music.mp3", NULL, 0, NULL);
    }
    else if (filename == L"level1.xml")
    {
        SetGameLevel(1);
        mLevel = L"Level 1";
        mLevelBalloons = 30;
		mciSendString(L"stop music.mp3", NULL, 0, NULL);
    }
    else if (filename == L"level2.xml")
    {
        SetGameLevel(2);
        mLevel = L"Level 2";
        mLevelBalloons = 30;
		mciSendString(L"stop music.mp3", NULL, 0, NULL);
    }
    else if (filename == L"level3.xml")
    {
        SetGameLevel(3);
        mLevel = L"Level 3";
        mLevelBalloons = 40;
		mciSendString(L"play music.mp3 repeat", NULL, 0, NULL);
    }

    // Open the document with the xml loader class
    CXmlLoader xmlLoader(this);
    xmlLoader.Load(filename);

    // Once we know it is open, clear the existing items
    Clear();

    // Set the mItems to the new ones from the file
    mItems = xmlLoader.GetItems();

    // If we're on level 3, include pumpkin bomb
    if (mGameLevel == 3)
    {
        InitializeStart(true);
    }
    // Otherwise, do not
    else
    {
        InitializeStart(false);
    }

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
 * \return share_ptr of the tower located at the location
 */
std::shared_ptr<CTower> CGame::HitTest(int x, int y)
{
    CGrabVisitor visitor;
    Accept(&visitor);
    for (auto tower : visitor.GetTowers())
    {
        // if item is hit
        if (tower->HitTest((x - mXOffset) / mScale, (y - mYOffset) / mScale))
        {
            // find tower in mItems
            for (auto item : mItems)
            {
                // If they refer to the same memory
                if (&(*item) == &(*tower))
                {
                    // return downcast of item to CTower
                    return std::static_pointer_cast<CTower>(item);
                }
            }
        }
    }
    //otherwise return nullptr
    return nullptr;
}

/**
 * Clear the game data.
 *
 * Deletes all known items in mItems.
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

    // add time to the scaretime counter
    if (mScare)
    {
        mScareTime += elapsed;
    }

    // apply appropriate damage to the balloons
    CDamageVisitor damager;
    Accept(&damager);
    damager.DealDamage();

    // incriment score for the popped ballons
    mScore += damager.GetScoreChange();

    // remove popped balloons and balloons that have made it through the level
    CItemRemover remover;
    Accept(&remover);
    Remove(remover.GetRemovedItems());

    // incriment score based off of how the balloons were removed
	mScore += remover.GetScoreChange();

    // if pumpkin is removed, set mPumpkin to false
    if (remover.PumpkinCollected())
    {
        mPumpkin = false;
    }

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
            mDisplayEnd = true;
            if (mMenu->GetEndGame() == true)
            {
                mDisplayEnd = false;
                ProgressLevel();
            }
            
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
void CGame::InitializeStart(bool pumpkin)
{
    // create a menu for the game
    mMenu = make_shared<CGameMenu>(this);
    if (pumpkin)
    {
        mMenu->AddPumpkin();
    }
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
        if (mLevel == L"Level 3")
        {
            if (i % 4 == 0)
            {
                balloon->SetImagePtr(GetImage(L"dracula.png"));
            }
            else if (i % 3 == 0)
            {
                balloon->SetImagePtr(GetImage(L"werewolf.png"));
            }
            else if (i % 2 == 0)
            {
                balloon->SetImagePtr(GetImage(L"mummy.png"));
            }
            else
            {
                balloon->SetImagePtr(GetImage(L"frankenstein.png"));
            }
        }
        else
        {
            balloon->SetImagePtr(GetImage(L"red-balloon.png"));
        }
        
        // set the location of the balloon
        balloon->SetLocation(balloonXPos, yStart);
        // add the balloon
        Add(balloon);
        // update the next balloons location
        balloonXPos -= mBalloonSpacing;
    }
    
    // if it is level 3, add a boss balloon to the level
    if (mLevel == L"Level 3")
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
            // Tile and Tower no longer relate, so sever ties
            mGrabbedItem->GetTile()->SetTower(nullptr);
            mGrabbedItem->SetTile(nullptr);

            // Set grabbed attribute to true, move tower to the front of the screen
            mGrabbedItem->SetGrabbed(true);
            ToFrontOfScreen(mGrabbedItem);
        }

        // see if the grabbed item was in the menu
        else if(point.x >= (GetGameWidth()* mScale) + mXOffset)
        {
            // create new instance of tower if tower icon is clicked on in menu
            mGrabbedItem = mMenu->MenuHitTest((point.x - mXOffset) / mScale,
                (point.y - mYOffset) / mScale);
            // if new tower was created
            if (mGrabbedItem != nullptr)
            {
                // set its location at mouse point
                mGrabbedItem->SetLocation((point.x - mXOffset) / mScale,
                    (point.y - mYOffset) / mScale);

                // Set grabbed attribute to true, add to mItems
                mGrabbedItem->SetGrabbed(true);
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
        // When the left button is released
        else
        {
            // Lock tower to an open tile
            CTileLocker visitor;
            Accept(&visitor);
            mGrabbedItem->Accept(&visitor);
            visitor.LockTower();
            
            // Set tower grabbed attribute to false and 
            // set mGrabbedItem to nullptr
            mGrabbedItem->SetGrabbed(false);
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