#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6;
int len;
struct Q
{
    int l,r,idx,bl;
    bool operator <(const Q &q)const{
		if (bl != q.bl) return bl < q.bl;
        return (bl&1) ? (r < q.r) : (r > q.r);
	}
};
vector<int>cnt(N+1);
int res=0;
void solve(){
    int n;
    cin>>n;
    len=max(1LL,(int)(n/sqrt(n)));
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    vector<Q>qu(q);
    int p=0;
    for(auto &[l,r,id,bl]:qu){
        cin>>l>>r;
        id=p++;
        bl=l/len;
    }
    auto add=[&](int x){
        if(cnt[a[x]]==0)res++;
        cnt[a[x]]++;
    };
    auto del=[&](int x){
        if( cnt[a[x]]==1)res--;
        cnt[a[x]]--;
    };
    sort(qu.begin(),qu.end());
    int l=1,r=0;
    vector<int>ans(q);
    for(auto &[L,R,idx,_]:qu){
        while(l>L)add(--l);
        while(l<L)del(l++);
        while(r>R)del(r--);
        while(r<R)add(++r);
        ans[idx]=res;
    }
    for(auto x:ans)cout<<x<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}