// Passport_Processing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <regex>
int main()
{
    std::string tmp;
    std::string passport_data = "";
    int valid_passports = 0;
    //eye color : amb blu brn gry grn hzl oth
    std::map<std::string, int> eye_color = { {"amb", 1}, {"blu", 1},{"brn", 1},{"gry", 1},{"grn", 1},{"hzl", 1},{"oth", 1}};
/*byr (Birth Year)
iyr (Issue Year)
eyr (Expiration Year)
hgt (Height)
hcl (Hair Color)
ecl (Eye Color)
pid (Passport ID)
cid (Country ID)*/
    while (std::getline (std::cin,tmp))
    {
        if (tmp.size() != 0) {
            passport_data += ":" + tmp;
        }
        else{
            //std::cout << passport_data << "\n\n";
            std::replace(passport_data.begin(), passport_data.end(), ' ', ':');
            //std::cout << passport_data << "\n";

            std::istringstream tokenStream(passport_data);
            std::string token;
            std::map<std::string, std::string> mapOfMarks = { {"byr", ""}, {"iyr", ""}, {"eyr", ""}, {"hgt", ""}, {"hcl", ""}, {"ecl", ""}, {"pid", ""} , {"cid", ""}};
            int number_of_fields = 0;
            bool optional_cid = false;
            
            while (std::getline(tokenStream, token, ':'))
            {
                if (mapOfMarks.count(token)){
                    if (token.compare("cid") == 0)
                        optional_cid = true;

                    std::string key = token;
                    std::getline(tokenStream, token, ':');
                    mapOfMarks[key] = token;
                    number_of_fields++;
                }

            }
            bool valid = true;
            if (number_of_fields >= 8 || (number_of_fields >= 7 && !optional_cid)) {

                if (!(std::stoi(mapOfMarks["byr"]) >= 1920 && std::stoi(mapOfMarks["byr"]) <= 2002))
                    valid = false;
                if (!(std::stoi(mapOfMarks["iyr"]) >= 2010 && std::stoi(mapOfMarks["iyr"]) <= 2020))
                    valid = false;
                if (!(std::stoi(mapOfMarks["eyr"]) >= 2020 && std::stoi(mapOfMarks["eyr"]) <= 2030))
                    valid = false;
                if (mapOfMarks["pid"].size() != 9)
                    valid = false;

                if (eye_color.count(mapOfMarks["ecl"]) == 0)
                    valid = false;

                std::string units = mapOfMarks["hgt"].substr(mapOfMarks["hgt"].size() - 2, 2);

                if (units.compare("cm") == 0 || units.compare("in") == 0) {
                    int height = std::stoi(mapOfMarks["hgt"].substr(0, mapOfMarks["hgt"].size() - 2));
                    if (units.compare("cm") == 0 && !(height >= 150 && height <= 193))
                        valid = false;
                    if (units.compare("in") == 0 && !(height >= 59 && height <= 76))
                        valid = false;
                }
                else {
                    valid = false;
                }
                
                std::regex self_regex("#[a-fA-F0-9]{6}");
                if (!std::regex_search(mapOfMarks["hcl"], self_regex)) {
                    valid = false;
                }

                if(valid)
                    valid_passports++;
            }
            passport_data.clear();
        }
    }
    std::cout << valid_passports << "\n";
}

