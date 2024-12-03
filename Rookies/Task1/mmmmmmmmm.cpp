#include <iostream>
#include <string>
using namespace std;

int main() {
    char direction;
    string typed_message;
    
    cin >> direction;
    cin >> typed_message;
    
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    
    for (char c : typed_message) {
        int index = keyboard.find(c);  
        if (direction == 'L') {
            cout << keyboard[index + 1];
        } else if (direction == 'R') {
            cout << keyboard[index - 1];
        }
    }

    cout << endl;
    return 0;
}
