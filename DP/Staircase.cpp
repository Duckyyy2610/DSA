// Một chiếc cầu thang có N bậc. 
// Mỗi bước, bạn được phép bước lên trên tối đa K bước. 


// Input Format

// Dòng duy nhất chứa 2 số nguyên N và K

// Constraints

// 1<=N<=100000; 1<=K<=100;

// Output Format

// In ra đáp án tìm được trên một dòng theo modulo 10^9+7.

// Sample Input 0

// 7 3
// Sample Output 0

// 44
// Sample Input 1

// 4 2
// Sample Output 1

// 5
#include<bits/stdc++.h>

using namespace std;
long long mod=1e9+7;
int main() {
    long long n;int k;
    cin>>n>>k;
    long long dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=min(i,k);j++)
        {
            dp[i]+=dp[i-j];
            dp[i]%=mod;
        }
    }
    cout<<dp[n];
    return 0;
}
