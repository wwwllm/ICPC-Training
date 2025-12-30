#include<bits/stdc++.h>
using namespace std;

struct apple{
	int h;
	int l;
};
apple t[5050];
bool cmp(apple a,apple b){
	return a.l<b.l;
}
int main(){
	int n,s,ans=0;
	cin>>n>>s;
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>t[i].h>>t[i].l;
	}
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n&&s>0;i++){
		if(t[i].h<=a+b&&t[i].l<=s){
			ans++;
			s-=t[i].l;
		}
	}
	cout<<ans;
	return 0;
} 
