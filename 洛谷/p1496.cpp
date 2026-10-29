#include<bits/stdc++.h>
#define ll long long
using namespace std;

//¿Î…¢ªØ 
const int maxn=2e4+50;
int n;
ll f[2*maxn],df[2*maxn],ans=0;
int a[maxn],b[maxn],dtop=0,top=0,c[maxn*2];
map<int,int >m;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		df[++dtop]=a[i];
		df[++dtop]=b[i];
	}
	sort(df+1,df+1+dtop);
	for(int i=1;i<=dtop;i++){
		if(df[i]!=df[i-1]||i==1){
			f[++top]=df[i];
			m[df[i]]=top;
		}
	}
	for(int i=1;i<=n;i++){
		int l=m[a[i]],r=m[b[i]];
		for(int j=l;j<r;j++){
			c[j]=1;
		}
	}
	for(int i=1;i<top;i++){
		if(c[i])ans+=f[i+1]-f[i];
	}
	cout<<ans<<endl; 
	return 0;
}
