#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*Input:
8 92
69 16 82 170 31 24 45 112 
*/
/*
Output: 1
*/
int main() {
    int n,s;
    cin>>n>>s;
    int a[n];
    bool f[s+1];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        
    }
    memset(f , false, sizeof(f));
    f[0]=true;
    for(int i=0;i<n;i++)
    {
        for(int j=s; j>=a[i]; j--)
        {
            if(f[j-a[i]])
            {
                f[j]=true;
            }
        }
    }
    
    if(f[s])cout<<1;
    else cout<<0;
    return 0;
}
