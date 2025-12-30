#include<bits/stdc++.h>
using namespace std;

struct tu{
	int x,y,q;
}v[100050];
int t[20050],b[20050]={0};
int n,m;
bool cmp(tu a,tu b){
	return a.q>b.q;
}
int find(int x){
	if(x==t[x])return x;
	return t[x]=find(t[x]);
}
void join(int a,int b){ 
	int roota=find(a),rootb=find(b);
	if(roota!=rootb){
		t[rootb]=roota;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		t[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>v[i].x>>v[i].y>>v[i].q;
	}
	sort(v+1,v+1+m,cmp);
	for(int i=1;i<=m+1;i++){
		if(find(v[i].x)==find(v[i].y)){
			cout<<v[i].q<<endl;
			break;
		}
		if(!b[v[i].x])b[v[i].x]=v[i].y;
		else	join(b[v[i].x],v[i].y);
		if(!b[v[i].y])b[v[i].y]=v[i].x;
		else	join(b[v[i].y],v[i].x);
	}
	return 0;
}
