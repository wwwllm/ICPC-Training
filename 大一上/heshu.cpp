#include<iostream>
using namespace std;
 
bool sushu(int n){
	if(n==2||n==1)return true;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)	return false;
	}
	return true;
}
int main(){
	int t,l,r,k;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>l>>r>>k;
		int count=0;
		for(int j=l;j<=r;j++){
			if(sushu(j)==false)count++;
			else count=0; 
			if(count==k){
			cout<<j-k+1<<endl;
			break; 
			}
			
		}
		if(count<k)cout<<-1<<endl;
	}
	return 0;
}
