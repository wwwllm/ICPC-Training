#include<bits/stdc++.h>
#define maxn 80050
using namespace std;

int n,h[maxn],s[maxn];
long long ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	} 
	int top=0,k=2;
	s[top++]=1;
	while(k!=n+1){
		while(h[s[top-1]]<h[k]&&top>0){
			top--;
		}
		ans+=top;
		s[top++]=k++;
	}
	cout<<ans;
	return 0;
}
