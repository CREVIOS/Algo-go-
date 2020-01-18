#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    int n;
    cin>>n;
    if(n>3999||n<1) {cout<<"Invaild"<<endl;
    return 0;}
    int i =0;
    int k = 0;
    vector<string>p;
    while(n>0)
    {
        if(n-value[i]>=0)
        {
            p.push_back(a[i]);
            k++;
            n -= value[i];
        }
        else{
            i++;
        }
    }
    for(int i=0;i<k;i++)
    {
        cout<<p[i];
    }
    return 0;
}
