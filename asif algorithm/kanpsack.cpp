#include<bits/stdc++.h>
using namespace std;
int knapsack(int n,int W , int a[],int b[])//knapsack is done by dynamic programming
{
    int knap[n+1][W+1];
    for(int i = 0; i<=n;i++)
    {
        for(int k = 0;k<=W;k++)
        {
            if(i==0||k==0)
            {
                knap[i][k]=0;
                continue;
            }
            if(k-b[i-1]>=0)
            {
                knap[i][k]=max(knap[i-1][k],knap[i-1][k-b[i-1]]+a[i-1]);
            }
            else{
                knap[i][k]=knap[i-1][k];
            }
        }
    }
    cout<<knap[n][W];
}

int main(){
    int n ;
    cin>>n;
    int a[n],b[n];
    for(int i = 0; i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    int W;
    cin>>W;
    knapsack(n,W,a,b);
}
/*
4
1 1
4 3
5 4
7 5
7
output
9
*/

