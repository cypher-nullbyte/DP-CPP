//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

int len_lcs_bruteforce(char X[],char *Y,int m,int n)
{
    if(m==0 || n==0) return 0;
    
    if(X[m-1]!=Y[n-1])
        return max(len_lcs_bruteforce(X,Y,m-1,n),len_lcs_bruteforce(X,Y,m,n-1));
    else return 1+ len_lcs_bruteforce(X,Y,m-1,n-1);
    
}

int len_lcs_memo_recur(char X[],char *Y,int m,int n,int** memo)
{
    if(m==0 || n==0) return 0;
    
    if(memo[m][n]!=-1) return memo[m][n];
    
    if(X[m-1]!=Y[n-1])
        return memo[m][n]=max(len_lcs_memo_recur(X,Y,m-1,n,memo),len_lcs_memo_recur(X,Y,m,n-1,memo));
    else return memo[m][n]=1+ len_lcs_memo_recur(X,Y,m-1,n-1,memo);
    
}

int len_lcs_memo(char X[],char *Y,int m,int n)
{
    int** memo=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        memo[i]=new int[n+1];
        memset(memo[i],-1,sizeof(memo[i])*(n+1));
    }
    return len_lcs_memo_recur(X,Y,m,n,memo);
    
}

int len_lcs_tabulation(char X[],char Y[],int m,int n)
{
    int table[m+1][n+1];
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0) table[i][j]=0;
            
            else if(X[i-1]!=Y[j-1])
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            
            else table[i][j]=1+table[i-1][j-1];
        }
    }
    
    return table[m][n];
}


int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m=strlen(X),n=strlen(Y);
    cout<<m+n-len_lcs_bruteforce(X,Y,m,n)<<endl;
    cout<<m+n-len_lcs_memo(X,Y,m,n)<<endl;
    cout<<m+n-len_lcs_tabulation(X,Y,m,n)<<endl;
    
    return 0;
}   
// The only extra thing is m+n-len_lcs
// Thats it!

// https://www.geeksforgeeks.org/shortest-common-supersequence/
