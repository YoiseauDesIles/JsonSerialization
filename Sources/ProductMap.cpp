//
// Created by johan on 26/03/2023.
//

#include <fstream>
#include "ProductMap.h"
namespace JSONModels
{
    ProductMap::ProductMap()
    {}

    ProductMap::~ProductMap()
    {}



    bool ProductMap::Deserialize(const rapidjson::Value & obj)
    {
        for (rapidjson::Value::ConstMemberIterator itr = obj.MemberBegin(); itr != obj.MemberEnd(); ++itr) {
            if(itr->value.IsArray()) {
                std::list<std::string> value_list;
                for (rapidjson::SizeType i = 0; i < itr->value.Size(); i++) {
                    if(itr->value[i].IsString()) {
                        value_list.push_back(itr->value[i].GetString());
                    }
                }
                _graph[itr->name.GetString()] = value_list;
            }
            else
            {
                Colour(obj["colour"].GetString());
            }
        }
        return true;
    }

    bool ProductMap::Serialize(rapidjson::Writer<rapidjson::StringBuffer> * writer) const
    {
        writer->StartArray();


        return true;
    }

    void ProductMap::printGraph() const {

        for (auto const& pair : _graph) {
            std::cout << pair.first << " : ";
            for(auto const& value : pair.second) {
                std::cout << value << ", ";
            }
            std::cout << std::endl;
        }
    }
}