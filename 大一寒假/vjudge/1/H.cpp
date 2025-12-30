#include<bits/stdc++.h>
using namespace std;

void solve(){
	string a1,s1;
	cin>>a1>>s1;
	int b[20];
	int a[20]={0};
	int s[20]={0};
	int lena=a1.length(),lens=s1.length(),i,j;
	j=lens-1;
	for(i=1;i<=lena;i++){
		a[i]=a1[lena-i]-'0';
		if(a1[lena-i]>s1[j]){
			if(j>=1&&s1[j-1]=='1'){
				s[i]=(s1[j-1]-'0')*10+s1[j]-'0';
				j-=2;
			}else{
				cout<<-1<<endl;
				return ;
			}
		}else{
			if(j>=0){
				s[i]=s1[j--]-'0';
			}else{
				cout<<-1<<endl;
				return ;
			}
		}
	}
	int top=lena;
	while(j>=0)s[++top]=s1[j]-'0',j--;
	while(s[top]-a[top]==0)top--;
	for(int i=top;i>=1;i--)cout<<s[i]-a[i];
	cout<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
