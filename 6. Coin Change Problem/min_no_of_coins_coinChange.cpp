//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<climits>

using namespace std;


int min_coinChange_bruteforce(int coin[],int n,int S)
{
    if(n==0 || S==0) return S==0? 0:INT_MAX-1;
    
    if(coin[n-1]>S) return min_coinChange_bruteforce(coin,n-1,S);
    
    else return min(min_coinChange_bruteforce(coin,n,S-coin[n-1])+1 , min_coinChange_bruteforce(coin,n-1,S));
}

int min_coinChange_memo_recur(int coin[],int n, int S,int** memo)
{
    if(n==0 || S==0) return S==0? 0:INT_MAX-1;
    
    if(memo[n][S]!=-1) return memo[n][S];
    
    if(coin[n-1]>S) return memo[n][S]=min_coinChange_memo_recur(coin,n-1,S,memo);
    
    else return memo[n][S]=min(min_coinChange_memo_recur(coin,n,S-coin[n-1],memo)+1, min_coinChange_memo_recur(coin,n-1,S,memo));
}

int min_coinChange_memo(int coin[],int n, int S)
{
    int** memo=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        memo[i]=new int[S+1];
        memset(memo[i],-1,sizeof(memo[i])*(S+1));
    }
    
    return min_coinChange_memo_recur(coin,n,S,memo);
}

int min_coinChange_tabulation(int coin[],int n,int S)
{
    int table[n+1][S+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int s=0;s<=S;s++)
        {
            if(s==0 || i==0) table[i][s]=s==0?0:INT_MAX-1;
            
            else if(coin[i-1]<=s)
            {
                table[i][s]=min(table[i][s-coin[i-1]]+1, table[i-1][s]);
            }
            else table[i][s]= table[i-1][s];
        }
    }
    return table[n][S];
}

int main()
{
    int coin[] = {1,2,5,10,50};
    int n = sizeof(coin)/sizeof(coin[0]);
    int S=102; // iska chutta lena h
    cout<<min_coinChange_bruteforce(coin,n,S)<<endl;
    cout<<min_coinChange_memo(coin,n,S)<<endl;
    cout<<min_coinChange_tabulation(coin,n,S)<<endl;
    
    return 0;
}   

// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
