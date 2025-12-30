#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	ll a,b,c;
	cin>>a>>b>>c;
	ll mid;
	if(a>b){
		if(c+b>=a)mid=(c+b+a)/2;
		else	mid=c+b;
	}else{
		if(c+a>=b)mid=(c+b+a)/2;
		else	mid=c+a;
	}
	ll i=1;
	while(mid>=i){
		mid-=i;
		i++;
	}
	cout<<i-1<<endl;
	return 0;
} 
