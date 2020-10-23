/**
 * \file ImageContainer.cpp
 *
 * \author Ian Masterson
 */

#include "pch.h"
#include "ImageContainer.h"

using namespace std;
using namespace Gdiplus;


/// the folder that contains the images
const wstring path = L"images/";

/**
 * gets the appropriate image from the filename
 * \param filename 
 * \returns 
 */
shared_ptr<Bitmap> CImageContainer::GetImage(wstring filename)
{
	auto iter = mImages.find(filename);
	if (iter == mImages.end())
	{
		shared_ptr<Bitmap> itemImage = shared_ptr<Bitmap>(Bitmap::FromFile((path + filename).c_str()));
        // make sure getting the image was successful
        if (itemImage->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
        }

        mImages[filename] = itemImage;
        return itemImage;
	}
    else
    {
        return mImages[filename];
    }
}


/**
 * intializes the images in the level from another map
 * \param images the map of images to store
 */
void CImageContainer::SetImages(map < wstring, shared_ptr<Bitmap>> images)
{
    mImages = images;
}