#include<bits/stdc++.h>
using namespace std;

int p[100050]={0},d[100050]={0},rank[100050];

int find(int x){//优化方式：路径压缩 
	if(x==p[x])return x;
	return p[x]=find(p[x]);
}
void join(int a,int b){//优化方式：按秩合并 
	int roota=find(a),rootb=find(b);
	if(roota!=rootb){
		if(rank[roota]>rank[rootb])	p[rootb]=roota;
		else if(rank[roota]<rank[rootb])	p[roota]=rootb;
		else	p[rootb]=roota,rank[roota]++;
	}
}
int main(){
	int n,q,t;
	cin>>n>>q;
	int ans=0;
	for(int i=1;i<=n;i++)	p[i]=i,rank[i]=0;
	for(int i=1;i<=q;i++){
		cin>>t;
		for(int j=1;j<=t;j++){
			cin>>d[j];
		}
		for(int j=2;j<=t;j++){
			join(d[1],d[j]);
		}
	}
	for(int i=1;i<=n;i++){
		if(p[i]==i)ans++;
	}
	cout<<ans;
	return 0;
} 
