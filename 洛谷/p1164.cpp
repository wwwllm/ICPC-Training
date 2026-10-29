#include<bits/stdc++.h>
using namespace std;

int a[1050]={0},f[1050][1050]={0};
//当数据量大是迭代算法所需时间大于递归算法 ，当使用递归时会有测试点超时。 
/*int f(int m,int n){
	if(n==1){
		if(a[n]==m)	return f1[m][n]=1;
		else	return f1[m][n]=0;
	}
	if(f1[m][n])return f1[m][n];
	if(m==a[n])return f1[m][n]=1+f(m,n-1);
	if(m>a[n]) return f1[m][n]=f(m-a[n],n-1)+f(m,n-1);
	if(m<a[n])	return f1[m][n]=f(m,n-1);
}*/
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
      for(int j=1;j<=m;++j)
      {
          if(j==a[i])f[i][j]=f[i-1][j]+1;
          if(j>a[i]) f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
          if(j<a[i]) f[i][j]=f[i-1][j];
      }
    cout<<f[n][m];
	
	return 0;
} 
