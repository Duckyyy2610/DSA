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
using namespace std;


int main() {
    int n,s;
    cin>>n>>s;
    long long a[n], dp[s+1]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=s) dp[a[i]]=1;
    }
    for(int i=1;i<=s;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=a[j])
            {
                dp[i]+=dp[i-a[j]];
                dp[i]%=1000000007;
            }
        }
    }
    cout<<dp[s];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
