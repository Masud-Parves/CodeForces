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
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)

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
const int maxn = (int)1e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
vector<int>sub[maxn];
vector<int>cSum[maxn];
int mapping[maxn];
int n,m;
pair < int, int > lst[maxn];



int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>n>>m;
    int s,r;
    int cnt=0;
    for(int i=1 ; i<=n ; i++)
    {
        cin>>s>>r;
        if(mapping[s]==0) mapping[s]=++cnt;
        sub[mapping[s]].pb(r);
    }
    //Debug(cnt);

    int maxSize=0;

    for(int i=1 ; i<=cnt ; i++)
    {

        sort(all(sub[i]), greater<int>());
        int SZ=sub[i].size(),t=0;

        maxSize=max(maxSize,SZ);
        for(int j=0 ; j<SZ ; j++)
        {
            t+=sub[i][j];
            cSum[i].pb(t);
        }
        lst[i]=mp(SZ, i);
    }

    sort(lst+1, lst+cnt+1);
    reverse(lst+1, lst+cnt+1);

    ll ans=0;
    for(int l=1 ; l<=maxSize ; l++)
    {
        ll current=0;
        for(int i=1 ; i<=cnt ; i++)
        {
            int a=lst[i].ss;
            if(lst[i].first<l)
                break;
            if(cSum[a][l-1]>0)
                current+=cSum[a][l-1];
        }
        ans=max(ans,current);
    }
    cout<<ans<<endl;

    return 0;
}

