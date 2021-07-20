#include<bits/stdc++.h>
using namespace std;

int memo[1000][100000];

int knapSack_bruteforce(int W,int wt[],int val[],int n)
{
    if(W==0 || n==0) return 0;
    
    return max(knapSack_bruteforce(W-wt[n-1],wt,val,n-1)+val[n-1], knapSack_bruteforce(W,wt,val,n-1));
}


int knapSack_memo(int W,int wt[],int val[],int n)
{
    if(W==0 || n==0) return 0;
    if(memo[n][W]!=-1) return memo[n][W];
    return memo[n][W]= max(knapSack_memo(W-wt[n-1],wt,val,n-1)+val[n-1], knapSack_memo(W,wt,val,n-1));
}

int knapSack_tabulation(int W,int wt[],int val[],int n)
{
    int table[n+1][W+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0 || w==0) table[i][w]=0;
            else if(wt[i-1]<=w)
            {
                table[i][w]=max(table[i-1][w-wt[i-1]]+val[i-1],table[i-1][w]);
            }
            else{
                table[i][w]=table[i-1][w];
            }
        }
    }
    return table[n][W];
    
}


int knapSack_tabulation_space_opt1_rev(int W,int wt[],int val[],int n)
{
    int dp[W+1]={0};
    for(int i=1;i<=n;i++)
    {
        for(int w=W;w>=0;w--)
        {
            if(wt[i-1]<=w)
            {
                dp[w]=max(val[i-1]+dp[w-wt[i-1]],dp[w]);
            }
        }
    }
    return dp[W];
}


int knapSack_tabulation_space_opt2(int W,int wt[],int val[],int n)
{
    int dp[2][W+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(wt[i-1]<=w)
            {
                dp[1][w]=max(dp[1][w-wt[i-1]]+val[i-1],dp[0][w]);
            }
        }
    }
    return dp[1][W];
}


int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = {1, 2, 3};
    int W = 5;
    int n = sizeof(val) / sizeof(val[0]);
    
    cout << knapSack_bruteforce(W,wt,val,n) << endl;
    
    memset(memo,-1,sizeof(memo));
    cout << knapSack_memo(W,wt,val,n) << endl;
    
    cout << knapSack_tabulation(W, wt, val, n) << endl;
    cout << knapSack_tabulation_space_opt1_rev(W, wt, val, n) << endl;
    cout << knapSack_tabulation_space_opt2(W, wt, val, n) << endl;
    return 0;
}
