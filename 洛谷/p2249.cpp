#include<bits/stdc++.h>;
using namespace std;

int t[1000050]={0};
int main(){
	int m,n,q;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	int i=1,j=n,k;
	for(int x=1;x<=m;x++){
		cin>>q;
		i=1,j=n;
		while(i<j){
			k=(i+j)/2;
			if(q>t[k]){
				i=k+1;
			}
			else{
				j=k;
			}
		}
		if(t[i]==q)cout<<i<<' ';
		else	cout<<-1<<' ';
	}
	return 0;
}
