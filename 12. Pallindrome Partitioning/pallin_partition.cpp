#include<bits/stdc++.h>

using namespace std;

bool isPallindrome(string str,int i,int j)
{
    string s=str.substr(i,j-i+1);
    string s2=s;
    reverse(s.begin(), s.end());
    if(s==s2) return true;
    return false;
}

int minPalPartition(string str,int i,int j)
{
    if(i>=j) return 0;
    if(isPallindrome(str,i,j)) return 0;
    
    int mn=numeric_limits<int>::max();
    for(int k=i;k<=j-1;k++)
    {
        int temp=minPalPartition(str,i,k)+1+minPalPartition(str,k+1,j);
        mn=min(mn,temp);
    }
    return mn;
}

int minPalPartition_recur_memo(string str,int i,int j,int** memo)
{
    if(i>=j) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    if(isPallindrome(str,i,j)) return 0;
    
    int mn=numeric_limits<int>::max();
    for(int k=i;k<=j-1;k++)
    {
        int temp=minPalPartition_recur_memo(str,i,k,memo)+1+minPalPartition_recur_memo(str,k+1,j,memo);
        mn=min(mn,temp);
    }
    return memo[i][j]= mn;
}

int minPalPartition_memo(string str,int i,int j)
{
    int **memo=new int*[j+2];
    for(int k=0;k<j+2;k++)
    {
        memo[k]=new int[j+2];
        memset(memo[k],-1,sizeof(memo[k])*(j+2));
    }
    return minPalPartition_recur_memo(str,i,j,memo);
}

int main()
{
    string str = "ababbbabbababa";
    cout << "Min cuts needed for Palindrome Partitioning is: " << minPalPartition(str, 0, str.length() - 1) << endl;
    cout << "Min cuts needed for Palindrome Partitioning is: " << minPalPartition_memo(str, 0, str.length() - 1) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
