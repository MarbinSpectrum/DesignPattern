#pragma once

#include <string>
#include <unordered_map>

namespace Flyweight
{
	enum class BodyType
	{
		EH_BA,
		EH_BB,
		EH_BC
	};

	enum class LensType
	{
		EH_L1,
		EH_L2,
		EH_L3
	};

	enum class LightType
	{
		LT_CLEAR,
		LT_CLOUDY,
		LT_LAMP
	};

	class Meta
	{
		static std::string bodyname[];
		static std::string lensname[];
		static std::string lightname[];
		static int scnt;

		BodyType body;
		LensType lens;
		LightType light;
		int seq;

	public:
		BodyType GetBody();
		LensType GetLens();
		LightType GetLight();
		int GetSeq();

		Meta(BodyType body, LensType lens, LightType light);

		bool IsEqual(BodyType body, LensType lens, LightType light);
		void View();
	};

	class MetaPool
	{
		typedef std::unordered_map<BodyType, std::unordered_map<LensType, 
		std::unordered_map<LightType, Meta*>>> META_LIST;

		META_LIST metas;

	public:
		static MetaPool& GetInstance();
		Meta* MakeMeta(BodyType body, LensType lens, LightType light);
	};

	class PictureFile
	{
		std::string name;
		Meta* meta;
	public:
		PictureFile(std::string name, BodyType body, LensType lens, LightType light);
		void View();
	};

	struct FlyweightPattern
	{
		static void Run();
	};
}
