#include<bits/stdc++.h>
using namespace std;


long long int maxxor(long long int l,long long  int r)
{
    long long int a = l ^ r;
   long long  int max = 0;
    while (a != 0)
    {
        max |= a;
        a = a >> 1;
    }
    return max;
}
int main()
{
    long long int l , r ;
    scanf("%lld%lld",&l,&r);
 long long int p = maxxor(l,r);
 printf("%lld",p);
 return 0;
}
