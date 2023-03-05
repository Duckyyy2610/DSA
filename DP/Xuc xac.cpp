// Tèo hiện đang học sinh lớp 10A1, vốn là một học sinh 
// được đánh giá rất cao về khả năng toán học nên 
// Tèo thường được các bạn trong lớp nhờ giải các bài toán trên tạp chí toán học và tuổi trẻ. 
// Hôm nay Tí là bạn thân của Tèo gặp một bài toán trên tạp chí và đã nhờ Tèo giải hộ, 
// Tèo dù rất giỏi toán và biết cách làm bài này nhưng bài toán này kết quả quá lớn nên 
// Tèo phải nhờ tới bạn lập trình thuật toán để tìm ra lời giải giúp Tèo. Bài toán có yêu cầu rất đơn giản, 
// cho ngẫu nhiên số N, hỏi rằng nếu được tung một con xúc xắc không giới hạn số lần và lấy 
// tổng số chấm trên mặt xúc xắc cộng lại với nhau, hỏi có bao nhiêu cách tung để tổng số chấm trong mọi lần tung xúc xắc bằng N. 
// Bạn hãy giúp Tèo giải quyết bài toán này nhé, vì số cách tung có thể quá lớn, nên bạn hãy chia dư kết quả với modulo 10^9 + 7

// Input Format

// Dòng duy nhất chứa số nguyên dương N

// Constraints

// 1<=N<=10^6;

// Output Format

// Kết quả của bài toán

// Sample Input 0

// 7
// Sample Output 0

// 63
// Sample Input 1

// 3
// Sample Output 1

// 4
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int mod= 1e9+7;
int main() {
    int n;
    cin>>n;
    long long dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=min(i,6);j++)
        {
            dp[i]+=dp[i-j];
            dp[i]%=mod;
        }
    }
    cout<<dp[n];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
