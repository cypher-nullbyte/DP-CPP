// #include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;


int countSubsetSum_brute_force(int set[],int n,int sum)
{
    if(n==0 && sum>0) return 0;
    if(sum==0) return 1;
    
    if(set[n-1]>sum)    return countSubsetSum_brute_force(set,n-1,sum);
        
    return countSubsetSum_brute_force(set,n-1,sum-set[n-1]) + countSubsetSum_brute_force(set,n-1,sum);
}

int countSubsetSum_memo_recur(int set[],int n,int sum,int **memo)
{
    if(n==0 && sum>0) return 0;
    if(sum==0) return 1;
    
    if(memo[n][sum]!=-1) return memo[n][sum];
    
    if(set[n-1]>sum)    return memo[n][sum]= countSubsetSum_memo_recur(set,n-1,sum,memo);
        
    return memo[n][sum]= countSubsetSum_memo_recur(set,n-1,sum-set[n-1],memo) + countSubsetSum_memo_recur(set,n-1,sum,memo);
}

int countSubsetSum_memo(int set[],int n,int sum)
{
    int **memo=new int*[n+1];
    for(int i=0;i<=n;i++) 
    {
        memo[i]=new int[sum+1];
        memset(memo[i],-1,sizeof(memo[i])*(sum+1));
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=sum;j++)
    //         cout<<memo[i][j]<<" ";
    //     cout<<endl;
    // }
    return countSubsetSum_memo_recur(set,n,sum,memo);
}

int countSubsetSum_tabulation(int set[],int n,int sum)
{
    int table[n+1][sum+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int s=0;s<=sum;s++)
        {
            if(i==0 || s==0) table[i][s]=(s==0)? 1:0;
            
            else if(set[i-1]<=s)
            {
                table[i][s]= table[i-1][s-set[i-1]] + table[i-1][s];
            }
            else table[i][s]=table[i-1][s];
            
        }
        
    }
    return table[n][sum];
    
}


int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    cout<<countSubsetSum_brute_force(set, n, sum)<<endl;

    cout<<countSubsetSum_memo(set, n, sum)<<endl;
    
    cout<<countSubsetSum_tabulation(set, n, sum)<<endl;

    
    
    return 0;
}
