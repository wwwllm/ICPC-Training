#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=100010;
struct node{
	ll x,y,z;
};
node a[maxn];
ll d[maxn*2],f[maxn*2],dtop=0,top=0,bcj[maxn*2];
map<ll,ll>m;
ll find(ll n){
	if(bcj[n]==n)return n;
	else	return bcj[n]=find(bcj[n]);
}
void join(ll a,ll b){
	ll roota=find(a),rootb=find(b);
	if(roota!=rootb){
		bcj[rootb]=roota;
	}
}
void solve(){
	int n;
	cin>>n;
	dtop=0;top=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		d[++dtop]=a[i].x;
		d[++dtop]=a[i].y;
	}
	sort(d+1,d+1+dtop);
	for(int i=1;i<=dtop;i++){
		if(i==1||d[i]!=d[i-1]){
			f[++top]=d[i];
			m[d[i]]=top;
		}
	}
	for(int i=1;i<=top;i++)bcj[i]=i;
	for(int i=1;i<=n;i++){
		if(a[i].z){
			ll q=m[a[i].x],p=m[a[i].y];
			join(q,p);
		}
	} 
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(!a[i].z){
			ll q=m[a[i].x],p=m[a[i].y];
			if(find(q)==find(p)){
				flag=false;
				break;
			}
		}
	}
	if(flag)cout<<"YES"<<endl;
	else	cout<<"NO"<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
