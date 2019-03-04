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
#define sfff(a,b,c)     scanf("%d% d %d",&a,&b,&c)

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
const int maxn = (int)1e5+5;
const int k = (int)512;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
ll arr[maxn];
ll ans[maxn];
int cnt[maxn];
int L=0,R=-1,n,Q;
ll SUM=0;

struct query {
    int l,r,id;
}q[maxn];

bool cmp(query &a, query &b){

    int block_a=a.l/k,block_b=b.l/k;

    if(block_a==block_b) return a.r<b.r;
    return a.l<b.l;
}


void Add(int x){
    x=arr[x];
    if(x>n)return;
    if(cnt[x]==x) SUM--;
    cnt[x]++;
    if(cnt[x]==x) SUM++;
}

void Remove(int x){
    x=arr[x];
    if(x>n)return;
    if(cnt[x]==x) SUM--;
    cnt[x]--;
    if(cnt[x]==x) SUM++;

}


int main() {
    //CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    sff(n,Q);


    f0(i,n) sf(arr[i]);


    for(int i=0; i<Q ; i++){
        sff(q[i].l,q[i].r);
        q[i].l--;
        q[i].r--;
        q[i].id=i;
    }


    sort(q,q+Q,cmp);

    for(int i=0 ; i<Q ;i++){
        while(L > q[i].l) Add(--L);
        while(R < q[i].r) Add(++R);
        while(L < q[i].l) Remove(L++);
        while(R > q[i].r) Remove(R--);

        ans[q[i].id]=SUM;
    }

    for(int i=0 ; i<Q ; i++){
        printf("%I64d\n", ans[i]);
    }
    return 0;
}
