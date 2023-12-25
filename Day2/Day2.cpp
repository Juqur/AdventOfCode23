#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_RED = 12;
const int MAX_GREEN = 13;
const int MAX_BLUE = 14;

const int ID_OFFSET = 5;
const int COLOR_OFFSET = 2;

string line;
int sum = 0;
ifstream file("Data.txt");

int getGameId(string line){
    int colonPos = line.find(':');
    string gameIdString = line.substr(ID_OFFSET, colonPos - ID_OFFSET); //The id starts at pos = 5
    return stoi(gameIdString);
}

bool getColorSum(string line, string color, int max){
    int pos = line.find(color);
    while (pos != -1 ){
        int index = 0;
        int colorSum = 0;
        while (isdigit(line[pos - COLOR_OFFSET - index])){
            colorSum += (line[pos - COLOR_OFFSET - index] - '0') * pow(10, index);
            index++;
        }
        if (colorSum > max) return false;
        pos = line.find(color, pos + 1);
    }
    return true;
}

int main(){
    while (std::getline(file, line)) {
        if (!getColorSum(line, "red", MAX_RED)) continue;
        if (!getColorSum(line, "blue", MAX_BLUE)) continue;
        if (!getColorSum(line, "green", MAX_GREEN)) continue;
        cout << getGameId(line);
        cout << '\n';
        sum += getGameId(line);
    }
    file.close();
    cout << sum;
    return 1;
}
