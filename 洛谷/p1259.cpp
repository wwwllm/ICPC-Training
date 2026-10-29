#include<bits/stdc++.h>
using namespace std;


char ans[250];

int main(){
	int n;
	cin>>n;
	char huan[2];
	for(int i=1;i<=n;i++){
		ans[i]='o';
		ans[n+i]='*';
	}
	ans[2*n+1]='-';
	ans[2*n+2]='-';
	for(int j=1;j<=2*n+2;j++)cout<<ans[j];
	cout<<endl;
	bool flag=true;
	for(int i=n+1;i>=5;i--){
		if(flag){
			huan[1]=ans[i];
			huan[0]=ans[i-1];
			ans[i]=ans[2*(i-1)+2];
			ans[i-1]=ans[2*(i-1)+1];
			ans[2*(i-1)+2]=huan[1];
			ans[2*(i-1)+1]=huan[0];
			flag=false;
			for(int j=1;j<=2*n+2;j++)cout<<ans[j];
		}
		else{
			huan[1]=ans[i+1];
			huan[0]=ans[i];
			ans[i+1]=ans[2*(i-1)+2];
			ans[i]=ans[2*(i-1)+1];
			ans[2*(i-1)+2]=huan[1];
			ans[2*(i-1)+1]=huan[0];
			i++;
			flag=true;
			for(int j=1;j<=2*n+2;j++)cout<<ans[j];
		}
	
		cout<<endl;
	}
	cout<<"ooo*o**--*";
	for(int i=1;i<=n-4;i++)
	cout<<"o*";
	cout<<endl;
	cout<<"o--*o**o";
	for(int i=1;i<=n-3;i++)
	cout<<"o*";
	cout<<endl;
	cout<<"o*o*o*--";
	for(int i=1;i<=n-3;i++)
	cout<<"o*";
	cout<<endl;
	cout<<"--";
	for(int i=1;i<=n;i++)
	cout<<"o*";
	return 0;
} 
