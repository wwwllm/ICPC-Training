#include<bits/stdc++.h>
using namespace std;

int b[7]={99,100,101,110,111,114,119};
int c[7]={0};
int ans[7]={1,1,1,1,2,1,1};
void solve(){
	string s;
	cin>>s;
	int t=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(b[j]==s[i]){
				c[j]++;
			}
		}
	}
	bool flag=1;
	for(int i=0;i<7;i++){
		if(ans[i]!=c[i])flag=false;
	}
	if(flag)cout<<"happy new year"<<endl;
	else	cout<<"I AK IOI"<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t=1;
	//cin>>t;
	while (t--) solve();
	return 0;
}
