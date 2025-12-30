#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+50;
int arr[maxn];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i];
	int numa[2],numb[2]={0};
	numa[0]=arr[1];
	numa[1]=1;
	for(int i=2;i<=n;i++){
		if(numa[0]==arr[i])numa[1]++;
		else{
			if(!numb[0])numb[0]=arr[i],numb[1]=1;
			else{
				if(arr[i]!=numb[0]){
					cout<<"No"<<endl;
					return ;
				}else{
					numb[1]++;
				}
			}
		}
	}
	if(numa[1]==numb[1])cout<<"Yes"<<endl;
	else	cout<<"No"<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
