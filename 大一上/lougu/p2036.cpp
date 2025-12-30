#include<bits/stdc++.h>
using namespace std;
//注释为回溯算法，会超时。 
int n;
struct food{
	int s;
	int b;
};
food t[15];
int ans=0x7fffffff;//b[15]={0},ssum=1,bsum=0;
void dfs(int x,int ssum,int bsum){
	if(x>n){
		if(ssum==1&&bsum==0)return ;
		ans=min(ans,abs(ssum-bsum));
		return ;
	}
	dfs(x+1,ssum*t[x].s,bsum+t[x].b);
	dfs(x+1,ssum,bsum);
	
}
/*void dfs(int x){
	if(x>n){
		if(ssum==1&&bsum==0)return ;
		ans=min(ans,abs(ssum-bsum));
		return ;
	}
	for(int i=x;i<=n;i++){
		if(b[i]==0){
			ssum*=t[i].s;
			bsum+=t[i].b;
			b[i]=1;
			dfs(x+1);
			b[i]=0;
			ssum/=t[i].s;
			bsum-=t[i].b;
		}
		dfs(x+1);
	}
}*/
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].s>>t[i].b;
	}
	dfs(1,1,0);//dfs(1);
	cout<<ans;
	return 0;
} 
