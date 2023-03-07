// Bạn biết rằng một mảng có n số nguyên chỉ gồm các số từ 1 đến m và độ lệch giữa 
// 2 phần tử liền kề trong mảng không được vượt quá 1 đơn vị. 
// Bài toán đặt ra đó là cho bạn một mảng trong đó một số giá trị trong mảng chưa được xác định giá trị, 
// nhiệm vụ của bạn là đếm số mảng phù hợp với mô tả, đó là các số liền kề trong mảng không lệch nhau quá 1 đơn vị 
// và các giá trị trong mảng chỉ được nằm trong đoạn từ 1 tới m.

// Input Format

// Dòng nhập đầu tiên có hai số nguyên n và m: kích thước mảng và giới hạn trên cho mỗi giá trị.

// Dòng tiếp theo có n số nguyên x1, x2,…, xn: nội dung của mảng. Giá trị 0 biểu thị một giá trị không xác định.

// Constraints

// 1≤n≤10^5;
// 1≤m≤100; 0≤xi≤m;

// Output Format

// In ra số lượng mảng phù hợp sau khi chia dư cho 1e9 + 7

// Sample Input 0

// 3 5
// 2 0 2
// Sample Output 0

// 3
// Explanation 0

// Các mảng có thể thỏa mãn : [2, 1, 2], [2, 2, 2], [2, 3, 2]
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long mod = 1e9 + 7;
long long dp[100005][102];

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(a[0]!=0) dp[0][a[0]]=1;
    else for(int i=1;i<=m;i++) dp[0][i]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            for(int j=1;j<=m;j++)
            {
                for(int k=-1;k<2;k++)
                {
                    int tmp=k+j;
                    if(tmp>=1 && tmp<=m)
                    {
                        dp[i][j]+=dp[i-1][tmp];
                        dp[i][j]%=mod;
                    }
                }
            }
        }
        else
        {
            for(int k=-1;k<2;k++)
            {
                int tmp=k+a[i];
                if(tmp>=1 && tmp<=m)
                {
                    dp[i][a[i]]+=dp[i-1][tmp];
                    dp[i][a[i]]%=mod;
                }
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        ans+=dp[n-1][i];
        ans%=mod;
    }
    cout<<ans<<endl;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}