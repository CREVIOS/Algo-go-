#include<bits/stdc++.h>
using namespace std;
/// Longest palindromic subsequence
int arr(string a,int i,int j)
{
    if(i>j)
        return 0;
   if(i==j)
        return 1;
    if(a[i]==a[j])
   return 2+ arr(a,i+1,j-1);

    // kdnfgn
    int k = 1;
    return max(arr(a,i+1,j),arr(a,i,j-1));
}
int main()
{
    string A ;
    cin>>A;
    int K = arr(A,0,A.size()-1);
    cout<<K;
    return 0;
}
