#pragma once
#include "BaseImage.h"
class RefImage :
	public BaseImage
{
public:
	RefImage();
	~RefImage();

	// Inherit constructors from base class
	using BaseImage::BaseImage;
};

