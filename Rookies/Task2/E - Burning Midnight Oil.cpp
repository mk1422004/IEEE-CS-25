#include <iostream>
using namespace std;

// فانكشن لحساب عدد الاسطر 
long long total_lines(long long v, int k) {
    long long total = 0;
    while (v > 0) {
        total += v;
        v /= k;  
    }
    return total;
}

int main() {
    long long n;
    int k;
    cin >> n >> k;  
    
  
    long long left = 1, right = n, answer = n;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (total_lines(mid, k) >= n) {
            answer = mid;
            right = mid - 1; 
        } else {
            left = mid + 1;  
        }
    }
    
    cout << answer << endl;  
    
    return 0;
}
