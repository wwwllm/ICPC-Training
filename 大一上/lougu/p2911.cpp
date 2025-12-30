#include<iostream>
using namespace std;

int a[80]={0};
int main(){
	int s1,s2,s3,max=0,count=0;
	cin>>s1>>s2>>s3;	
	for(int i=1;i<=s1;i++){
			for(int j=1;j<=s2;j++){
				for(int k=1;k<=s3;k++){
					a[i+j+k-1]++;
				}
			}
	}
	for(int i=3;i<80;i++){
			if(a[i]>count)	{
				max=i+1;
				count=a[i];
			}	
	}
	cout<<max;
	return 0;
}
