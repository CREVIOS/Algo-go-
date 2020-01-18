
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    vector<int>p,m;
    int n , r;
    cin>>n>>r;
    int l = n - r ;
    if(l>r)
    {
        for(int i = l+1;i<=n;i++)
        {
            p.push_back(i);
        }
        for(int j= 1;j<=r;j++)
        {
            m.push_back(j);
        }
    }
    else{
        for(int i = r+1;i<=n;i++)
        {
            p.push_back(i);

        }
         for(int j= 1;j<=l;j++)
        {
            m.push_back(j);
        }
    }
    for(int i = 0;i<p.size();i++)
    {
        int b ;
        for(int j = 0;j<m.size();j++)
        {
            b = __gcd(p[i],m[j]);
            m[j] = m[j] / b;
            p[i] = p[i] / b;
        }
    }
    /* for(int i = 0;i<p.size();i++)
    {

        for(int j = 0;j<m.size();j++)
        {
           if(p[i]%m[i]==0)
           {
               p[i]= p[i] / m[i];
               m[i] = m[i] / m[i];
           }
        }
    }*/
     for(int i = 0;i<p.size();i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
     for(int i = 0;i<m.size();i++)
    {
        cout<<m[i]<<" ";
    }

}
