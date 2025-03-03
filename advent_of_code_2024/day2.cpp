#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string line;
    int count = 0;

    while (getline(cin, line)) {
        if (line.empty()) continue; // Skip empty lines
        stringstream ss(line);
        int prev, number;
        bool flag = true; 
        int direction = 0;
        if (!(ss >> prev)) {
            continue; 
        }
        while (ss >> number) {
            int diff = number - prev;
            if (abs(diff) < 1 || abs(diff) > 3) {
                flag = false; 
                break;
            }
            int currentDirection = (diff > 0) ? 1 : -1;
            if (direction != 0 && direction != currentDirection) {
                flag = false;
                break;
            }
            direction = currentDirection;
            prev = number;
        }
        if (flag) {
            count++;
        }

    }
    cout << count << endl;
    return 0;
}


