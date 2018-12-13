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
const int maxn = (int)2e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;

int n,k;
int arr[maxn],cnt[maxn];
map<int, int>mp;
vector< pair<int, int> >p;
bool cmp(pair< int, int >&p1, pair< int, int >&p2)
{
    return p1.ss>p2.ss;
}

bool isPossible(int m)
{
    int tot=0;
    for(auto it:p)
    {
        tot+=(it.ss/m);
    }
    return (tot>=k);
}
int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    cin>>n>>k;



    for(int i=1 ; i<=n ; i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    for(auto it:mp)
    {
        p.pb({it.ff,it.ss});
    }
    sort(p.begin(), p.end(), cmp);
//    for(auto it:p)
//    {
//        cout<<it.ff<<" "<<it.ss<<endl;
//    }

    int l=1,r=n,kotobar=0;

    while(l<=r)
    {
        int mid=(l+r)/2;
        if(isPossible(mid))
        {
            //Debug(mid);
            kotobar=max(kotobar, mid);
            l=mid+1;
        }
        else
            r=mid-1;
    }

    vector<int>ans;
    for(auto it:p)
    {
        int CASE=it.ss/kotobar;
        for(int i=1 ; i<=CASE ; i++)
        {
            if((int)ans.size()<k)
                ans.pb(it.ff);
        }
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    ans.clear();



    return 0;
}

