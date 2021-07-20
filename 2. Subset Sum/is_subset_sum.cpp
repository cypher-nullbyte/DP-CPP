// #include<bits/stdc++.h>
#include<iostream>
#include<cstring>
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

bool isSubsetSum_memo(int set[],int n,int sum)
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
    return isSubsetSum_memo_recur(set,n,sum,memo);
}

bool isSubsetSum_tabulation(int set[],int n,int sum)
{
    int table[n+1][sum+1];
    memset(table,0,sizeof(table));
    
    for(int i=0;i<=n;i++)
    {
        for(int s=0;s<=sum;s++)
        {
            if(i==0) table[i][s]=0;
            if(s==0) table[i][s]=1;
            
            else if(set[i-1]<=s)
            {
                table[i][s]= table[i-1][s-set[i-1]] || table[i-1][s];
            }
            else table[i][s]=table[i-1][s];
            
        }
        
    }
    return table[n][sum];
    
}

void answer(bool ans)
{
    cout<<(ans?"Yes":"No")<<endl;
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    answer(isSubsetSum_brute_force(set, n, sum));

    answer(isSubsetSum_memo(set, n, sum));

    answer(isSubsetSum_tabulation(set, n, sum));
    
    
    return 0;
}

// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
