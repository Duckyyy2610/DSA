// Ngân hàng XYZ hiện có N tờ tiền có mệnh giá khác nhau được lưu vào mảng C[], bạn hãy tìm cách đổi số tiền là S sao cho số tờ tiền cần dùng là ít nhất. Bạn được sử dụng một mệnh giá không giới hạn số lần.

// Input Format

// Dòng đầu tiên chứa 2 số N và S; Dòng thứ 2 chưa N số là mệnh giá các tờ tiền;

// Constraints

// 1<=N<=100; 1<=S<=10^6; 1<=C[i]<=10^6;

// Output Format

// In ra số tờ tiền nhỏ nhất cần đổi. Nếu không thể đổi được số tiền đúng bằng S thì in ra -1.

// Sample Input 0

// 3 10
// 4 5 8
// Sample Output 0

// 2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
    int n,s;
    cin>>n>>s;
    int a[n], dp[s+1];
    for(int &x : a )cin>>x;
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=s;i++)
    {
        dp[i]=1000000000;
        for(int j=0;j<n;j++)
        {
            if(i>=a[j])
            {
                dp[i]=min(dp[i],dp[i-a[j]]+1);
            }
        }
    }
    if(dp[s]<1000000000)cout<<dp[s];
    else cout<<-1;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
