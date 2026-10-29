#include<bits/stdc++.h>
using namespace std;

#define MAXN 1050
int n,m,ans;
int t[MAXN];
int find(int n){
	if(n==t[n])return n;
	return t[n]=find(t[n]);
}
void join(int x,int y){
	int rootx=find(x),rooty=find(y);
	if(rootx!=rooty)t[rooty]=rootx; 
}
int main(){
	while(cin>>n>>m){
		ans=0;
		for(int i=1;i<=n;i++){
			t[i]=i;
		}
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			join(x,y);
		}
		for(int i=1;i<=n;i++){
			if(t[i]==i)ans++;
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
