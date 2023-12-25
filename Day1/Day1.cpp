#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string line;
    int sum = 0;
    ifstream file("Data.txt");
    while (std::getline(file, line)) {
        int first;
        int last;
        for (auto it = line.begin(); it != line.end(); ++it) {
            if (isdigit(*it)) {
                first = *it - '0';
                break; 
            }
        }
        for (auto it = line.rbegin(); it != line.rend(); ++it) {
            if (isdigit(*it)) {
                last = *it - '0';
                break; 
            }
        }
        sum += first*10 + last;
    }
    file.close();
    cout << sum;
    return 1;
}