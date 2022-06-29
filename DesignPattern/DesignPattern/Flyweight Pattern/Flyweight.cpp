#include "Flyweight.h"
#include <format>
#include <iostream>

namespace Flyweight
{
	std::string Meta::bodyname[] = { "EH_BA","EH_BB","EH_BC" };
	std::string Meta::lensname[] = { "EH_L1","EH_L2","EH_L3" };
	std::string Meta::lightname[] = { "맑음", "흐림","램프" };
	int Meta::scnt = 0;

	BodyType Meta::GetBody()
	{
		return body;
	}

	LensType Meta::GetLens()
	{
		return lens;
	}

	LightType Meta::GetLight()
	{
		return light;
	}

	int Meta::GetSeq()
	{
		return seq;
	}

	Meta::Meta(BodyType body, LensType lens, LightType light)
	: body(body)
	, lens(lens)
	, light(light)
	{
		scnt++;
		seq = scnt;
	}

	bool Meta::IsEqual(BodyType body, LensType lens, LightType light)
	{
		return (this->body == body) && (this->lens == lens) && (this->light == light);
	}

	void Meta::View()
	{
		std::cout << std::format("일련번호: {}", seq) << std::endl;
		std::cout << std::format("Body: {}", bodyname[(int)body]) << std::endl;
		std::cout << std::format("Lens: {}", lensname[(int)lens]) << std::endl;
		std::cout << std::format("Light: {}", lightname[(int)light]) << std::endl;
	}

	MetaPool& MetaPool::GetInstance()
	{
		static MetaPool* instance = new MetaPool();
		return *instance;
	}

	Meta* MetaPool::MakeMeta(BodyType body, LensType lens, LightType light)
	{
		if (metas.find(body) != metas.end() && metas[body].find(lens) != metas[body].end()
			&& metas[body][lens].find(light) != metas[body][lens].end())
		{
			return metas[body][lens][light];
		}

		Meta* meta = new Meta(body, lens, light);
		metas[body][lens][light] = meta;
		return meta;
	}

	PictureFile::PictureFile(std::string name, BodyType body, LensType lens, LightType light)
	: name(name)
	, meta(MetaPool::GetInstance().MakeMeta(body,lens,light))
	{
	}

	void PictureFile::View()
	{
		if (meta != NULL)
		{
			std::cout << std::format("사진 이름: {}", name) << std::endl;
			meta->View();
		}
	}

	void FlyweightPattern::Run()
	{
		BodyType body_type = BodyType::EH_BA;
		LensType lens_type = LensType::EH_L1;
		LightType light_type = LightType::LT_CLEAR;

		PictureFile* pf0 = new PictureFile("사진0", body_type, lens_type, light_type);
		PictureFile* pf1 = new PictureFile("사진0", body_type, lens_type, light_type);

		pf0->View();
		pf1->View();
	}
};
