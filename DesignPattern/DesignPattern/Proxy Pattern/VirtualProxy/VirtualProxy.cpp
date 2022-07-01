#include "VirtualProxy.h"
#include <iostream>
#include "../../StudyUtility.h"

namespace VirtualProxy
{
	Bitmap::Bitmap(const std::string filename)
	: file(filename)
	{
	}

	void Bitmap::draw()
	{
		std::cout << file << std::endl;
	}
	Image::Image(const std::string& filename)
	: filename(filename)
	, bitmap(NULL)
	{
	}

	Image::~Image()
	{
		SAFE_DELETE(bitmap);
	}
	void Image::draw()
	{
		if (bitmap == NULL)
		{
			//그림을 그릴때 그림 파일이 로딩되도록 흐름을 제어했다.
			bitmap = new Bitmap(filename);
		}

		bitmap->draw();
	}
};
