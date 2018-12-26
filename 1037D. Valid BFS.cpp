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

int n,arr[maxn];
vi graph[maxn];
bool visited[maxn];
set<int> lev[maxn];

void dfs(int u, int p)
{
    for(int i=0 ; i<(int)graph[u].size() ; i++)
    {
        int v=graph[u][i];
        if(v!=p)
        {
            lev[u].insert(v);
            dfs(v,u);
        }

    }
}

void bfs(int src)
{
    queue<int>Q;
    Q.push(src);
    int i=2;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int j=0 ; j<lev[u].size() ; j++)
        {
            if(lev[u].find(arr[i])==lev[u].end())
            {
                cout<<"No"<<endl;
                return;
            }
            Q.push(arr[i]);
            i++;
        }
    }
    cout<<"Yes"<<endl;
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
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    f1(i,n) cin>>arr[i];


    if(arr[1]!=1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    dfs(1,0);

    bfs(1);
    return 0;
}

