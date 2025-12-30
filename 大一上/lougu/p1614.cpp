#include<iostream>
using namespace std;

int main(){//优化后 
	int n,m,sum=0,msum=0;
	cin>>n>>m;
	int *p=new int[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
		if(i<m){
			sum+=p[i];
			msum+=p[i];
		}
		else{
			sum=sum+p[i]-p[i-m];
			msum=sum<msum?sum:msum;
			
		}
		
	}
	cout<<msum; 
	return 0;
} 

/*优化前 
int main(){
	int n,m,msum=300000,sum=0;
	cin>>n>>m;
	int *p=new int[n];
	for(int i=0;i<n;i++)cin>>p[i];
	for(int i=0;i<n-m+1;i++){
		sum=0;
		
		for(int j=0;j<m;j++){
			sum+=p[i+j];
		}
		if(sum<msum){
			msum=sum;
		}
		
	}
	cout<<msum;
	delete[] p;
	return 0;
}优化方案：前m个数值计为sum，在m+1...n中扫描，每次减去区间外的数值，加上新进入区间的数值，再更新答案就可以了 */

