#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*Input:
ZHFTDFHF
TFISHROV
*/
/*Output: 3
*/
int dp[1001][1001];
int main() {
    string s, x;
    cin>>s>>x;
    s='i'+s; x='k'+x;
    for(int i=1; i<s.size(); i++)
    {
        for(int j=1; j<x.size(); j++)
        {
            if(s[i]==x[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<< dp[s.size()-1][x.size()-1];
    return 0;
}
