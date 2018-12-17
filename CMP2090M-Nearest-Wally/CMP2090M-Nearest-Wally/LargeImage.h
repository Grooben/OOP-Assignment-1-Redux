#pragma once
#include "BaseImage.h"
class LargeImage :
	public BaseImage
{
public:
	LargeImage();
	~LargeImage();

	// Inherit constructors from base class
	BaseImage::BaseImage;
};

