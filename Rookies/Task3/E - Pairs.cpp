#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100000];

bool b_search(int l, int r, long long x){
    int m;
    while (l <= r){
        m = l + (r-l)/2;
        if (arr[m] == x) 
            return true;  
        if (arr[m] < x) 
            l = m + 1; 
        else
            r = m - 1; 
    }
  return false; 
}
int main() {
    int n;
    long long k, ans=0;
    cin>>n>>k;
    int i,j;
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(i=0; i<n-1; i++){
        if(b_search(i+1, n-1, arr[i]+k)){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}