//
//  main.cpp
//  Meet in the Middle
//
//  Created by Zachary Nesvacil on 11/10/24.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return 1;
        }
    string file_store, number;
    vector<int> data;
    
    
    getline(file, file_store);
    stringstream s(file_store);
    while (getline(s, number, ',')) {
        data.push_back(stoi(number));
    }
    
    if (data.size() % 2 == 1) {
        int middle = (static_cast<int>(data.size()) / 2);
        cout << "\nYour median is: " << data[middle] <<endl;
    }
    
    else if (data.size() % 2 == 0) {
        int middle_2 = (static_cast<int>(data.size()) / 2);
        int middle_1 = middle_2 - 1;
        double middle = (static_cast<double>(data[middle_2]) + static_cast<double>(data[middle_1])) / 2;
        
        cout << "\nYour median is: " << middle << endl;
        
    }
    
    else {
        cout << "Something went wrong!" << endl;
    }
    
    return 0;
}
