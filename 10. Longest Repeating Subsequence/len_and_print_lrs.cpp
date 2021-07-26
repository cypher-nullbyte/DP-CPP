//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm> //reverse
using namespace std;


void len_and_print_lrs_tabulation(string S,int n)
{
    int table[n+1][n+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0) table[i][j]=0;
            
            else if(S[i-1]==S[j-1] && i!=j)
                table[i][j]=1+table[i-1][j-1];
                
            else 
                table[i][j]=max(table[i-1][j],table[i][j-1]);
        }
    }
    cout<<table[n][n]<<endl;
    int i=n,j=n;
    string result;
    while(i>0 && j>0)
    {
        if(S[i-1]==S[j-1] && i!=j)
        {
            result.push_back(S[i-1]);
            i--;
            j--;
        }
        else if(table[i-1][j]>table[i][j-1]) i--;
        else j--;
    }
    reverse(result.begin(),result.end());
    cout<<result<<endl;
}


int main()
{
    string S= "AABEBCDD";
    int n=S.length();
    len_and_print_lrs_tabulation(S,n);
    // ABD
    return 0;
}   
// https://www.geeksforgeeks.org/longest-repeated-subsequence/
