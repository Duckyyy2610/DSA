// John có một đàn bò. Một ngày đẹp trời,
// anh ta quyết định mua xe tải với khả năng chở được
// C kg (1000 ≤ C ≤ 25000) để đưa những con bò đi xem phim. 
// Cho số con bò là N (20 ≤ N ≤ 100) và khối lượng w[i] của từng con 
// (đều nhỏ hơn C), hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.

// Input Format

// Dòng 1: 2 số nguyên C và N cách nhau bởi dấu cách; Dòng 2: Ghi lần lượt các số nguyên: w[i]

// Constraints

// 1000 ≤ C ≤ 25000; 20 ≤ N ≤ 100; w[i] <= C;

// Output Format

// Một số nguyên là tổng khối lượng bò lớn nhất mà John có thể mang đi xem phim.

// Sample Input 0

// 259 5
// 81 58 42 33 61
// Sample Output 0

// 242

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm> 
#include<cstring>
using namespace std;


int main() {
    int C,n;
    cin>>C>>n;
    int w[n];
    for(int &x : w) cin>>x;
    bool dp[C+1];
    memset(dp, false, sizeof(dp));
    dp[0]=true;
    for(int i=0;i<n;i++)
    {
        for(int j=C;j>=w[i];j--)
        {
            if(dp[j-w[i]])
            {
                dp[j]=true;
            }
        }
    }
    // cout<<dp[C];
    for(int i=C;i>=0;i--)
    {
        if(dp[i])
        {
            cout<<i<<" ";
            return 0;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
