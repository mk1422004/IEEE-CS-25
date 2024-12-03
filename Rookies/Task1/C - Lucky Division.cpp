#include <iostream>
using namespace std;

// Function to check if a number is almost lucky
bool isAlmostLucky(int n) {
    // Array of lucky numbers
    int luckyNumbers[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    int size = sizeof(luckyNumbers) / sizeof(luckyNumbers[0]);  // int size = 14; fixed size

    for (int i = 0; i < size; i++) {
        if (n % luckyNumbers[i] == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    if (isAlmostLucky(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
