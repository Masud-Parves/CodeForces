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
const int maxn = (int)100000+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;

ll arr[maxn];

int main()
{
    //CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n,k;
    cin>>n>>k;

    memset(arr , 0 ,sizeof arr );
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];

    vector < int > v;
    sort(arr, arr+n);
    v.pb(arr[0]);
    for(int i=1 ; i<n ; i++)
    {
        if(arr[i]==arr[i-1])
            continue;
        else
            v.pb(arr[i]);
    }
//    for(auto a: v) cout<<" "<<a<<endl;

    int temp=0;
    ll sum=0,pre=0;

    if(k>v.size())
    {
        for(int i=0 ; i<v.size() ; i++)
        {
            cout<<v[i]-sum<<endl;
            pre=v[i]-sum;
            sum+=pre;
            temp++;

        }
        int rem=k-v.size();
        for(int i=1 ; i<=rem ; i++)
            cout<<0<<endl;
    }
    else
    {
        for(int i=0 ; i<v.size() ; i++)
        {
            cout<<v[i]-sum<<endl;
            pre=v[i]-sum;
            sum+=pre;
            temp++;
            if(temp==k) break;
        }
    }
    v.clear();

    return 0;
}

