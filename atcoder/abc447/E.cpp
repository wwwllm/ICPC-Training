#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
struct DSU {
	vector<int> f,siz;
    int roots;
	
	DSU() {}
	DSU(int n) {init(n);}
	
	void init(int n) {
        roots=n;
		f.resize(n);
		iota(f.begin(),f.end(),0);
		siz.assign(n,1);
	}
	
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}
	
	bool merge(int x,int y) {
		x=find(x);
		y=find(y);
		if (x == y) return 0;
        roots--;
		siz[x] += siz[y];
		f[y]=x;
		return 1;
	}
	
	int esize(int x) {
		return siz[find(x)];
	}
	
	int count() {
		return roots;
	}
};
int exp(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<array<int,3>>edges(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        edges[i]={u,v,i+1};
    }
    int res=0;
    DSU dsu(n);
    ranges::reverse(edges);
    for(auto [u,v,p]:edges){
        if(dsu.count()>2){
            dsu.merge(u,v);
        }
        else{
            int fu=dsu.find(u),fv=dsu.find(v);
            if(fu==fv)dsu.merge(fu,fv);
            else res+=exp(2,p),res%=mod;
        }
    }
    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}