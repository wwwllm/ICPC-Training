#include<iostream>
#include<cmath>
using namespace std;

int m[2000000]={0};

int main(){
	int n,ans;
	cin>>n;
	double a;
	int t;
	for(int i=0;i<n;i++){
		cin>>a>>t;
		for(int j=1;j<=t;j++){
			m[(int)floor(a*j)-1]++;
		}
	}
	for(int i=0;i<2000000;i++){
		if(m[i]%2==1){
			ans=i+1;
			break;
		}
	}
	cout<<ans;
	return 0;
}

