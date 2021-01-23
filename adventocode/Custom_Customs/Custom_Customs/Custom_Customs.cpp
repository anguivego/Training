// Custom_Customs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <sstream>
#include <iostream>
#include <map>

int main()
{
    std::string tmp;
    std::string group_data;
    int total_counts = 0;
    int votes = 0;
    while (std::getline(std::cin, tmp))
    {
        if (tmp.size() != 0) {
            group_data += tmp;
            votes++;
        }
        else
        {

            std::map<char, int> letters;
            for (char i : group_data) {
                if (letters.count(i) == 0)
                    letters[i] = 1;
                else
                    letters[i] += 1;
            }

            int group_counts = 0;
            for (std::pair<char, int> i : letters) {
                if (i.second == votes)
                    group_counts++;
            }

            if(group_counts > 0)
                total_counts += group_counts;

            std::cout <<group_counts <<" - " << letters.size() << ":" << group_data << ": "<< group_counts << "\n";
            group_data.clear();
            votes = 0;
        }
    }
    std::cout << total_counts << "\n";
}

