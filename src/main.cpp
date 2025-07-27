#include <iostream>
#include "../include/json.hpp"
#include <fmt/core.h>
using json=nlohmann::json;
int main(){
    std::string json_str=R"(
        {
             "name":"Alice",
             "age":25,
             "skills":["C++","python"]
         }
    )";
    auto data=json::parse(json_str);
    std::string new_json_str=fmt::format(
        R"({{"name":"{}","skills":{},"gender":"Female"}})",
        data["name"].get<std::string>(),
        data["skills"].dump()
     );
     auto new_data=json::parse(new_json_str);
     std::cout<<"Original JSON:\n"<<data.dump(2)<<"\n\n";
     std::cout<<"Formatted JSON:\n"<<new_data.dump(2)<<std::endl;
     return 0;
}
