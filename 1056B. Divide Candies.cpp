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


#define pb push_back
#define all(a)  a.begin(), a.end()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define mx  550
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define NOT_VISITED 0
#define IS_VISITED 1



int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};


const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;


map< int , int >mp;
int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n,m;

    cin>>n>>m;

    int nBlock=n/m;


    for(int i=1 ; i<=m ; i++){
        ll p=(i*i)%m;
        mp[p]+=nBlock;
    }

    int outBlock=(n)%m;
    for(int i=1 ;i<=outBlock ; i++){
        ll p=(i*i)%m;
        mp[p]++;
    }
//    for(auto a:mp){
//        cout<<"mp :" <<a.first <<" "<<a.second<<endl;
//    }

    ll sum=0;
    for(auto a: mp){
        ll idx1=a.first;
        //cout<<idx1<<endl;
        ll val1=a.second;
        //cout<<val1<<endl;

        ll nxt=m-idx1;
        nxt%=m;
        ll val2=mp[nxt];
        sum+=val1*val2;

    }
    cout<<sum<<endl;
    return 0;
}

