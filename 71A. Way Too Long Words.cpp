#include<bits/stdc++.h>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    string inp;
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>inp;
        int len=inp.size();
        if(len>10)
        {
            cout<<inp[0]<<len-2<<inp[len-1]<<endl;
        }
        else
        {
            cout<<inp<<endl;
        }

    }

    return 0;