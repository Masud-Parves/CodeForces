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
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
 
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
 
#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define TEST_CASE(t) for(int zz=1 ; zz<=t ; zz++)
#define PRINT_CASE printf("Case %d: ",zz)
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
 
vector < ll > v;
int main() {
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    for(int i=1 ; ; i++){
        ll val = (i*(i+1))/2;
        if(val>MOD) break;
        v.pb(val);
    }
 
    int t;
    cin >> t;
 
    vector < ll >::iterator lo,hi;
    while(t--){
        ll n;
        cin >> n;
 
//        if(n==1) {
//            cout <<"1337" << endl;
//            continue;
//        }
//        else if(n==2){
//            cout << "11337" << endl;
//            continue;
//        }
 
        string s="133",t="";
        bool f=0;
        while(n){
            lo = lower_bound(v.begin(),v.end(), n);
            int _low = lo - v.begin();
 
            if(v[_low]!=n){
                _low-=1;
            }
            //cout << _low << endl;
 
            if(!f){
                for(int i=0 ; i<_low ; i++) t+="3";
                f=1;
                s+=t;
            }else {
                int point=SZ(s)-(_low+2);
                s.insert(point, "1");
            }
            n-=v[_low];
        }
 
        s+="7";
        //ll ans = _give(n);
        cout << s << endl;
    }
 
    return 0;
}
 
