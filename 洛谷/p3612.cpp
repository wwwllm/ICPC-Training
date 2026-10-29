#include<bits/stdc++.h>

using namespace std;

string s;
long long p[80]={0},n;
int main(){
	long long i=1;
	cin>>s>>n;
	int len=s.length();
	int k=0;
	while(k<=80&&len*p[k-1]*2<n){
		p[k]=i;
		i=i<<1;
		k++;
	}
	while(n>len){
		if(n<len*p[k-1]){
			k--;
			continue;
		}
		if(n==len*p[k]){//ÔÚÎ²²¿
			n=p[--k]*len-1;
			continue;
		}
		if(n==len*p[k-1]+1){
			k--;
			n--;
			continue;
		}
		n=n-p[k-1]*len-1;
		k--;
	}
	cout<<s[n-1];
	return 0;
} 
