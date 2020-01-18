#include <bits/stdc++.h>
using namespace std;


int main()
{
    int a[10000];
int n ;
    cin>>n;
    for(int i = 0; i< n-2 ; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long int sumi = 0;
    long long int k = (n*(n+1))/2;
    for(int i= 0; i< n ; i++)
    {
        sumi += a[i];
    }
    long long int s = k - sumi ;
long long int l ;

    l = (int)s/2;
int arxor = 0;
int arixor = 0;
int nxor = 0;
    int nixor = 0;
    for(int j = 1 ; j <=l;j++)
    {
        nxor ^= j;
    }
     for(int j = l+1 ; j <=n;j++)
    {
        nixor ^= j;
    }
    for(int  j = 0; j <=n ;j++)
    {
        if(a[j]<=l) {arxor^=a[j];}
        else{
            arixor^=a[j];
        }
    }
 int t = arxor ^ nxor;
 int  x = arixor^nixor;
 cout<<x<<" "<<t;


return 0;

}
