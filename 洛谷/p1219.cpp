#include<bits/stdc++.h>
using namespace std;

int b1[30]={0},b2[30]={0},b3[30]={0},n,ans,a[1000];//b1为列，b2，b3为斜着的。 
void dfs(int x);//x为行 
int main(){
	cin>>n;
	dfs(1);
	cout<<ans;
	return 0;
}
void dfs(int x){
	if(x>n){
		ans++;
		if(ans<=3){
			for(int i=1;i<=n;i++){
				cout<<a[i]<<' ';
			}
			cout<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		if(b1[i]==0&&b2[i+x]==0&&b3[x-i+n]==0){
			b1[i]=1;b2[i+x]=1;b3[x-i+n]=1;
			a[x]=i;
			dfs(x+1);
			b1[i]=0;b2[i+x]=0;b3[x-i+n]=0;
		}
	}
} 
