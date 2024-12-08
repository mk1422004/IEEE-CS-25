#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
   
    int t;
    cin >> t;
    while (t --)
    {
        int n,l,r;
        cin >> n >> l >> r;  // n-> عدد العناصر فى المصفوفه   l->الحد الادنى    r-> الحد الاقصي  
        vector<int> v; 
        int k = n;
        while (k--)
        {
            int vv;
            cin >> vv;
            v.push_back(vv);
        }
      
        sort(v.begin(), v.end());
        auto count = [&](int r) -> long long{
            long long res = 0;
            int i = 0, j = n - 1;
            while(i < j) {
                while(i < j && v[i] + v[j] > r)
                {
                    j--;
                }
                res += (j - i);
                i++;
            }
            return res;
        };
        cout << count(r) - count(l - 1) << endl;
    }
    return 0;
}