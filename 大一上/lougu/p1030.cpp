#include<bits/stdc++.h>
using namespace std;

string a,b;
int len;
void dfs(int l1,int r1,int l2,int r2){//1为中序，2为后序 
	char root=b[r2];
	int i=l1;
	for(;i<=r1;i++){
		if(a[i]==root)break;
	}
	cout<<root;
	if(i>l1)dfs(l1,i-1,l2,l2+i-l1-1);
	if(i<r1)dfs(i+1,r1,l2+i-l1,r2-1);
	return ;
}
int main(){
	cin>>a>>b;
	len=a.length();
	dfs(0,len-1,0,len-1);
	return 0;
}
