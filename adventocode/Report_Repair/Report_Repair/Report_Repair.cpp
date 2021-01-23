// Report_Repair.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*int main()
{
    int tmp = 0;
    vector<int> expences;
    while (cin >> tmp)
    {
        expences.push_back(tmp);
    }
    sort(expences.begin(), expences.end());
    for (int i : expences)
    {
        if (std::binary_search(expences.begin(), expences.end(), 2020 - i)) {
            cout << i << " + " << 2020 - i << endl;
        }
    }
}*/

int main()
{
    int tmp = 0;
    vector<int> expences;
    while (cin >> tmp)
    {
        expences.push_back(tmp);
    }
    sort(expences.begin(), expences.end());
    for (int i : expences)
    {
        for (int j : expences)
        {
            for (int k : expences)
            {
                if ((i + j + k == 2020))
                    cout << i << ", " << j << "," << k << endl;
            }
        }
    }
}
