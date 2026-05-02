#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
struct Info
{
    int cnt;
    Info() : cnt(0){};
    Info(int value) :cnt(value) {};
    Info operator+(const Info &other) const
    {
        return Info(cnt+other.cnt);
    }
};
struct ValueSegTree
{
    int n;
    vector<int> tag;
    vector<Info> info;
    ValueSegTree(int _n) : n(_n), tag(4 * _n), info(4 * n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    // 区间查询[x,y)
    Info query(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
            return {};
        if (l >= x && r <= y)
        {
            return info[p];
        }
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
    };
    int query(int x, int y)
    {
        return query(1, 0, n, x, y).cnt;
    };

    int rank(int val){
        return query(0,val)+1;
    }
    
    // 单点修改:在x上加v
    void modify(int p, int l, int r, int x, int v)
    {
        if (r - l == 1)
        {
            info[p].cnt += v;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(p << 1, l, mid, x, v);
        }
        else
        {
            modify(p << 1 | 1, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int x, int v)
    {
        modify(1, 0, n, x, v);
    }

    int query_kth(int p,int l,int r,int k){
        if(r-l==1){
            return l;
        }
        int mid=l+r>>1;
        int l_cnt=info[p<<1].cnt;
        if(k<=l_cnt)
            return query_kth(p<<1,l,mid,k);
        else 
            return query_kth(p<<1|1,mid,r,k-l_cnt);
    }
    int query_kth(int k){
        return query_kth(1,0,n,k);
    }
};
void solve()
{
    int n;
    cin>>n;
    vector<array<int,2>>q(n);
    vector<int>b;
    for(auto &[op,v]:q){
        cin>>op>>v;
        b.push_back(v);
    }
    ranges::sort(b);
    b.erase(unique(b.begin(),b.end()),b.end());
    auto get_idx=[&](int x){
        return ranges::lower_bound(b,x)-b.begin()+1;
    };
    ValueSegTree T((int)b.size()+1);
    
    for(auto [op,v]:q){
        int idx=get_idx(v);
        if(op==1){
            T.modify(idx,1);
        }
        else if(op==2){
            T.modify(idx,-1);
        }
        else if(op==3){
            cout<<T.rank(idx)<<'\n';
        }
        else if(op==4){
            cout<<b[T.query_kth(v)-1]<<'\n';
        }
        else if(op==5){
            cout<<b[T.query_kth(T.rank(idx)-1)-1]<<'\n';
        }
        else{
            cout<<b[T.query_kth(T.query(0,idx+1)+1)-1]<<'\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}