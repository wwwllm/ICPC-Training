#include<bits/stdc++.h>
using namespace std;

#define MAXN 5050
int n,m,p;
int t[MAXN],r[MAXN];

int find(int n){
	if(n==t[n])return n;
	return t[n]=find(t[n]);
}
void join(int x,int y){
	int rootx=find(x),rooty=find(y);
	if(rootx!=rooty){
		if(r[rootx]>r[rooty])t[rooty]=rootx;
		else if(r[rootx]<r[rooty])t[rootx]=rooty;
		else	t[rooty]=rootx,r[rootx]++;
	}
}
int main(){
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++){
		t[i]=i;
		r[i]=0;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		join(x,y);
	}
	for(int i=1;i<=p;i++){
		int a,b;
		cin>>a>>b;
		if(find(a)==find(b))cout<<"Yes"<<endl;
		else	cout<<"No"<<endl;
	}
	return 0;
}
