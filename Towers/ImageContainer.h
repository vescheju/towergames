/**
 * \file ImageContainer.h
 *
 * \author Ian Masterson
 *
 * Class stores the images that are needed for displaying the game
 */

#pragma once
#include<map>
#include <memory>
#include <string>


/**
 * Stores the images in the game
 */
class CImageContainer
{
private:
	/// a map from the filename to the image ptr
	std::map<std::wstring, std::shared_ptr<Gdiplus::Bitmap> > mImages;

public:
	std::shared_ptr<Gdiplus::Bitmap> GetImage(std::wstring filename);

	void SetImages(std::map<std::wstring, std::shared_ptr<Gdiplus::Bitmap> > images);
};

