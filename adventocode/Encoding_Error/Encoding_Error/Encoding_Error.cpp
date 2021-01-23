// Encoding_Error.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#define WINDOW 25
int main()
{
    std::string data;
    std::vector<long long> encoded_data;
    while (std::getline(std::cin, data)) {
        encoded_data.push_back(std::stoll(data));
    }

    for (int i = WINDOW; i < encoded_data.size(); i++) {
        bool corrupt_number = true;
        for (int j = i - WINDOW; j < i; j++) {
            for (int k = i - WINDOW; k < i; k++) {
                if ( encoded_data[j] + encoded_data[k] == encoded_data[i]) {
                    corrupt_number = false;
                }
            }
        }
        if (corrupt_number) {
            std::cout << encoded_data[i] << "\n";
            return 0;
        }
    }

}

