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
int parent[maxn];


vector<pair < ll , pii > > edge;
ll a[maxn];

int Find(int node)
{
    if(parent[node]==node)
        return node;
    return parent[node]=Find(parent[node]);
}

void make_union(int u, int v){
    int pu = Find(u);
    int pv = Find(v);
    if(pu==pv) return;
    if(a[pu]<a[pv]){
        parent[pv] = pu;
        a[pv] = a[pu];
    }
    else
    {
        parent[pu] = pv;
        a[pu] = a[pv];
    }
}

int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n,m;
    cin>>n>>m;

    for(int i=1 ; i<=n ; i++)
    {
        cin>>a[i];
    }

    for(int i=1 ; i<=m ; i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        edge.pb({w,{u,v}});
    }

    int root=1;
    ll r_weight=a[1];

    for(int i=1 ; i<=n ; i++)
    {
        if(r_weight>a[i])
        {
            root=i;
            r_weight=a[i];
        }
    }

    for(int i=1 ; i<=n ; i++)
    {
        if(i!=root)
        {
            edge.pb({r_weight+a[i],{root,i}});
        }
    }
//    for(auto v:edge)
//    {
//        cout<<v.ff<<  " " <<v.ss.ff<< " " <<v.ss.ss<<endl;
//    }


    sort(all(edge));

    for(int i=1 ; i<=n ; i++)
    {
        parent[i]=i;
    }
    int siz=SZ(edge);
    ll mstValue=0LL;
    for(int i=0 ; i<siz ; i++)
    {
        int uPr=Find(edge[i].second.first);
        int vPr=Find(edge[i].second.second);
        if(uPr!=vPr)
        {
            mstValue+=edge[i].first;
            make_union(uPr,vPr);
        }
    }

    cout<<mstValue<<endl;






    return 0;
}

