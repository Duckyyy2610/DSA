// Bạn được cung cấp một số nguyên n. Trên mỗi bước, bạn có thể trừ một trong các chữ số khỏi số. Cần thực hiện bao nhiêu bước để số đó bằng 0?

// Input Format

// Dòng duy nhất chứa số nguyên n

// Constraints

// 1<=n<=10^6;

// Output Format

// In ra số bước tối thiểu

// Sample Input 0

// 4
// Sample Output 0

// 1
// Sample Input 1

// 27
// Sample Output 1

// 5
// Explanation 1

// Các bước thực hiện : 27→20→18→10→9→0
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1, 0);
    for(int i=1;i<=n;i++)
    {
        string s=to_string(i);
        dp[i]=1e9+7;
        for(auto x : s)
        {
            dp[i]=min(dp[i], dp[i-x+'0']+1);
        }
    }
    cout<<dp[n]<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
