#include<bits/stdc++.h>
#define pb push_back
using namespace std;

struct DSU {
	vector<int> f,siz;
	
	DSU() {}
	DSU(int n) {init(n);}
	
	void init(int n) {
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
		siz[x] += siz[y];
		f[y]=x;
		return 1;
	}
	
	int esize(int x) {
		return siz[find(x)];
	}
	
	int count() {
		unordered_set<int> roots;
		for(int i=0;i<f.size();i++) roots.insert(find(i));
		return roots.size();
	}
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<array<int,2>>edges;
    DSU dsu(n+1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(w)dsu.merge(v,u);
        else edges.push_back({v,u});
    }
    int ans=0;
    for(auto [v,u]:edges){
        ans+=!dsu.merge(v,u);
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}