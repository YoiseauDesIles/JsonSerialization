#pragma once

#include "JSONBase.h"
#include <list>

namespace JSONModels
{
	class Product2 : public JSONBase
	{

	public:
		Product2();		
		virtual ~Product2();			

		virtual bool Deserialize(const rapidjson::Value& obj);
		virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;

		// Getters/Setters.
		const std::string& Color() const { return _color; }
		void Color(const std::string& color) { _color = color; }

		int Sauce() const { return _sauce; }
		void Sauce(int sauce) { _sauce = sauce; }		
	
    private:
		std::string _color;
		int _sauce;
        
	};	
}