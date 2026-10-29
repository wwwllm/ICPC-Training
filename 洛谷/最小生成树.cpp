#include<bits/stdc++.h>
using namespace std;

struct lianxian{
	int j1,j2,v;
}; 
lianxian t[5050];
int p[5050];
bool cmp(lianxian a,lianxian b){
	return a.v<b.v;
}
bool find(int x){
	if(p[x]==x)return x;
	return x=find(p[x]);
}
int main(){
	int n,sum=0,rootj1,rootj2;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].j1>>t[i].j2>>t[i].v;
		p[i]=i;
	}
	sort(t+1,t+n+1,cmp);
	
	for(int i=1;i<=n;i++){
		rootj1=find(t[i].j1);
		rootj2=find(t[i].j2);
		if(rootj1!=rootj2){
			sum+=t[i].v;
			p[t[i].j2]=t[i].j1;
		}
	}
	cout<<sum;
	return 0;
} 
