// Nhiệm vụ của bạn là đếm số cách các số 1,2,…, n có thể chia thành hai tập có tổng bằng nhau. 
// Các phần tử trong tập không xét đến thứ tự Ví dụ, nếu n = 7, có bốn nghiệm: 
// {1,3,4,6} và {2,5,7}. {1,2,5,6} và {3,4,7}. {1,2,4,7} và {3,5,6}. {1,6,7} và {2,3,4,5}.

// Input Format

// Dòng duy nhất chứa số nguyên dương n

// Constraints

// 1<=n<=500

// Output Format

// In ra kết quả sau khi chia dư với 10^9 + 7

// Sample Input 0

// 7
// Sample Output 0

// 4
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long mod=1e9+7;
long long powMod(long long a, long long b){
    a%=mod;
    long long res=1;
    while(b)
    {
        if(b%2)
        {
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        b/=2;
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    long long sum=n*(n+1)/2;
    if(sum%2)
    {
        cout<<0;
        return 0;
    }
    else
    {
        sum/=2;
        long long dp[sum+1]={0};
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=sum;j>=i;j--)
            {
                dp[j]+=dp[j-i];
                dp[j]%=mod;
            }
        }
        // cout<<dp[sum]<<endl;
        cout<<(dp[sum]*powMod(2, mod-2))%mod;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}