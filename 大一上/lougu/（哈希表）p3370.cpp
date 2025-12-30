//hash表 
#include<bits/stdc++.h>
using namespace std;

#define mod 23333
#define MAXN 1510
#define base 261
int n,ans;
char s[MAXN];
vector<string>linker[mod+2];
inline void insert(){
	int hash=1;
	for(int i=0;s[i];i++){
		hash=(hash*base*111+s[i])%mod;//计算字符串的哈希值 
	}
	string t=s;
	for(int i=0;i<linker[hash].size();i++){
		if(linker[hash][i]==t){
			return;
		}
	}
	linker[hash].push_back(t);
	ans++;
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		insert();
	}
	cout<<ans<<endl;
	return 0;
}
