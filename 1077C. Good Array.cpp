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
#define mp make_pair
#define SZ(a)           (int)a.size()
#define all(a)  a.begin(), a.end()
#define allr(a)  a.rbegin(), a.rend()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("d",&a,&b)
#define sfff(a,b,c)     scanf("d%d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define Debug(x)            cout<<#x " = "<<(x)<<endl
#define NOT_VISITED 0
#define IS_VISITED 1
#define WHITE 0
#define GRAY 1
#define BLACK 2



int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N  (1<<pos);}
//int Reset(int N,int pos){return N= N & ~(1<<pos);}
//bool Check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/


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

int lm[maxn],rm[maxn],arr[maxn];

int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin>>n;

    int l=0,r=0;
    ll sum=0;
    arr[0]=0;
    for(int i=1 ; i<=n ; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        l=max(l,arr[i]);
        lm[i]=l;
    }
    for(int i=n ; i>=1 ; i--)
    {
        r=max(r,arr[i]);
        rm[i]=r;
    }
    //for(int i=1 ; i<=n ; i++) cout<<lm[i]<<endl;

    vector<int>pos;

    for(int i=1 ; i<=n ; i++)
    {
        int SecondMAX=max(lm[i-1],rm[i+1]);
        if(sum-arr[i]==2*SecondMAX)
        {
            pos.pb(i);
            //cout<<i<<endl;
        }
    }
    cout<<pos.size()<<endl;
    for(int i=0 ; i<pos.size() ; i++)
    {
        cout<<pos[i]<<" ";
    }
    pos.clear();

    return 0;
}
