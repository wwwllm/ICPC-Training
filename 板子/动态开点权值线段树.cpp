#include<bits/stdc++.h>
using namespace std;

struct SegTree{
    struct Node{
        int l;
        int r;
        int cnt;
    };
    int root;
    int tot;
    int n;
    vector<Node>info;
    SegTree(int n,int cnt):n(n),root(0),tot(0){
        info.assign(cnt,{0,0,0});
        tot=0;
        root=0;
    }
    void pull(int p){
        int l=info[p].l,r=info[p].r;
        info[p].cnt=info[l].cnt+info[r].cnt;
    }

    void modify(int &p,int l,int r,int x,int v){
        if(!p)p=++tot;
        if(r-l==1){
            info[p].cnt+=v;
            return ;
        }
        int mid=l+r>>1;
        if(x<mid){
            modify(info[p].l,l,mid,x,v);
        }
        else{
            modify(info[p].r,mid,r,x,v);
        }
        pull(p);
    }
    void modify(int x,int v){
        return modify(root,0,n,x,v);
    }

    int query(int p,int l,int r,int x,int y){
        if(!p||l>=y||r<=x){
            return 0;
        }
        if(l>=x&&r<=y){
            return info[p].cnt;
        }
        int mid=l+r>>1;
        return query(info[p].l,l,mid,x,y)+query(info[p].r,mid,r,x,y);
    }
    int query(int x,int y){
        return query(root,0,n,x,y);
    }
    int rank(int val){
        return query(0,val)+1;
    }
    int kth(int p,int l,int r,int k){
        if(r-l==1)
            return l;
        int mid=l+r>>1;
        int cntl=info[info[p].l].cnt;
        int cntr=info[info[p].r].cnt;
        if(k<=cntl){
            return kth(info[p].l,l,mid,k);
        }
        else {
            return kth(info[p].r,mid,r,k-cntl);
        }
    }
    int kth(int k){
        return kth(root,0,n,k);
    }
};
const int inf=1e7;
void solve(){
    int n;
    cin>>n;
    SegTree T(2*inf+10,n*40);
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            int val;
            cin>>val;
            val+=inf;
            T.modify(val,1);
        }
        else if(op==2){
            int val;
            cin>>val;
            val+=inf;
            T.modify(val,-1);
        }
        else if(op==3){
            int val;
            cin>>val;
            val+=inf;
            cout<<T.rank(val)<<'\n';
        }
        else if(op==4){
            int k;
            cin>>k;
            cout<<T.kth(k)-inf<<'\n';
        }
        else if(op==5){
            int val;
            cin>>val;
            val+=inf;
            cout<<T.kth(T.rank(val)-1)-inf<<'\n';
        }
        else if(op==6){
            int val;
            cin>>val;
            val+=inf;
            cout<<T.kth(T.query(0,val+1)+1)-inf<<'\n';
        }
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}