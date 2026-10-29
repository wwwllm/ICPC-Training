#include<bits/stdc++.h>
using namespace std;

stack<int>s;
int n,t;
int p[100005]={0},q[100005]={0};
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>q[j];
		}
		for(int j=1;j<=n;j++){
			cin>>p[j];
		}
		int k=1;
		for(int j=1;j<=n;j++){
			s.push(q[j]);
			while((s.top())==p[k]){
				s.pop();
				k++;
				if(s.empty())break;
			}
		}
		if(s.empty()) cout<<"Yes"<<endl; 
		else cout<<"No"<<endl;
		while(!s.empty())s.pop();
	}
	return 0;
}
