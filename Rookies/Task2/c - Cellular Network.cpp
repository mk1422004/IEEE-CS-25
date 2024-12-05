#include <iostream>
#include <vector>
#include <cmath>   
#include <algorithm>   
#include <climits>  
using namespace std;

int main()
{

    int n,m;
    cin >> n >>m;
      vector<int>cities(n);
      vector<int>tower(m);

          for (int i = 0; i < n; ++i) {
        cin >> cities[i];
             }
          for (int i = 0; i < m; ++i) {
        cin >> tower[i];
             }

       int min_r = 0; // to track minimal radus


  for (int i = 0; i < n; ++i) {
    int city = cities[i];

    
    auto it = lower_bound(tower.begin(), tower.end(), city); //البحث عن اقرب برج 
    
    int distance = -1;

    // Check the tower at `it` and `it - 1` (if valid)
    if (it != tower.end()) {
        distance = min(distance, abs(city - *it));
    }
    if (it != tower.begin()) {
        distance = min(distance, abs(city - *(it - 1)));
    }

   
    min_r = max(min_r, distance);
}

  
 cout << min_r << endl;

    return 0;



}