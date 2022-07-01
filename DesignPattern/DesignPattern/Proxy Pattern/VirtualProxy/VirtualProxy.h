#pragma once

#include <string>

namespace VirtualProxy
{
	struct Bitmap
	{
	public:
		Bitmap(const std::string filename);
		void draw();

	private:
		std::string file;
	};

	struct Image
	{
	public:
		Image(const std::string& filename);
		~Image();
		void draw();

	private:
		std::string filename;
		Bitmap* bitmap;
	};
}
