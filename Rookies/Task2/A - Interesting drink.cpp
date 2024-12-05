#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{ 
     int num_of_shops = 0 ;
      cin>>num_of_shops;
     
    vector<int> price_of_bottles(num_of_shops);
    for (int i = 0; i < num_of_shops; ++i) {
        cin >> price_of_bottles[i] ;// أسعار المشروب في كل متجر
       cout<<endl;
    }

     sort(price_of_bottles.begin(), price_of_bottles.end());
     
     int q; //num of days
     cin>>q;

     while (q--)
     {
        int mi; // number of coin on every day
        cin>> mi ; 

         int found = upper_bound(price_of_bottles.begin(), price_of_bottles.end(), mi) - price_of_bottles.begin();
          cout<< found <<endl;

     }
     

}

