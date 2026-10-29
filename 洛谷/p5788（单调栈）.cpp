#include<bits/stdc++.h>
#define maxn 3000050

using namespace std;

int n,s[maxn],ans[maxn],t[maxn];
int main(){
	cin>>n;
	int top=0;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	s[top++]=1;
	int k=2;
	while(k!=n+1){
		while(t[k]>=t[s[top-1]]&&top>0){
			ans[s[--top]]=k;
		}
		s[top++]=k;
		k++;
	}
	for(int i=n;i>=1;i--){//????
		while(t[ans[i]]==t[i])
			ans[i]=ans[ans[i]];
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
