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



int main()
{
    //CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;

    TEST_CASE(t)
    {
        ll row,col,tot=0;
        ll white=0,black=0;
        cin>>row>>col;
        tot=row*col;

        white=(tot+1)/2;
        black=(tot/2);
        ll x1,y1,x2,y2,r,c,t;
        cin>>x1>>y1>>x2>>y2;
        r=(x2-x1)+1;
        c=(y2-y1)+1;
        t=r*c;

        ll wx,by;
        if((x1+y1)%2==0)
        {
            wx=(t+1)/2;
            by=(t/2);
        }
        else
        {
            wx=(t/2);
            by=(t+1)/2;
        }

        white+=by;
        black-=by;

        ll a1,b1,a2,b2,ra,cb,ta;
        cin>>a1>>b1>>a2>>b2;
        ra=(a2-a1)+1;
        cb=(b2-b1)+1;
        ta=ra*cb;
        ll wa,bb;
        if((a1+b1)%2==0)
        {
            wa=(ta+1)/2;
            bb=(ta/2);
        }
        else
        {
            wa=(ta/2);
            bb=(ta+1)/2;
        }

        white-=wa;
        black+=wa;

        ll p1,p2,q1,q2;
        p1=max(x1,a1);
        q1=max(y1,b1);
        p2=min(x2,a2);
        q2=min(y2,b2);

        ll fr,fc,ft=0,fw,fb;
        if(p1<=p2 && q1<=q2)
        {

            fr=(p2-p1)+1;
            fc=(q2-q1)+1;
            ft=fr*fc;
            if((p1+q1)%2==0)
            {
                fw=(ft+1)/2;
                fb=(ft/2);
            }
            else
            {
                fw=(ft/2);
                fb=(ft+1)/2;
            }
            black += fb;
            white -= fb;

        }
        cout<<white << " " << black<<endl;
    }
    return 0;
}

