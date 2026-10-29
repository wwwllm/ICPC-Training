#include<iostream>
using namespace std;

int main(){
	int t,n,sum=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		sum=0;
		int *p=new int[n];
		for(int i=0;i<n;i++){
			cin>>p[i];
			p[i]%=114;
			sum+=p[i];
		}	
		cout<<sum<<endl;
	}
	return 0;
}
