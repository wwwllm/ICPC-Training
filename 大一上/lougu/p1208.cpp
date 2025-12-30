#include<bits/stdc++.h>
using namespace std;

struct nai{
	int p;
	int q;
};
nai t[5050];
bool cmp(nai a,nai b){
	return a.p<b.p;
}
int main(){
	int n,m,ans=0;//ans要赋一个初始值 ！！！不会报错。 
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>t[i].p>>t[i].q;
	}
	sort(t+1,t+1+m,cmp);
	int i=1;
	while(n>0&&i<=m){
		if(n<t[i].q){
			ans+=t[i].p*n;
			n=0;
			break;
		}
		else{
			n-=t[i].q;
			ans+=t[i].p*t[i].q;
			i++;
		}
	}
	cout<<ans;
	return 0;
}

