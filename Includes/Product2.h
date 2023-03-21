#pragma once

#include "JSONBase.h"
#include <list>
#include <map>
#include <algorithm>

namespace JSONModels
{
	class ProductMap : public JSONBase
	{

	public:
		ProductMap();		
		virtual ~ProductMap();			

		virtual bool Deserialize(const rapidjson::Value& obj);
		virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;

		// Getters/Setters.
		const std::string& Color() const { return _color; }
		void Color(const std::string& color) { _color = color; }

		// const std::list<std::string> & Graph() const { return _graph; }
		// void Graph(const std::list<std::string>& graph) const {

		// 	    std::copy(graph.begin(), graph.end(), std::back_inserter(_graph));
			
		//  }
	
    private:
		std::string _color;
        std::list<std::string> _graph;
	};	
}