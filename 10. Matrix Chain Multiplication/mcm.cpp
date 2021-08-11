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

int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Minimum number of multiplications is: "
         << MCM(arr, 1, n - 1);
    return 0;
}

// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
