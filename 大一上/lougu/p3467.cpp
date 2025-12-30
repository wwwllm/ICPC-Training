#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=250050; 
ll n,top=0,ans;
ll s[maxn],h[maxn],w;
int main(){
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)cin>>w>>h[i];
	for(int i=1;i<=n;i++){
		while(top>0&&h[s[top-1]]>=h[i]){
			top--;
			if(h[s[top]]==h[i])ans--;
		}
		s[top++]=i;
	}
	cout<<ans<<endl;
	return 0;
} 
