#include <string>
#include "../Includes/Product2.h"

namespace JSONModels
{
	ProductMap::ProductMap() 
	{}

	ProductMap::~ProductMap()
	{}
	
	
	
	bool ProductMap::Deserialize(const rapidjson::Value & obj)
	{
		// Graph(obj["graph"].GetInt());
		Color(obj["color"].GetString());

		return true;
	}

	bool ProductMap::Serialize(rapidjson::Writer<rapidjson::StringBuffer> * writer) const
	{
		writer->StartArray();


		return true;
	}	
}