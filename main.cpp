#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "Includes/JSONBase.h"
#include "Includes/Product.h"

int jsonReaderFromFile();
void testDeserialization();
void testSerialization();

int main()
{
    testDeserialization();
    testSerialization();    
    // std::cout << jsonReaderFromFile() << "\n";
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
    std::FILE * file = fopen("details.json", "rb");

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
    Product products;
    products.DeserializeFromFile("ressources/details.json");

    std::cout << "Name : " << products.Name() << ", Sales : " << products.Sales(); 

}


void testSerialization()
{
    Product product;
    product.DeserializeFromFile("../ressources/details.json");            
    product.Sales(product.Sales() + 100.0f); // increase the sales by 100
    product.SerializeToFile("../ressources/DataSampleNew.json");
}