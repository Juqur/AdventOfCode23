#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct NumberInfo {
    int digit;  
    int position;  
};

string numberWords[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string line;
int sum = 0;
ifstream file("Data.txt");

int main(){
    while (std::getline(file, line)) {
        std::vector<NumberInfo> numbers;
        int i = 0;
        for (auto it = line.begin(); it != line.end(); ++it) {
            if (isdigit(*it)) {
                NumberInfo info = {*it - '0', i};
                numbers.push_back(info);
            }
            i++;
        }
        for (int i = 0; i <= 9; ++i) {
            int pos = line.find(numberWords[i]);
            while (pos != -1) {
                NumberInfo info = {i, pos};
                numbers.push_back(info);
                pos = line.find(numberWords[i], pos + 1);
            }
        }
        sort(numbers.begin(), numbers.end(), [](const NumberInfo& a, const NumberInfo& b) {
            return a.position < b.position;
        });
        sum += (numbers.front().digit ) * 10 + (numbers.back().digit);
    }
    file.close();
    std::cout << sum;
    return 1;
}