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
			//�׸��� �׸��� �׸� ������ �ε��ǵ��� �帧�� �����ߴ�.
			bitmap = new Bitmap(filename);
		}

		bitmap->draw();
	}
};
