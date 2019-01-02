#include<bits/stdc++.h>

using namespace std;

#define MX 1000005
int n;
string s;

struct node {
    int L,R;
} tree[4*MX];

void buildTree(int node, int b, int e) {
    if(b==e) {
        tree[node].L=0;
        tree[node].R=0;
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
    tree[node].L=max(0, tree[left].L-tree[right].R)+tree[right].L;
    tree[node].R=max(0, tree[right].R-tree[left].L)+tree[left].R;
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
    tree[node].L=max(0, tree[left].L-tree[right].R)+tree[right].L;
    tree[node].R=max(0, tree[right].R-tree[left].L)+tree[left].R;
}

int main() {

    cin>>n;
    cin>>s;
    buildTree(0,0,n-1);

    if(n%2==1){
        cout<<0<<endl;
        return 0;
    }

    int ans=0;
    for(int i=0 ; i<n ; i++) {
        update(0,0,n-1,i);
        ans+= (tree[0].L+tree[0].R==0);
        update(0,0,n-1,i);
    }

    cout<<ans<<endl;

    return 0;
}
