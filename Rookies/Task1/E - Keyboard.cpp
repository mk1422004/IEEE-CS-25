#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (heights[i] > heights[maxIndex]) {
            maxIndex = i;
        }
    }

    int minIndex = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (heights[i] < heights[minIndex]) {
            minIndex = i;
        }
    }

   
    int swaps = maxIndex + (n - 1 - minIndex);

    if (maxIndex > minIndex) {
        swaps--;
    }

    cout << swaps << endl;

    return 0;
}