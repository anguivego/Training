// Handy_Haversacks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <set>
bool DFS(std::map<std::string, std::vector<std::pair<std::string, int>>>  &G, std::string source, std::string dest) {
    std::set<std::string> visited_nodes;
    std::stack<std::tuple<std::string, int, int>> S;
    S.push(std::make_tuple(source, 1, 1));
    int total_of_bags = 0;
    int prev_level = 0;
    std::vector<int> n_bags;
    while (!S.empty()) {
        std::tuple<std::string,int, int> v = S.top();
        S.pop();

        prev_level = std::get<1>(v);
        //if (visited_nodes.count(std::get<0>(v)) == 0) {
            visited_nodes.insert(std::get<0>(v));
            std::cout << std::get<0>(v) << ": {" << std::get<1>(v) << "} ";
            int sum_of_childs = 0;
            for (auto u : G[std::get<0>(v)]) {
                /*if (u.first.compare(dest) == 0)
                    return true;*/
                std::cout << u.first << " : {" << std::get<1>(v) * u.second << "} ";
                S.push(std::make_tuple(u.first, std::get<1>(v) * u.second, u.second));
            }
            std::cout << "\n";
        //}
        if(std::get<0>(v).compare(source) != 0)
            n_bags.push_back(std::get<1>(v));
    }
    int sum = 0;
    for (int i : n_bags)
        sum += i;

    std::cout << source << ":" << dest << "="<< sum << "\n";
    return false;
}
int main()
{
    std::string tmp;
    std::string group_data;
    std::map<std::string, std::vector<std::pair<std::string, int>>> bags_G;
    while (std::getline(std::cin, tmp))
    {
        std::istringstream tokenStream(tmp);
        std::string token;
        std::string color_name, color_tone, bags, token_contains, n_bags;
        std::vector<std::pair<std::string, int>> can_contain;
        //bright white bags contain 1 shiny gold bag.
        tokenStream >> color_name >> color_tone >> bags >> token_contains >> n_bags;
        std::pair<std::string, int> a;
        if (n_bags.compare("no") != 0) {
            std::string contained_color, contained_color_tone, contained_n_bags;
            tokenStream >> contained_color >> contained_color_tone >> bags;
            if (n_bags.size() == 0)
                n_bags = "0";
            can_contain.push_back(std::make_pair(contained_color + "_" + contained_color_tone, std::stoi(n_bags)));

            while (std::getline(tokenStream, token, ',')) {
                std::istringstream containedColorStream(token);
                containedColorStream >> contained_n_bags >> contained_color >> contained_color_tone >> bags;
                can_contain.push_back(std::make_pair(contained_color + "_" + contained_color_tone, std::stoi(contained_n_bags)));
            }
        }
        bags_G[color_name + "_" + color_tone] = can_contain;
    }
    int paths = 0;
    /*
    for (auto i : bags_G) {
        if (DFS(bags_G, i.first, "shiny_gold"))
            paths++;
    }*/
    DFS(bags_G, "shiny_gold", "none");
    std::cout << paths << "\n";
}
