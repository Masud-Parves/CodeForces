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
const int maxn = (int)3e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
ll ans[maxn],BIT[maxn],level[maxn];
vector < int > graph[maxn];
vector < pair<int, int> > gVal[maxn];
int n;

void update(int pos, int val)
{
    while(pos<=n)
    {
        BIT[pos]+=val;
        pos +=(pos & -pos);
    }
}

ll query(int pos)
{
    ll sum = 0;
    while(pos>0)
    {
        sum+=BIT[pos];
        pos -=(pos&-pos);
    }
    return sum;
}

void dfs(int u, int p=0)
{

    level[u]=level[p]+1;

    for(auto it:gVal[u])
    {
        auto x=it;
        update(level[u],x.ss);
        update(level[u]+x.ff+1,-x.ss);
    }

    ans[u]=query(level[u]);
    //Debug(ans[u]);

    for(int v:graph[u])
    {
        if(v!=p)
        {
            dfs(v,u);
        }
    }
    for(auto it:gVal[u])
    {
        auto x=it;
        update(level[u],-x.ss);
        update(level[u]+x.ff+1,+x.ss);
    }
}


int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    cin>>n;

    f1(i,n-1)
    {
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    int q;
    cin>>q;
    f1(i,q)
    {
        int v,d,x;
        cin>>v>>d>>x;
        //d=d+1;
        gVal[v].pb(mp(min(d,n),x));
    }

    dfs(1);

    for(int i=1 ; i<=n ; i++){
        cout<<ans[i]<<" ";
    }


    return 0;
}

