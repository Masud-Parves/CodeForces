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
#define all(a)  a.begin(), a.end()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("d",&a,&b)
#define sfff(a,b,c)     scanf("d%d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define mx  550
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define NOT_VISITED 0
#define IS_VISITED 1



int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};


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


vector < int > v;

int main()
{
    //CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin>>n;

    string s;
    cin>>s;
    //cout<<n<<s;

    int len=s.size();
    int cntG=0,cntS=0;
    v.pb(0);
    for(int i=0 ; i<len ; i++){
        if(s[i]=='G') cntG++;
        else cntS++;
    }
    int ans=0,c=0;
    if(cntG==n) cout<<n<<endl;
    else if(cntS==n) cout<<0<<endl;
    else {

        for(int i=0 ; i<len ; i++){
            if(s[i]=='G'){
                c++;
            }else {
                if(c>0){
                    v.pb(c);
                    c=0;
                }
                v.pb(0);
            }
        }
        if(c>0) v.pb(c);
        v.pb(0);

        for(int i=1 ; i+1<v.size() ; i++){
                if(v[i]==0 && (v[i+1]!=0 || v[i-1]!=0)){
                    int x=v[i+1]+v[i-1];
                    if(cntG>x){
                        ans=max(ans,x+1);
                    }else {
                        ans=max(ans,x);
                    }
                }
        }
        cout<<ans<<endl;
        v.clear();
    }
    return 0;
}

