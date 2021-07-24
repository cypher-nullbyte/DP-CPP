// #include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<numeric> //accumulate
#include<climits> //INT_MAX
using namespace std;

bool isSubsetSum_brute_force(int set[],int n,int sum)
{
    if(n==0 && sum>0) return false;
    if(sum==0) return true;
    
    if(set[n-1]>sum)    return isSubsetSum_brute_force(set,n-1,sum);
        
    return isSubsetSum_brute_force(set,n-1,sum-set[n-1]) || isSubsetSum_brute_force(set,n-1,sum);
}

bool isSubsetSum_memo_recur(int set[],int n,int sum,int **memo)
{
    if(n==0 && sum>0) return false;
    if(sum==0) return true;
    
    if(memo[n][sum]!=-1) return memo[n][sum];
    
    if(set[n-1]>sum)    return memo[n][sum]= isSubsetSum_memo_recur(set,n-1,sum,memo);
        
    return memo[n][sum]= isSubsetSum_memo_recur(set,n-1,sum-set[n-1],memo) || isSubsetSum_memo_recur(set,n-1,sum,memo);
}

int minSubsetSum_memo(int set[],int n,int total)
{
    int **memo=new int*[n+1];
    for(int i=0;i<=n;i++) 
    {
        memo[i]=new int[total+1];
        memset(memo[i],-1,sizeof(memo[i])*(total+1));
    }
    int mn=INT_MAX;
    for(int i=1;i<total/2;i++)
    {
        if(isSubsetSum_memo_recur(set,n,i,memo))
        mn=min(mn,total-2*i);
    }
    return mn;
}

int minSubsetSum_tabulation(int set[],int n,int total)
{
    
    int mn=INT_MAX;
    int t=total;
    total=total/2;
    
    int table[n+1][total+1];
    memset(table,0,sizeof(table));
    
    while (total--)
    {
        int sum=total+1;
        
        for(int i=0;i<=n;i++)
        {
            for(int s=0;s<=sum;s++)
            {
                if(i==0 || s==0) table[i][s]=(s==0)? 1:0;
                
                else if(set[i-1]<=s)
                {
                    table[i][s]= table[i-1][s-set[i-1]] || table[i-1][s];
                }
                else table[i][s]=table[i-1][s];
                
            }
            
        }
        if(table[n][sum])
            mn=min(mn,t-2*sum);
    }
    return mn;   
}

int minSubsetSum_brute_force(int set[],int n,int total)
{
    int mn=INT_MAX;
    for(int i=1;i<=total/2;i++)
    {
        if(isSubsetSum_brute_force(set,n,i))
            mn=min(mn,total-2*i);
    }
    return mn;
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };    
    int n = sizeof(set) / sizeof(set[0]);
    int sum=accumulate(set,set+n,0);
    cout<<minSubsetSum_brute_force(set, n, sum)<<endl;

    cout<<minSubsetSum_memo(set, n, sum)<<endl;
    
    cout<<minSubsetSum_tabulation(set, n, sum)<<endl;

    
    
    return 0;
}
// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
