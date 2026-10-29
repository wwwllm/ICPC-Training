#include<bits/stdc++.h>
using namespace std;

int n,m,s[1005],t[1005]={0};
long long ans=0;
char p[1005][1005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p[i][j]=='.')	t[j]++;
			else	t[j]=0;
		}
		int top=0;
		s[top++]=1;
		for(int j=2;j<=m;j++){
			while(t[s[top-1]]>t[j]&&top>0){
				top--;
				ans+=(s[top]-s[top-1])*(j-s[top])*t[s[top]];
			}
			s[top++]=j;
		}
		while(top>0){
			top--;
			if(top!=0){
				ans+=(s[top]-s[top-1])*t[s[top]]*(m+1-s[top]);
			}else	ans+=t[s[top]]*(m+1-s[top])*s[top];
		}
	}
	cout<<ans;
	return 0;
}
