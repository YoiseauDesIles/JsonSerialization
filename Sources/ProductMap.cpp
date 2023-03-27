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
        const rapidjson::Value& map_value = obj["my_map"];
        Graph(map_value);

        Colour(obj["colour"].GetString());

        return true;
    }

    bool ProductMap::Serialize(rapidjson::Writer<rapidjson::StringBuffer> * writer) const
    {

        writer->StartObject();

        for (const auto& pair : _graph)
        {
            writer->Key(pair.first.c_str());
            writer->StartArray();
            for (const auto& value : pair.second)
            {
                writer->String(value.c_str());
            }
            writer->EndArray();
        }

        writer->String("colour");
        writer->String(_colour.c_str());

        writer->EndObject();

        return true;
    }



    void ProductMap::Graph(const rapidjson::Value &map_value) {

        if(map_value.IsObject()) {

            for (rapidjson::Value::ConstMemberIterator itr = map_value.MemberBegin(); itr != map_value.MemberEnd(); ++itr) {
                if(itr->value.IsArray()) {
                    std::list<std::string> value_list;
                    for (rapidjson::SizeType i = 0; i < itr->value.Size(); i++) {
                        if(itr->value[i].IsString()) {
                            value_list.push_back(itr->value[i].GetString());
                        }
                    }
                    _graph[itr->name.GetString()] = value_list;
                }

            }
        }
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