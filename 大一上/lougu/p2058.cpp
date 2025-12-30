#include<bits/stdc++.h>
using namespace std;

struct Ren{
	int time,n;
};
int n;
queue<Ren>Q;
int s=0,num[100001]={0},k,t;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>k;
		for(int j=1;j<=k;j++){
			Ren p;
			p.time=t;
			cin>>p.n;
			if(num[p.n]++==0)s++;
			Q.push(p);
		}
		Ren a=Q.front();
		while(a.time<=t-86400){
			Q.pop();
			if(--num[a.n]==0)s--;
			a=Q.front();
		}
		cout<<s<<endl;
	}
	return 0;
}
