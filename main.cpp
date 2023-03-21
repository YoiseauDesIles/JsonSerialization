#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "Includes/Product.h"
#include "Includes/Product2.h"

#include <fstream>
#include <string>
#include <map>
#include <list>


int jsonReaderFromFile();
void testDeserialization();
void testSerialization();
void testSerializationFromObject();
void deserializationMap();

int main()
{
    std::cout << "test";
    deserializationMap();
    // testDeserialization();
    // testSerialization();    
    // testSerializationFromObject();
    // std::cout << "\n" << jsonReaderFromFile() << "\n";
}



void jsonParserWithBuffer()
{
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    rapidjson::Document d;
    d.Parse(json);

    rapidjson::Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);

    std::cout << "jsonParserWithBuffer : \n" << buffer.GetString() << "\n";
}

int jsonReaderFromFile()
{
    //open the file
    std::FILE * file = fopen("../ressources/details.json", "rb");

    if (!file) {
        std::cerr << "Error: unable to open file"
                  << std::endl;
        return 1;
    }

    //Read the file into a buffer
    char readBuffer[65536];
    rapidjson::FileReadStream is(file, readBuffer, sizeof(readBuffer));

    //Parse the Json documentument
    rapidjson::Document document;
    document.ParseStream(is);

    // Check if the documentument is valid
    if (document.HasParseError()) {
        std::cerr << "Error: failed to parse JSON documentument"
                  << std::endl;
        fclose(file);
        return 1;
    }
    

    //close the file
    fclose(file);

// Get the "name" member
    if (document.HasMember("name") && document["name"].IsString()) {
        std::string name = document["name"].GetString();
        std::cout << "Name: " << name << std::endl;
    }
  
    // Get the "age" member
    if (document.HasMember("age") && document["age"].IsInt()) {
        int age = document["age"].GetInt();
        std::cout << "Age: " << age << std::endl;
    }
  
    // Get the "city" member
    if (document.HasMember("city") && document["city"].IsString()) {
        std::string city = document["city"].GetString();
        std::cout << "City: " << city << std::endl;
    }
  
    // Get the "skills" array
    if (document.HasMember("skills")
        && document["skills"].IsArray()) {
        const rapidjson::Value& skills = document["skills"];
        std::cout << "Skills: ";
        for (rapidjson::SizeType i = 0; i < skills.Size();
             i++) {
            if (skills[i].IsString()) {
                std::string skill = skills[i].GetString();
                std::cout << skill << " ";
            }
        }
        std::cout << std::endl;
    }
  

    return 0;

}

void testDeserialization(){
    //Load Json from file
    JSONModels::Product product;
    product.DeserializeFromFile("../ressources/details.json");

    std::cout << "Name : " << product.Name() << ",\r\n Sales : " << product.Sales() << "\n\n";    
}


void testSerialization()
{
    JSONModels::Product product;
    product.DeserializeFromFile("../ressources/details.json");            
    product.Sales(product.Sales() + 100.0f); // increase the sales by 100
    product.SerializeToFile("../ressources/DataSampleNew.json");
}


void testSerializationFromObject()
{
    // JSONModels::Product2 product;
    // product.Color("couleur sauce");
    // product.Sauce(18);

    // product.SerializeToFile("../ressources/sauce.json");

}


void deserializationMap(){
        std::ifstream file("../ressources/data.json");
    std::string json_str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    using namespace rapidjson;

    Document doc;
    doc.Parse(json_str.c_str());

    std::map<std::string, std::list<std::string>> my_map;

    if(doc.HasMember("my_map")) {
        const Value& map_value = doc["my_map"];

        if(map_value.IsObject()) {
            for (Value::ConstMemberIterator itr = map_value.MemberBegin(); itr != map_value.MemberEnd(); ++itr) {
                if(itr->value.IsArray()) {
                    std::list<std::string> value_list;
                    for (SizeType i = 0; i < itr->value.Size(); i++) {
                        if(itr->value[i].IsString()) {
                            value_list.push_back(itr->value[i].GetString());
                        }
                    }
                    my_map[itr->name.GetString()] = value_list;
                }
            }
        }
    }

// Affichage de la map pour vérification
for (auto const& pair : my_map) {
    std::cout << pair.first << " : ";
    for(auto const& value : pair.second) {
        std::cout << value << ", ";
    }
    std::cout << std::endl;
}

}