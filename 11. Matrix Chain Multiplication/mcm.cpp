#include<bits/stdc++.h>

using namespace std;

int MCM(int arr[],int i,int j)
{
    if(i>=j) return 0;
    
    int mn=numeric_limits<int>::max();
    for(int k=i;k<=j-1;k++)
    {
        int temp=MCM(arr,i,k)+MCM(arr,k+1,j)+ arr[i-1]*arr[k]*arr[j];
        mn=min(mn,temp);
    }
    return mn;
    
}

int MCM_recur(int arr[],int i,int j,int**memo)
{
    if(i>=j) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    
    int mn=numeric_limits<int>::max();
    for(int k=i;k<=j-1;k++)
    {
        int temp=MCM_recur(arr,i,k,memo)+MCM_recur(arr,k+1,j,memo)+ arr[i-1]*arr[k]*arr[j];
        mn=min(mn,temp);
    }
    return memo[i][j]=mn;
}

int MCM_memo(int arr[],int i,int j)
{
    int **memo=new int*[j+2];
    for(int k=0;k<j+2;k++)
    {
        memo[k]=new int[j+2];
        memset(memo[k],-1, sizeof(memo[k])*(j+2));
    }
    return MCM_recur(arr,i,j,memo);
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Minimum number of multiplications is: "<< MCM(arr, 1, n - 1)<<endl;
    cout << "Minimum number of multiplications is: "<< MCM_memo(arr, 1, n - 1)<<endl;
    return 0;
}

// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
