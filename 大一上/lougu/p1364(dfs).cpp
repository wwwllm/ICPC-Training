#include<bits/stdc++.h>
using namespace std;

struct node{
	int left,right,value,father;
}t[105];
int n;
bool b[105];
int ans=10000000000;
int dfs(int num,int d){
	if(!num||b[num])return 0;
	b[num]=true;
	return dfs(t[num].left,d+1)+dfs(t[num].right,d+1)+dfs(t[num].father,d+1)+d*t[num].value;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].value>>t[i].left>>t[i].right;
	}
	for(int i=1;i<=n;i++){
		t[t[i].left].father=i;
		t[t[i].right].father=i;
	}
	for(int num=1;num<=n;num++){
		memset(b,false,sizeof(b));
		ans=min(ans,dfs(num,0));
	}
	cout<<ans;
	return 0;
}
