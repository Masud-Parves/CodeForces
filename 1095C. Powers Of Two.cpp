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

#define int long long

vector < int > num,ans;
int powerValue(int n){
    int res = 1;
    while(1){
        if(res*2 > n){
            return res;
        }
        res *= 2;
    }
}

int32_t main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n,k;
    cin>>n>>k;

    if(k>n) {
        cout<<"NO"<<endl;
        return 0;
    }
    int m=k,mm=n;
    if(n%2!=0){
        n--;
        k--;
    }
    int baki=n-k;

    for(int i=0 ; i<k ; i++)
    {
        int tmp=1;
        int a=powerValue(tmp+baki);
        //Debug(a);
        baki-=(a-tmp);
        //Debug(baki);
        num.pb(a);
    }

    if(baki==0)
    {
        cout<<"YES"<<endl;
        if(mm%2==1) cout<<1<< " ";
        for(int i=0 ; i<num.size() ; i++)
            cout<<num[i]<<" ";
    }
    else {
        cout<<"NO"<<endl;
    }

    return 0;
}
