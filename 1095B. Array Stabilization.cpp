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
int a[maxn];
int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    for(int i=1; i<=n ; i++)
    {
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    int ans,x,b;
    x=a[n-1]-a[1];
    b=a[n]-a[2];


    cout<<min(x,b)<<endl;

    return 0;
}

