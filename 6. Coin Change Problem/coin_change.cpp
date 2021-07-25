//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>

using namespace std;


int coinChange_bruteforce(int coin[],int n,int S)
{
    if(n==0 || S==0) return S==0? 1:0;
    
    if(coin[n-1]>S) return coinChange_bruteforce(coin,n-1,S);
    
    else return coinChange_bruteforce(coin,n,S-coin[n-1]) + coinChange_bruteforce(coin,n-1,S);
}

int coinChange_memo_recur(int coin[],int n, int S,int** memo)
{
    if(n==0 || S==0) return S==0?1:0;
    
    if(memo[n][S]!=-1) return memo[n][S];
    
    if(coin[n-1]>S) return memo[n][S]=coinChange_memo_recur(coin,n-1,S,memo);
    
    else return memo[n][S]=coinChange_memo_recur(coin,n,S-coin[n-1],memo) + coinChange_memo_recur(coin,n-1,S,memo);
}

int coinChange_memo(int coin[],int n, int S)
{
    int** memo=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        memo[i]=new int[S+1];
        memset(memo[i],-1,sizeof(memo[i])*(S+1));
    }
    
    return coinChange_memo_recur(coin,n,S,memo);
}

int coinChange_tabulation(int coin[],int n,int S)
{
    int table[n+1][S+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int s=0;s<=S;s++)
        {
            if(s==0 || i==0) table[i][s]=s==0?1:0;
            
            else if(coin[i-1]<=s)
            {
                table[i][s]=table[i][s-coin[i-1]] + table[i-1][s];
            }
            else table[i][s]= table[i-1][s];
        }
    }
    return table[n][S];
}

int main()
{
    int coin[] = {2,5,10};
    int n = sizeof(coin)/sizeof(coin[0]);
    int S=10; // iska chutta lena h
    cout<<coinChange_bruteforce(coin,n,S)<<endl;
    cout<<coinChange_memo(coin,n,S)<<endl;
    cout<<coinChange_tabulation(coin,n,S)<<endl;
    
    return 0;
}   

// https://www.geeksforgeeks.org/coin-change-dp-7/
