#include<bits/stdc++.h>

using namespace std;

/*

        Bismillahir Rahmanir Rahim
        Problem :
        Problem Link :
        Topics :
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/

#define ff first
#define ss second
#define pb push_back
#define SZ(a)           (int)a.size()
#define all(a)  a.begin(), a.end()
#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define Debug(x)            cout<<#x " = "<<(x)<<endl


const int maxn = (int)2e5+5;

typedef long long ll;

int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin>>n>>s;

    int len = SZ(s);

    string out="";
    out+=s[0];
    for(int i=1,j=1 ; i<len ; i++)
    {
        out+=s[i];
        i+=j;
        j++;
    }
    cout<<out<<endl;


    return 0;
}

