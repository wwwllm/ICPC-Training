#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1000050; 
int son[maxn][26], cnt[maxn], idx;
int d[maxn]; //到根节点的距离
int chcnt[maxn];//子节点的数量
void insert(const char str[]) {
    int k = 0; 
    for (int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if (!son[k][u]) {
            son[k][u] = ++idx;
            d[son[k][u]] = d[k] + 1; 
			chcnt[k]++;
        }
        k = son[k][u];
    }
    cnt[k] ++; 
}
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		insert(s.c_str());
	}
	int l,r;
	cin>>l>>r;
    
    int ans=0;
    for (int i = 1; i <= idx; i++) {
    	if (chcnt[i] == 0) ans+=d[i]*2;
    	else if (chcnt[i] >= 2) ans-=d[i]*2*(chcnt[i]-1);
    }
    int maxd=0;
    for (int i = 1; i <= idx; i++) maxd=max(maxd,d[i]);
    ans-=maxd;
    cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t=1;
	//cin>>t;
	while (t--) solve();
	return 0;
}

