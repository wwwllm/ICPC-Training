#include <bits/stdc++.h>
#define int long long
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
            f[x] = f[f[x]]; 
            x = f[x];
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
void solve()
{
    int n, m,k;
    cin >> n >> m>>k;
    vector<array<int,4>>e(m);
    for(int i=0;i<m;i++)
    {
        auto &[w,u,v,id]=e[i];
        id=i+1;
        cin>>u>>v>>w;
    }
    ranges::sort(e);
    DSU dsu(n+1);
    vector<array<int,4>>ee;
    for(auto [w,u,v,id]:e){
        if(dsu.merge(u,v)){
            ee.push_back({w,u,v,id});
        }
    }
    ranges::sort(ee);
    int cnt=0,res=0;
    
    for(int _=0;_<min(k,n-1);_++){
        if(ee.back()[0]>1)
            ee.pop_back(),cnt++;
        else break;
    }
    cout<<cnt<<'\n';
    dsu=DSU(n+1);
    for(auto [w,u,v,id]:ee)dsu.merge(u,v),res+=w;
    for(int i=1;i<n;i++){
        if(dsu.merge(i,i+1))
            cout<<i<<' '<<i+1<<'\n',res++;
    }
    cout<<res<<'\n';
    for(auto [w,u,v,id]:ee)cout<<id<<' ';
    for(int i=1;i<=cnt;i++)cout<<m+i<<" \n"[i==cnt];
    if(cnt==0)cout<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}