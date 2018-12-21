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

struct edge
{
    int u,v,w;
};

vector<edge>graph,output;
int parent[maxn],mstValue=0;
int n,m,k;
bool sp[maxn];

bool compare(edge a, edge b)
{
    return a.w<b.w;
}

int Find(int node)
{
    if(parent[node]==node)
        return node;
    return parent[node]=Find(parent[node]);
}
void initPar(int node)
{
    for(int i=1 ; i<=node ; i++)
    {
        parent[i]=i;
    }
}
void minimumSpaningTree(int node)
{
    sort(graph.begin(), graph.end(), compare);

    initPar(node); /// parent initialization.
    int cnt=0;
    for(int i=0 ; i<(int)graph.size() ; i++)
    {
        int uPr=Find(graph[i].u);
        int vPr=Find(graph[i].v);
        int weight=graph[i].w;
        if(uPr!=vPr)
        {
//            if(cnt==n-1)
//                break;
            if(sp[uPr] && sp[vPr])
            {
                mstValue=max(mstValue, weight);
            }
            parent[uPr]=vPr;
//            output.pb(graph[i]);
            if(!sp[uPr] && !sp[vPr]) continue;
            if(sp[uPr]){
                sp[vPr]=true;
            }else {
                sp[uPr]=true;
            }

            cnt++;
        }
    }

}

int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>n>>m>>k;

    graph.clear();
    int x;
    edge in;
    f1(i,k)
    {
        cin>>x;
        sp[x]=true;
    }
    f1(i,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        in.u=u;
        in.v=v;
        in.w=w;
        graph.pb(in);
    }

    minimumSpaningTree(n);
    f1(i,k) cout<<mstValue<<" ";
    return 0;
}

