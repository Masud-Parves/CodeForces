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
const int maxn = (int)2e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;

vector< pair< string, int > > v;
char ans[200];
bool cmp(pair<string, int>&a, pair<string, int>&b)
{
    return a.ff.size()<b.ff.size();
}

int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int n;
    cin>>n;

    string s;
    for(int i=0 ; i<(2*n-2) ; i++)
    {
        cin>>s;
        v.pb(mp(s,i));
    }

    sort(all(v),cmp);

    string pref = v[0].ff, suff = v[1].ff;
    ans[v[0].ss] = 'P';
    ans[v[1].ss] = 'S';
    bool no=false;
    for(int i=3 ; i<(2*n-2) ; i+=2)
    {
        string a = v[i-1].ff,b = v[i].ff;
        if(pref+a.back()==a && b[0]+suff==b)
        {
            pref = a,suff = b;
            ans[v[i-1].ss] = 'P';
            ans[v[i].ss] = 'S';
        }
        else if(pref+b.back()==b && a[0]+suff==a)
        {
            pref = b,suff = a;
            ans[v[i-1].ss] = 'S';
            ans[v[i].ss] = 'P';
        }
        else
        {
            no=1;
            break;
        }
    }
    if(no)
    {
        pref = v[1].ff, suff = v[0].ff;
        ans[v[0].ss] = 'S';
        ans[v[1].ss] = 'P';
        bool no=false;
        for(int i=3 ; i<(2*n-2) ; i+=2)
        {
            string a = v[i-1].ff,b = v[i].ff;
            if(pref+a.back()==a && b[0]+suff==b)
            {
                pref = a,suff = b;
                ans[v[i-1].ss] = 'P';
                ans[v[i].ss] = 'S';
            }
            else if(pref+b.back()==b && a[0]+suff==a)
            {
                pref = b,suff = a;
                ans[v[i-1].ss] = 'S';
                ans[v[i].ss] = 'P';
            }

        }
    }

        ans[2*n-2]='\0';
        cout<<ans<<endl;


        return 0;
    }

