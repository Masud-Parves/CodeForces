#include<bits/stdc++.h>

using namespace std;

#define MX 1000005
int n;
string s;

struct node {
    int L,R,M;
} tree[4*MX];

node marge(node &a, node &b)
{
    node res;
    int mini=min(a.L,b.R);
    res.L=a.L+b.L-mini;
    res.R=a.R+b.R-mini;
    res.M=a.M+b.M+mini;
    return res;
}

void buildTree(int node, int b, int e) {
    if(b==e) {
        tree[node].L=0;
        tree[node].R=0;
        tree[node].M=0;
        if(s[b]=='(') {
            tree[node].L=1;
        } else {
            tree[node].R=1;
        }
        return;
    }
    int mid=(b+e)/2,left=node*2+1,right=left+1;
    buildTree(left,b,mid);
    buildTree(right,mid+1, e);
    tree[node]=marge(tree[left],tree[right]);
}

void update(int node, int b, int e, int pos) {
    if(pos<b || pos>e)
        return ;
    if(b==e) {
        swap(tree[node].L,tree[node].R);
        return;
    }
    int mid=(b+e)/2,left=node*2+1,right=left+1;
    update(left,b,mid,pos);
    update(right,mid+1,e, pos);
    tree[node]=marge(tree[left],tree[right]);
}

int main() {

    cin>>n;
    cin>>s;
    buildTree(0,0,n-1);

    if(n%2==1) {
        cout<<0<<endl;
        return 0;
    }
    int ans=0;
    for(int i=0 ; i<n ; i++) {
        update(0,0,n-1,i);
        ans+= (tree[0].M==(n/2));
        update(0,0,n-1,i);
    }

    cout<<ans<<endl;

    return 0;
}

