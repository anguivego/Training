// Binary_Boarding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    
        std::string boarding_pass;
        int higest_value = 0;
        int final_row = 0;
        int final_col = 0;
        int airplane[128][8];
        while (std::cin >> boarding_pass) {
            std::cout << boarding_pass << "\n";
            {

                std::string rows = boarding_pass.substr(0, 7);
                int lower_half = 1, upper_half = 128;
                int mid = 0;
                final_row = 0;
                for (char i : rows) {
                    mid = (upper_half + lower_half) / 2;
                    if (i == 'F') {
                        upper_half = mid;
                        final_row = lower_half;
                    }
                    if (i == 'B') {
                        lower_half = mid + 1;
                        final_row = upper_half;
                    }
                }
            }
            {
                std::string cols = boarding_pass.substr(7, 3);
                std::cout << cols << std::endl;
                int lower_half = 0, upper_half = 7;
                int mid = 0;
                final_col = 0;
                for (char i : cols) {
                    mid = (upper_half + lower_half) / 2;
                    if (i == 'L') {
                        upper_half = mid;
                        final_col = lower_half;
                    }
                    if (i == 'R') {
                        lower_half = mid + 1;
                        final_col = upper_half;
                    }
                }
            }
            airplane[final_row - 1][final_col] = ((final_row - 1) * 8) + final_col;
            int id = ((final_row - 1) * 8) + final_col;
            if (higest_value < id)
                higest_value = id;
            std::cout << id << "  higest_id "<< higest_value << "\n";


        }

    for (int i = 0; i < 128; i++) {
        std::cout << i << ":";
        for (int j = 0; j < 8; j++) {
            std::cout << airplane[i][j] << " ";
        }
        std::cout << "\n";
    }
}

