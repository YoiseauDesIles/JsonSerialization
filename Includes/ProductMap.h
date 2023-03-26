//
// Created by johan on 26/03/2023.
//

#ifndef GRAPH_PRODUCTMAP_H
#define GRAPH_PRODUCTMAP_H


#include "JSONBase.h"
#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"


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
        void Colour(std::string colour) { this->_colour = colour; };
        std::string Colour() const { return _colour; }

        void printGraph() const;

    private:
        std::string _colour;
        std::map<std::string, std::list<std::string>> _graph;
    };
}


#endif //GRAPH_PRODUCTMAP_H
