//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm> //reverse
#include<cstring>
using namespace std;

string print_lcs_tabulation(char X[],char Y[],int m,int n)
{
    int table[m+1][n+1];
    int mxm=0;
    int i_focus,j_focus;
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
                if(table[i][j]>mxm)
                {
                    mxm=table[i][j];
                    i_focus=i;
                    j_focus=j;
                }
        
            }    
        }
    }
    string result;
    while(table[i_focus][j_focus]>0)
    {
        result.push_back(X[i_focus-1]);
        i_focus--;
        j_focus--;
    }
    reverse(result.begin(),result.end());
    return result;
}


int main()
{
    char X[] = "xyzcypherabc";
    char Y[] = "abccypherxyc";
    int m=strlen(X),n=strlen(Y);
    cout<<print_lcs_tabulation(X,Y,m,n)<<endl;
    return 0;
}   

// https://www.geeksforgeeks.org/print-longest-common-substring/
