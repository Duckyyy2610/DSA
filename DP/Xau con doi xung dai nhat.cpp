// Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự. Hãy tìm xâu con đối xứng dài nhất của S.

// Input Format

// Dòng duy nhất chứa xâu S

// Constraints

// 1<=len(S)<=1000;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// edhcgeehahbbeggfcgcchffbffcgfghgc
// Sample Output 0

// 5
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
    string s;
    cin>>s;
    int f[s.length()+1][s.length()+1];
    memset(f, 0, sizeof(f));
    for(int i=0;i<s.length();i++)
    {
        f[i][i]=1;
    }
    int Max=0;
    for(int len=2;len<=s.length();len++)
    {
        for(int i=0;i<=s.length()-len;i++)
        {
            int j=len+i-1;
            if(len==2)
            {
                if(s[i]==s[j]) f[i][j]=1;
                else f[i][j]=0;
            }
            else 
            {
                if(s[i]==s[j] && f[i+1][j-1])
                {
                    f[i][j]=1;
                }
            }
            if(f[i][j]) Max=max(Max, len);
        }
    }
    cout<<Max;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
