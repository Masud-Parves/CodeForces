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
#define int long long



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


typedef vector<int> vi;
typedef pair<int, int> pii;

vector<pii>fact;
void factorization(int n)
{
    for(int i=2 ; i<=n ; i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                n/=i;
                cnt++;
            }
            fact.pb({i,cnt});
        }
    }
}

int p2(int n)
{
    int x=1;
    while(x<n)
        x*=2;
    return x;
}

bool isP2(int n)
{
    if(n==1) return 0;
    int x=1;
    while(x<n)
        x*=2;
    return x==n;
}

int32_t main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    factorization(n);
//    for(int i=0; i<fact.size() ; i++){
//        cout<<fact[i].ff<<" "<<fact[i].ss<<endl;
//    }
    int mxf=0,ans=1;
    int cnt=0;
    for(auto a:fact)
    {
        mxf=max(mxf,a.ss);
    }


    if(!isP2(mxf)) cnt=1;
    mxf=p2(mxf);
    for(auto a:fact)
    {
        if(mxf!=a.ss) cnt=1;
        ans*=a.ff;
    }

    if(mxf==1){
        cout<<ans<<" "<<0<<endl;
        return 0;
    }

    while(mxf>1){
        cnt++;
        mxf/=2;
    }

    cout<<ans<<" "<<cnt<<endl;
    return 0;
}
