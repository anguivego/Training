// Toboggan_Trajectory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
int main()
{
    std::vector<std::string> trees;
    std::string tmp;

    while (std::cin >> tmp)
    {
        trees.push_back(tmp);
    }
    int rotatory_index = 3, number_of_trees = 0;
    std::vector<std::pair<int, int>> steps = { {1, 1},
                                               {3, 1},
                                               {5, 1},
                                               {7, 1},
                                               {1, 2} };
    for (std::pair<int, int> step: steps) {
        rotatory_index = step.first;
        number_of_trees = 0;
        for (int i = step.second; i < trees.size(); i+=step.second) {
            //std::cout << trees[i][rotatory_index] << ":" << rotatory_index << ":" << trees[i] << "\n";
            if (trees[i][rotatory_index] == '#')
                number_of_trees++;
            rotatory_index = (rotatory_index + step.first) % trees[i].size();
        }
        std::cout << number_of_trees << "\n";
    }
}

