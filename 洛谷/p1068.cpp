#include<bits/stdc++.h>
using namespace std;

struct zyz{
	int num;		
	int cj;	
};
zyz t[5050];
bool cmp(zyz a,zyz b){
	if(a.cj==b.cj)	return a.num<b.num;
	return a.cj>b.cj;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>t[i].num>>t[i].cj;
	sort(t+1,t+n+1,cmp);
	m=floor(m*1.5);
	int i=1;
	while(t[m].cj==t[m+1].cj)m++;
	cout<<t[m].cj<<' '<<m<<endl;
	while(t[i].cj>=t[m].cj){
		cout<<t[i].num<<' '<<t[i].cj<<endl;
		i++;
	}
	return 0;
}

