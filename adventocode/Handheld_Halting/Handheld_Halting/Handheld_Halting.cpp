// Handheld_Halting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
std::pair<int, int> run_program( std::vector<std::tuple<std::string, int, int>> &program) {
    int acc = 0;
    int pc = 0, pc_previeus = 0;
    bool loop = false, finish = false, change_once = false;
    std::tuple<std::string, int, int> preview_command;
/*
    std::cout << "---------------------" << "\n";
    for (auto i : program) {
        std::cout << std::get<0>(i) << " " << std::get<1>(i) << " " << std::get<2>(i) << "\n";
    }
 */   
    while (!loop && pc < program.size()) {
        
        if (std::get<2>(program[pc]) != 0) {
            loop = true;
            change_once = true;
        }
        else {
            program[pc] = std::make_tuple(std::get<0>(program[pc]), std::get<1>(program[pc]), 1);

            if (std::get<0>(program[pc]).compare("acc") == 0) {
                acc += std::get<1>(program[pc]);
            }

            if (std::get<0>(program[pc]).compare("jmp") == 0) {
                pc += std::get<1>(program[pc]);
            }
            else {
                pc++;
            }

        }

    }
    return std::make_pair(acc, pc);
}
int main()
{
    std::string command, argument;
    std::vector<std::tuple<std::string, int, int>> program;
    while (std::cin >> command >> argument) {
        program.push_back(std::make_tuple(command, std::stoi(argument), 0)); // 0 = instruction not excecuted.
    }
    
    for (int i = 0; i < program.size(); i++) {
        std::vector<std::tuple<std::string, int, int>> alternative_program = program;
        if (std::get<0>(program[i]).compare("jmp") == 0) {
            alternative_program[i] = std::make_tuple("nop", 0, 0);
        }
        std::pair< int, int>  result = run_program(alternative_program);
        if( result.second == program.size())
            std::cout << result.first << " -> " << result.second <<"\n";

    }
}

