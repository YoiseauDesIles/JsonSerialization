#include <string>
#include "../Includes/Product2.h"

namespace JSONModels
{
	Product2::Product2() : _sauce(0)
	{}

	Product2::~Product2()
	{}
	
	
	
	bool Product2::Deserialize(const rapidjson::Value & obj)
	{
		Sauce(obj["sauce"].GetInt());
		Color(obj["color"].GetString());

		return true;
	}

	bool Product2::Serialize(rapidjson::Writer<rapidjson::StringBuffer> * writer) const
	{
		writer->StartObject();

			writer->String("sauce");
			writer->Int(_sauce);

			writer->String("color");
			writer->String(_color.c_str());

		writer->EndObject();

		return true;
	}	
}