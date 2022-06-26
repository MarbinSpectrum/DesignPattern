#pragma once

#include <string>
#include <unordered_map>
#include <iostream>

namespace FacadePattern
{
	class Picture
	{
		int tone;
		int brightness;
		int saturation;
		std::string name;
	public:
		std::string GetName();
		Picture(const std::string& name, const int tone, const int brightness, const int saturation);
		void Change(const int tone, const int brightness, const int saturation);
		bool IsEqual(const std::string& name);
		void View();
	};

	class Compensator
	{
	public:
		void Change(Picture* picture, const int tone, const int brightness, const int saturation);
	};

	class PictureManager
	{
		typedef std::unordered_map<std::string, Picture*> PictureMap;
		PictureMap pictrueMap;
	public:
		bool Exist(const std::string& name);
		bool AddPicture(Picture* picture);
		Picture* FindPicture(const std::string& name);
		void View();
	};

	class SmartManager
	{
		std::unique_ptr<Compensator> compensator;
		std::unique_ptr<PictureManager> picManager;

	public:
		SmartManager();

		bool Exist(const std::string& name);
		bool AddPicture(Picture* picture);
		Picture* FindPicture(const std::string& name);
		bool Change(const std::string& name, const int tone, const int brightness, const int saturation);
		void View();
	};

	struct FacadePattern
	{
		static void Run();
	};
};