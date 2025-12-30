#include<bits/stdc++.h>
using namespace std;

string p[21]; 
int n;
int maxl=0,len,c,b[21]={0};
int chongfu(string a,string b){
	int lenm=min(a.length(),b.length()),lena=a.length();
	int t=0;
	for(int i=1;i<=lenm;i++){
		t=0;
		for(int j=0;j<i;j++){
			if(a[lena-i+j]!=b[j])break;
			t++;
		}
		if(t==i)return i;
	}
	return 0;
}
void dfs(int x){//x为字符串在数组中的索引 
	bool flag=false;
	for(int i=1;i<=n;i++){
		int lenm=min(p[x].length(),p[i].length()),lenc=chongfu(p[x],p[i]);
		if(b[i]==2)continue;
		if(lenc==lenm||lenc==0)continue;
		flag=true;
		len+=p[i].length()-lenc;
		b[i]++;
		dfs(i);
		b[i]--;
		len-=p[i].length()-lenc;
	}
	if(!flag){
		maxl=max(len,maxl);
		return ;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	char q;
	cin>>q;
	for(int i=1;i<=n;i++){
		if(p[i][0]==q){
			b[i]++;
			len=p[i].length();
			dfs(i);
			b[i]=0;
		}
	}
	cout<<maxl;
	return 0;
}
