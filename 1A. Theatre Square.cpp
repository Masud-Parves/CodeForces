#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main()
{

    long long n,m,a;
    long long row=0,col=0;

    while(cin>>m>>n>>a)
    {
        if(n%a==0)
        {
            row=n/a;
        }
        else
        {
            row=n/a;
            row++;

        }
        if(m%a==0)
        {
            col=m/a;
        }
        else
        {
            col=m/a;
            col++;
        }
        cout<<row*col<<endl;

    }

    return 0;
}
