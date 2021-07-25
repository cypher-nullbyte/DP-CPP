//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>

using namespace std;



int rodCutting_bruteforce(int price[],int size[],int n,int S)
{
    if(n==0 || S==0) return 0;
    
    if(size[n-1]>S) return rodCutting_bruteforce(price,size,n-1,S);
    
    else return max(rodCutting_bruteforce(price,size,n,S-size[n-1])+price[n-1], rodCutting_bruteforce(price,size,n-1,S));
}

int rodCutting_memo_recur(int price[], int size[],int n, int S,int** memo)
{
    if(n==0 || S==0) return 0;
    
    if(memo[n][S]!=-1) return memo[n][S];
    
    if(size[n-1]>S) return memo[n][S]=rodCutting_memo_recur(price,size,n-1,S,memo);
    
    else return memo[n][S]=max(rodCutting_memo_recur(price,size,n,S-size[n-1],memo)+price[n-1], rodCutting_memo_recur(price,size,n-1,S,memo));
}

int rodCutting_memo(int price[], int size[],int n, int S)
{
    int** memo=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        memo[i]=new int[S+1];
        memset(memo[i],-1,sizeof(memo[i])*(S+1));
    }
    
    return rodCutting_memo_recur(price,size,n,S,memo);
}

int rodCutting_tabulation(int price[],int size[],int n,int S)
{
    int table[n+1][S+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int s=0;s<=S;s++)
        {
            if(s==0 || i==0) table[i][s]=0;
            
            else if(size[i-1]<=s)
            {
                table[i][s]=max(table[i][s-size[i-1]]+price[i-1], table[i-1][s]);
            }
            else table[i][s]= table[i-1][s];
        }
    }
    return table[n][S];
}

int main()
{
//                    X            X                
//                 1  2   3  4  5  6   7    8
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price)/sizeof(price[0]);
    int size[n];
    for(int i=0;i<n;i++)
        size[i]=i+1;
    cout<<rodCutting_bruteforce(price,size,n,n)<<endl;
    
    cout<<rodCutting_memo(price,size,n,n)<<endl;
    
    cout<<rodCutting_tabulation(price,size,n,n)<<endl;
    
    return 0;
}   

// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
