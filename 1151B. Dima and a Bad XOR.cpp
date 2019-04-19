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
const int MOD = (int)1000000007;
const int maxn = (int)2e5+5;

#define int long long

int solve(int n){


    vector < int > save;
    for(int i=0 ; i<=64 ; i++){
        int tmp =  (1LL << i);
        if(n-tmp<0){
            save.pb(n);
            break;
        }
        save.pb(tmp);
        n-=tmp;
    }

    int flag = 1LL;
    int odd = 0, even = 0;
    for(auto c: save){
        if(flag){
            odd += c;
            odd %= MOD;
        }
        else{
            even += c;
            even %= MOD;
        }
        flag ^= 1LL;
    }

    odd%=MOD;
    even%=MOD;
    int sum=0LL;

    sum= (odd*odd)%MOD;
    sum += (even*(even+1))%MOD;

    return sum%MOD;

}

int32_t main() {
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int l,r;

    cin >> l >> r;

    int res= solve(r)-solve(l-1);
    res%=MOD;
    if(res<0) res+=MOD;
    cout << res << endl;

    return 0;
}
