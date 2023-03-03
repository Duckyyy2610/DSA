#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*Input:
14
128 104 53 876 660 961 754 775 290 231 224 915 392 994 
*/
/*Output: 6
*/

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int &x : a) cin>>x;
    vector<int> res;
    for(int i=0; i<n; i++)
    {
        auto it = lower_bound(res.begin(), res.end(), a[i]);
        if(it == res.end())
        {
            res.push_back(a[i]);
        }
        else 
        {
            *it = a[i];
        }
    }
    cout<<res.size();
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
