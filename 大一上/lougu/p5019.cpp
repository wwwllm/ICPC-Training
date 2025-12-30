#include<bits/stdc++.h>
using namespace std;

int d[100050]={0};
int min(int start,int end){//找到最小值的索引。 
	int min=start;
	for(int i=start+1;i<=end;i++){
		if(d[i]<d[min])min=i;
	}
	return min;
}

int f(int start,int end){
	if(start==end){
		return d[end];
	}
	int minp=min(start,end),day=d[minp];
	
	for(int i=start;i<=end;i++){
		d[i]-=day;
	}
	if(minp==end)return f(start,end-1)+day;
	if(minp==start)return f(start+1,end)+day;
	return f(start,minp-1)+f(minp+1,end)+day;
}
int main (){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	int days=f(1,n);
	cout<<days;
	return 0;
}
//其他解法
/*int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	f[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(d[i]<=d[i-1])
			f[i]=f[i-1];
		else f[i]=f[i-1]+(d[i]-d[i-1]);
	}
	cout<<f[n]<<endl;
	return 0;
}*/
/*int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)     cin>>a[i];
	for(int i=2;i<=n;i++)     if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
	cout<<ans+a[1];
	return 0;
}*/
