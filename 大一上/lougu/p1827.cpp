#include<bits/stdc++.h>
using namespace std;

string q,z;
int len;
void dfs(int l1,int r1,int l2,int r2){
	char q1=q[l1];
	for(int i=l2;i<=r2;i++){
		if(z[i]==q1){
			dfs(l1+1,l1+i-l2,l2,i-1);
			dfs(l1+i-l2+1,r1,i+1,r2);
			cout<<q1;
			return ;
		}
	}
}
int main(){
	cin>>z>>q;
	len=q.length();
	dfs(0,len-1,0,len-1);
	return 0;
} 
