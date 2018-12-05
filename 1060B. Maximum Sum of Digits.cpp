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

/*It is required to find the maximum of the sum of the numbers on each of the bits of a number n that can be summed to n. .
Like this question, what we have to do is to add more than 9. . First find a power of 10 that is no greater than n, and then subtract one. For example: 101, no more than its number is 100, 100-1 = 99. This has two 9s. The idea is this.
The code is as follows: */

ll sumOfDigits(ll n)
{

    ll remainder=0,sum=0;
    while (n != 0)
    {
        remainder = n % 10;
        sum       = sum + remainder;
        n         = n / 10;
    }
    return sum;

}

int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n;
    cin>>n;
    ll pow=1,num9=0,rem=0,temp=1;
    if(n<=18)
    {
        cout<<n<<endl;
        return 0;
    }
    while(true)
    {
        temp*=10;
        if(temp*10>=n)
        {
            break;
        }
    }
    num9=temp-1;
    rem=n-num9;
    ll s1=sumOfDigits(num9);
    ll s2=sumOfDigits(rem);
    cout<<s1+s2<<endl;

    return 0;
}

