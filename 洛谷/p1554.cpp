#include<iostream>
using namespace std;

int main(){
	long long m,n,x;
	cin>>m>>n;
	int p[10]={0};
	for (long long i=m;i<=n;i++){
		x=i;
		while(x>0){
			p[x%10]++;
			x/=10;
		}
	}
	for(int i=0;i<10;i++)cout<<p[i]<<' ';
	return 0;
	
} 
