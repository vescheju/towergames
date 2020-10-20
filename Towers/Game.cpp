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
#include "ButtonVisitor.h"

using namespace std;
using namespace xmlnode;
using namespace Gdiplus;

/// the folder that the levels exist in
const wstring levelFolder = L"levels/";

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

    // Ensure it is centered horizontally
    mXOffset = (float)((width - mWidth * mScale) / 2);

    // Ensure it is centered vertically
    mYOffset = (float)((height - mHeight * mScale) / 2);

    graphics->TranslateTransform(mXOffset, mYOffset);
    graphics->ScaleTransform(mScale, mScale);

    // draw the items
    for (auto item : mItems)
    {
        // only draw the item if it is with the dimensions of the level
        if ((item->GetX() >= 0 && item->GetX() <= mWidth) &&
            (item->GetY() >= 0 && item->GetY() <= double(mTileLength) * mLevelHeight))
        {
            item->Draw(graphics);
        }
        
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

    for (auto item : *this)
    {
        if (item->HitTest((x - mXOffset) / mScale, (y - mYOffset) / mScale))
        {
            return item;
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
    // will be fixed
    if (mButtonPressed)
    {
        for (auto item : mItems)
        {
            item->Update(elapsed);
        }
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
    const wstring filename = L"images/red-balloon.png";
    // pointer to the image for all red balloons
    shared_ptr<Gdiplus::Bitmap> itemImage = shared_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
    // make sure getting the image was successful
    if (itemImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += filename;
        AfxMessageBox(msg.c_str());
    }

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
        balloon->SetImagePtr(itemImage);
        // set the location of the balloon
        balloon->SetLocation(balloonXPos, yStart);
        // add it to the game
        Add(balloon);

        // update the next balloons location
        balloonXPos -= mBalloonSpacing;
    }

    std::shared_ptr<CGoButton> button(new CGoButton(this));
    button->SetLocation(ScoreX, ScoreY);
    Add(button);
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
        if (mGrabbedItem != nullptr)
        {
            CButtonVisitor buttonVisit;
            mGrabbedItem->Accept(&buttonVisit);

            mButtonPressed = buttonVisit.IsButton();

            mGrabbedItem = nullptr;
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
    
}


/**
 * Called when the left mouse button is released
 * \param nFlags Flags associated with the mouse button release
 * \param point Where the button was pressed
 */
void CGame::OnLButtonUp(UINT nFlags, CPoint point)
{
    
}

