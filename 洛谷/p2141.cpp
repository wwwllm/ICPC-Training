#include<iostream>
using namespace std;

/*优化前 O(n^3)
void px(int *p,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(p[j]>p[j+1]){
				p[j]=p[j]-p[j+1];
				p[j+1]+=p[j];
				p[j]=p[j+1]-p[j];
			}
		}
	}
}
int main()
{
	int n,*p,*q,count=0;
	cin>>n;
	p=new int[n];
	q=new int[n];
	int sum;
	for(int i=0;i<n;i++)cin>>p[i];
	px(p,n);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			sum=p[i]+p[j];
			if(sum>p[n-1])break;
			else
			{
				for(int k=j;k<n;k++)
				{
					if(p[k]==sum&&q[k]==0)q[k]=1;
				}
			}
		}
	}
	for(int i=0;i<n;i++)count+=q[i];
	cout<<count;
	delete[] p;
	delete[] q;
	return 0;
}
优化：利用桶 
*/
const int M=20005;//20005由于最大值是10000+10000=20000，const int是静态定义，定义后该值（即M)无法修改。
int t[M];//t是桶，t[i]表示值为i的数在集合中两两相加出现了几次
int main(){
	int n,*p,count=0;
	cin>>n;
	p=new int[n];
	for(int i=0;i<n;i++)cin>>p[i];
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			t[p[i]+p[j]-1]++;
		}
	}
	for(int i=0;i<n;i++){
		if(t[p[i]-1]!=0){
			count++;
			t[p[i]-1]=0;
		}
	}
	cout<<count<<endl;
	return 0;
} 
