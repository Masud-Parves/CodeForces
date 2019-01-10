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

int arr[maxn];



int32_t main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin>>n;

    f1(i,n) cin>>arr[i];

    sort(arr+1, arr+n+1);

    int ans=0LL;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=31 ; j++){

            int res= (int)(1<<j)-arr[i];
            ans+=upper_bound(arr+1+i, arr+1+n , res) - lower_bound(arr+i+1, arr+1+n , res);
        }
    }
    cout<<ans<<endl;


    return 0;
}

/*

Seeing this kind of data in the future is big and you have to find out how many pairs you want to think about.
The 2nd power of 31 can probably include the sum of the two largest numbers, so starting from the first number,
from 1 of 2 The ~31 power is enumerated in turn, and it is enough to find out how many points are satisfied.
How many numbers to use for upper_bound - lower_bound will do.

*/

