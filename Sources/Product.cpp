#include "../Includes/Product.h"

bool Product::Deserialize(const rapidjson::Value &obj)
{
    Id(obj["id"].GetInt());
    Name(obj["name"].GetString());
    Category(obj["category"].GetString());
    Sales(obj["sales"].GetFloat());

    return true;
}

bool Product::Serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const
{
    writer->StartObject();

    writer->String("id"); // create Id property
    writer->Int(_id);     // write the Id value from the object instance

    writer->String("name");
    writer->String(_name.c_str());

    writer->String("category");
    writer->String(_category.c_str());

    writer->String("sales");
    writer->Double(_sales);

  writer->EndObject();

  return true;
}
