// Cho một số tự nhiên N được biểu diễn như một xâu kí tự, bạn hãy tính tổng của tất cả các số tạo bởi các xâu con liên tiếp của N, ví dụ N = 235 thì ta có tổng = 2 + 3 + 5 + 23 + 35 + 235.

// Input Format

// Dòng duy nhất chứa số nguyên dương N

// Constraints

// 1<=N<=10^12

// Output Format

// In ra kết quả của bài toán

// Sample Input 0

// 1807
// Sample Output 0

// 2915
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long n;
    cin>>n;
    string s= to_string(n);
    long long dp[s.size()+1], ans=0;
    dp[0]=0;
    for(int i=1;i<=s.size();i++)
    {
        int x=s[i-1]-'0';
        dp[i]=dp[i-1]*10+x*i;
        ans+=dp[i];
    }
    cout<<ans;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
