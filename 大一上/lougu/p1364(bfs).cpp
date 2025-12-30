#include<bits/stdc++.h>
using namespace std;

struct node{
	int left,right,value=0,father,m;
}t[105];
int n;
bool b[105];
int dis[105];
int ans=10000000000;
queue<node>Q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].value>>t[i].left>>t[i].right;
		t[i].m=i;
	}
	for(int i=1;i<=n;i++){
		if(t[i].left!=0)t[t[i].left].father=i;
		if(t[i].right!=0)t[t[i].right].father=i;
	}
	for(int num=1;num<=n;num++){
		memset(b,false,sizeof(b));
		memset(dis,0,sizeof(dis));
		int res=0;
		Q.push(t[num]);
		b[num]=true;
		dis[num]=0;
		while(!Q.empty()){
			node p=Q.front();
			res+=dis[p.m]*p.value;
			Q.pop();
			if(!b[p.left]){
				Q.push(t[p.left]);
				dis[p.left]=dis[p.m]+1;
				b[p.left]=true;
			}
			if(!b[p.right]){
				Q.push(t[p.right]);
				dis[p.right]=dis[p.m]+1;
				b[p.right]=true;
			}
			if(!b[p.father]){
				Q.push(t[p.father]);
				dis[p.father]=dis[p.m]+1;
				b[p.father]=true;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
