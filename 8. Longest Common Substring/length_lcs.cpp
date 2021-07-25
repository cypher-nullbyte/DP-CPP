//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<climits>
#include<iterator>
#include<unordered_map>

using namespace std;

int len_lcs_bruteforce(char X[],char *Y,int m,int n,int count)
{
    if(m==0 || n==0) return count;
    
    if(X[m-1]!=Y[n-1])
        return max(count,max(len_lcs_bruteforce(X,Y,m-1,n,0),len_lcs_bruteforce(X,Y,m,n-1,0)));
    else return  len_lcs_bruteforce(X,Y,m-1,n-1,count+1);
    
}

int len_lcs_memo_recur(char X[],char *Y,int m,int n,int count,unordered_map<string,int> memo)
{
    if(m==0 || n==0) return count;
    string key= to_string(m)+"."+to_string(n)+"."+to_string(count);
    unordered_map<string,int>::iterator res=memo.find(key);
    if(res!=memo.end()) return res->second;
    
    if(X[m-1]!=Y[n-1])
        return memo[key]=max(count,max(len_lcs_memo_recur(X,Y,m-1,n,0,memo),len_lcs_memo_recur(X,Y,m,n-1,0,memo)));
    else return memo[key]= len_lcs_memo_recur(X,Y,m-1,n-1,count+1,memo);

}

int len_lcs_memo(char X[],char *Y,int m,int n)
{
    unordered_map<string,int> hash_memo;
    return len_lcs_memo_recur(X,Y,m,n,0,hash_memo);
}

int len_lcs_tabulation(char X[],char Y[],int m,int n)
{
    int table[m+1][n+1];
    int mxm=0;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0) table[i][j]=0;
            
            else if(X[i-1]!=Y[j-1])
                table[i][j]=0;
            
            else 
            {
                table[i][j]=1+table[i-1][j-1];
                mxm=max(mxm,table[i][j]);
        
            }    
        }
    }
    
    // for(int i=0;i<=m;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     {
    //       cout<<table[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    
    return mxm;
}


int main()
{
    char X[] = "xyzcypherabc";
    char Y[] = "abccypherxyc";
    int m=strlen(X),n=strlen(Y);
    
    cout<<len_lcs_bruteforce(X,Y,m,n,0)<<endl;
    
    
    cout<<len_lcs_memo(X,Y,m,n)<<endl;
    
    cout<<len_lcs_tabulation(X,Y,m,n)<<endl;
    
    return 0;
}   

// https://www.geeksforgeeks.org/longest-common-substring-dp-29/
