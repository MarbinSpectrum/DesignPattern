#include "FacadePattern.h";
#include <iostream>
#include <format>

namespace FacadePattern
{
	std::string Picture::GetName()
	{
		return name;
	}

	Picture::Picture(const std::string& name, const int tone, const int brightness, const int saturation)
		:name(name)
		, tone(tone)
		, brightness(brightness)
		, saturation(saturation)
	{
	}

	void Picture::Change(const int tone, const int brightness, const int saturation)
	{
		this->tone += tone;
		this->brightness += brightness;
		this->saturation += saturation;
	}

	bool Picture::IsEqual(const std::string& name)
	{
		return (this->name.compare(name) == 0);
	}

	void Picture::View()
	{
		std::cout << std::format("사진 이름 : {0}", name) << std::endl;
		std::cout << std::format("색조 : {0} 명도:{1} 채도 {2}", tone, brightness, saturation) << std::endl;
	}

	void Compensator::Change(Picture* picture, const int tone, const int brightness, const int saturation)
	{
		picture->Change(tone, brightness, saturation);
	}

	bool PictureManager::Exist(const std::string& name)
	{
		Picture* picture = FindPicture(name);
		return picture != NULL;
	}

	bool PictureManager::AddPicture(Picture* picture)
	{
		std::string pictureName = picture->GetName();
		if (Exist(pictureName))
		{
			return false;
		}
		pictrueMap.insert({ pictureName ,picture });
		return true;
	}

	Picture* PictureManager::FindPicture(const std::string& name)
	{
		PictureMap::iterator iter = pictrueMap.find(name);
		if (iter == pictrueMap.end())
			return NULL;
		Picture* picture = iter->second;
		return picture;
	}

	void PictureManager::View()
	{
		for (PictureMap::iterator iter = pictrueMap.begin(); iter != pictrueMap.end(); iter++)
		{
			Picture* picture = iter->second;
			picture->View();
		}
	}

	SmartManager::SmartManager()
	: compensator(std::make_unique<Compensator>())
	, picManager(std::make_unique<PictureManager>())
	{
	}

	bool SmartManager::Exist(const std::string& name)
	{
		return picManager->Exist(name);
	}

	bool SmartManager::AddPicture(Picture* picture)
	{
		return picManager->AddPicture(picture);
	}

	Picture* SmartManager::FindPicture(const std::string& name)
	{
		return picManager->FindPicture(name);
	}

	bool SmartManager::Change(const std::string& name, const int tone, const int brightness, const int saturation)
	{
		Picture* picture = FindPicture(name);
		if (picture == NULL)
		{
			return false;
		}
		compensator->Change(picture,tone, brightness, saturation);
		return true;
	}

	void SmartManager::View()
	{
		picManager->View();
	}

	void FacadePattern::Run()
	{
		Picture* picture0 = new Picture("언제나 휴일0", 100, 100, 100);
		Picture* picture1 = new Picture("언제나 휴일1", 100, 100, 100);

		SmartManager* smartManager = new SmartManager();
		smartManager->AddPicture(picture0);
		smartManager->AddPicture(picture1);
		smartManager->Change("언제나 휴일0", 20, 20, -50);
		smartManager->View();
	}
};
