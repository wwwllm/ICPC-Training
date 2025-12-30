#include<bits/stdc++.h>
using namespace std;

#define MAXN 130
struct node{
	char left,right;
}t[MAXN];
int n;
void dfs(char a){
	if(a=='*')return ;
	cout<<a;
	if(t[a].left!='*')dfs(t[a].left);
	if(t[a].right!='*')dfs(t[a].right);
}
int main(){
	cin>>n;
	char a1;
	cin>>a1;
	cin>>t[a1].left>>t[a1].right;
	for(int i=1;i<n;i++){
		char a;
		cin>>a;
		cin>>t[a].left>>t[a].right;
	}
	dfs(a1);
	return 0;
}
