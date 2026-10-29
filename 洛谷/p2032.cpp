#include<bits/stdc++.h>
#define maxn 2000050
using namespace std;

int n,k;
int a[maxn],q[maxn];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int h=0,t=0;
	for(int i=1;i<=n;i++){
		while(h<t&&q[h]+k<=i)	h++;
		while(h<t&&a[q[t-1]]<a[i])	t--;
		q[t++]=i;
		if(i>=k){
			cout<<a[q[h]]<<endl;
		}
	}
	return 0;
}
