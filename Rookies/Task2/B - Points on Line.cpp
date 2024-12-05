#include <iostream>
#include <vector>
using  namespace std;


int main()
{
 long long  n,d;
 cin>>n>>d;

 vector<long long > point(n);
  for (long long  i = 0; i < n; i++)
  {
    cin>>point[i];
  }
  
  long long count =  0 ; // لحساب عدد المجموعات المحققه للشرط
  long long  j = 0; // النهايه 

    for (long long i = 0; i < n - 2; ++i) {
        while (j < n && point[j] - point[i] <= d) {
            j++;
        }

        long long  k = j - i - 1;
        if (k >= 2) {
            count += k * (k - 1) / 2;
        }
    }

    cout << count << endl;
    return 0;
  

}