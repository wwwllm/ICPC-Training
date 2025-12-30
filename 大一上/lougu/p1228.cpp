#include<bits/stdc++.h>
using namespace std;

long long p[15]={0};
void f(int a,int b,int k,int x,int y){//a,b为处理方块的左上角坐标，x,y为人的坐标 
	if(k==0)	return ;
	if(x>=a+p[k-1]){
		if(y>=b+p[k-1]){
			cout<<b+p[k-1]-1<<' '<<a+p[k-1]-1<<" 4"<<endl;
			f(a+p[k-1],b+p[k-1],k-1,x,y); 
			f(a,b,k-1,a+p[k-1]-1,b+p[k-1]-1); 
			f(a+p[k-1],b,k-1,a+p[k-1],b+p[k-1]-1); 
			f(a,b+p[k-1],k-1,a+p[k-1]-1,b+p[k-1]); 
			return ;
		}
		cout<<b+p[k-1]<<' '<<a+p[k-1]-1<<" 2"<<endl;  
		f(a+p[k-1],b,k-1,x,y);
		f(a,b,k-1,a+p[k-1]-1,b+p[k-1]-1);
		f(a+p[k-1],b+p[k-1],k-1,a+p[k-1],b+p[k-1]);
		f(a,b+p[k-1],k-1,a+p[k-1]-1,b+p[k-1]);
		return ;
	}
	if(y>=b+p[k-1]){ 
		cout<<b+p[k-1]-1<<' '<<a+p[k-1]<<" 3"<<endl;
		f(a,b+p[k-1],k-1,x,y);
		f(a,b,k-1,a+p[k-1]-1,b+p[k-1]-1);
		f(a+p[k-1],b,k-1,a+p[k-1],b+p[k-1]-1);
		f(a+p[k-1],b+p[k-1],k-1,a+p[k-1],b+p[k-1]);
		return ;
	}
	cout<<b+p[k-1]<<' '<<a+p[k-1]<<" 1"<<endl; 
	f(a,b,k-1,x,y);
	f(a+p[k-1],b,k-1,a+p[k-1],b+p[k-1]-1);
	f(a+p[k-1],b+p[k-1],k-1,a+p[k-1],b+p[k-1]);
	f(a,b+p[k-1],k-1,a+p[k-1]-1,b+p[k-1]);
	return ;
}
int main(){
	int i=2,j=1;
	p[0]=1;
	while(j<=14){
		p[j]=i;
		i=i<<1;
		j++;
	}
	int k,x,y;
	cin>>k>>x>>y;
	f(1,1,k,x,y);
	return 0;
}





