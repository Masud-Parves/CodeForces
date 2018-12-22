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
#define R 1
#define B 2



int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N  (1<<pos);}
//int Reset(int N,int pos){return N= N & ~(1<<pos);}
//bool Check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/


const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)998244353;
const int maxn = (int)3e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
vector< int > graph[maxn];
int color[maxn];
bool f;
int p2[maxn];
int cnt[5];
void dfs(int u, int p)
{
    color[u]=p;
    cnt[p]++;

    for(auto v:graph[u])
    {
        if(color[v]==-1) dfs(v,1-p);
        if(color[u] ^ color[v]==0)
        {
            f=false;
        }
    }

}

int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    p2[0]=1;
    f1(i,maxn){
        p2[i]=(2*p2[i-1])%MOD;
    }


    int t;
    cin>>t;

    TEST_CASE(t)
    {
        int n,m;
        cin>>n>>m;


        for(int i=0 ; i<=n ; i++) {
            graph[i].clear();
            color[i]=-1;
        }
        f1(i,m)
        {
            int u,v;
            cin>>u>>v;

            graph[u].pb(v);
            graph[v].pb(u);
        }

        f=true;
        ll res=1;
        for(int i=1 ; i<=n ; i++)
        {
            if(color[i]!=-1) continue;

            cnt[0]=cnt[1]=0;
            dfs(i,0);

            if(f==false){
                cout<<"0"<<endl;
                break;
            }

            ll cur=(p2[cnt[0]]+p2[cnt[1]])%MOD;
            //Debug(cur);

            res=(res*1LL*cur)%MOD;

        }
        if(f==true){
            cout<<res<<endl;
        }

    }




    return 0;
}

