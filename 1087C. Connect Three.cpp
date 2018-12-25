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
int x1,x2,x3,y1,y2,y3;
set<pii>ans[3];
int index;
int sz=10000000;
void path(int x1, int y1, int x2, int y2, int idx)
{
    while((x1!=x2) || (y1!=y2))
    {
        ans[idx].insert({x1,y1});
        if(x1!=x2)
        {
            if(x1<x2)
                x1++;
            else
                x1--;
        }
        else
        {
            if(y1<y2)
                y1++;
            else
                y1--;
        }
    }
    ans[idx].insert({x2,y2});
}

int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;

    ///consider path a->b->c;
    path(x1,y1,x2,y2,0);
    path(x1,y1,x3,y3,0);

    if(ans[0].size()<sz)
    {
        sz=ans[0].size();
        index=0;
    }


    ///consider path b->a->c;

    path(x2,y2,x1,y1,1);
    path(x2,y2,x3,y3,1);

    if(ans[1].size()<sz)
    {
        sz=ans[1].size();
        index=1;
    }
    ///consider path c->b->a
    path(x3,y3,x2,y2,2);
    path(x3,y3,x1,y1,2);


    if(ans[2].size()<sz)
    {
        sz=ans[2].size();
        index=2;
    }

    cout<<ans[index].size()<<endl;

    for(auto a:ans[index])
    {
        cout<<a.ff<<" "<<a.ss<<endl;
    }

    return 0;
}

