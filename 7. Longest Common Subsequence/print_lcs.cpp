//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm> //reverse
using namespace std;


string print_lcs_tabulation(string X,string Y,int m,int n)
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
    
    //Printing 
    string result;
    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            result.push_back(X[i-1]);
            i--;
            j--;
        }
        else if(X[i-1]>Y[j-1]) i--;
        else j--;
    }
    reverse(result.begin(),result.end());
    return result;
}


int main()
{
    string X= "AGGTAB";
    string Y= "GXTXAYB";
    int m=X.size(),n=Y.length();
    cout<<print_lcs_tabulation(X,Y,m,n)<<endl;
    
    return 0;
}   
