#include<bits/stdc++.h>
using namespace std;

int n,t[30]={0},sum,maxt=0,ans=0,mintime=0;
void dfs(int x){
	if(x>n){
		maxt=max(maxt,ans);
		return ;
	}
	if(ans+t[x]<=sum/2){
		ans+=t[x];
		dfs(x+1);
		ans-=t[x];	
	}
	dfs(x+1);	
}
int main(){
	int s[5];
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	for(int i=1;i<=4;i++){
		n=s[i];
		ans=0;
		maxt=0;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>t[i];
			sum+=t[i];
		}
		dfs(1);
		mintime+=sum-maxt;
	}
	cout<<mintime;
	return 0;
}
