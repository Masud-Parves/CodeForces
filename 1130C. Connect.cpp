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
int visited[55][55];
int n,r1,r2,c1,c2,ok;
char s[55][55];

vector<pii>v[3];
void dfs(int t, int r,int c){
    if(t==0 && r==r2 && c==c2) ok=1;
    visited[r][c]=1;
    v[t].pb({r,c});
    f0(i,4){

        int nr=r+fx[i];
        int nc=c+fy[i];

        if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc] && s[nr][nc]=='0'){
//             cout << r << " " << c << " => ";
//             cout << nr << " " << nc << "\n";
            dfs(t, nr, nc);
        }
    }

}


int main() {
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    cin>>n;

    cin>>r1>>c1;
    cin>>r2>>c2;
    r1--,c1--;
    r2--,c2--;

    for(int i=0; i<n ; i++){
        cin>>s[i];
    }

    ok=0;

    dfs(0,r1,c1);
    dfs(1,r2,c2);

    if(ok==1){
        cout<<"0"<<endl;
        return 0;
    }
    ll ans=LLONG_MAX;
    for(auto p1:v[0]){
            //cout << p1.ff << " " << p1.ss << "\n";
        for(auto p2:v[1]){
                        //cout << p2.ff << " " << p2.ss << "\n";

            int x1,x2,y1,y2;
            x1=p1.ff,y1=p1.ss;
            x2=p2.ff,y2=p2.ss;

            ans=min(ans,((x2-x1)*1LL*(x2-x1))+(y2-y1)*1LL*(y2-y1));
        }
    }

    cout<<ans<<endl;


    return 0;
}

