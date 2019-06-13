#include <iostream>

#include <google/protobuf/text_format.h>

#include "testdata.pb.h"

int main(int argc, char const *argv[])
{
	TestEntity entity;
	entity.set_id(12);
	entity.set_description("Hello description!");

    std::string str;
    google::protobuf::TextFormat::PrintToString(entity, &str);
    printf("%s", str.c_str());

	std::cout << "Hello world!";
	return 0;
}