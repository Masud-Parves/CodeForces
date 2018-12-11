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
const int maxn = (int)300000+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
int weight[maxn],n;
vector<int>graph[maxn];
vector<int>wt[maxn];
ll DP[maxn];
ll ans;

void dfs(int u, int p)
{
    int SZ=graph[u].size();
    for(int i=0 ; i<SZ ; i++)
    {
        int v=graph[u][i];
        if(v==p)
            continue;
        dfs(v,u);
    }
    ll max1=0LL,max2=0LL;

    for(int i=0; i<SZ ; i++)
    {
        int v=graph[u][i];
        if(v==p) continue;
        ll cur=DP[v]-wt[u][i];

        if(cur>max1){
            max2=max1;
            max1=cur;
        }else if(cur>max2){
            max2=cur;
        }
    }
    DP[u]=weight[u]+max1;
    ans=max(ans , weight[u]+max1+max2);
}


int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    cin>>n;
    for(int i=1 ; i<=n ; i++)
        cin>>weight[i];

    int u,v,w;
    for(int i=1 ; i<n ; i++)
    {
        cin>>u>>v>>w;
        graph[u].pb(v);
        graph[v].pb(u);
        wt[u].pb(w);
        wt[v].pb(w);
    }

    ans=0LL;
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}

