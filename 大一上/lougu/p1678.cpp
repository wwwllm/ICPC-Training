#include<bits/stdc++.h>
using namespace std;

int q[100050]={0};
int main(){
	int n,m,s;
	long long ans=0;
	cin>>m>>n;//m表示学校，n表示人数。 
	for(int i=1;i<=m;i++){
		cin>>q[i];
	}
	sort(q+1,q+1+m);
	for(int i=1;i<=n;i++){
		cin>>s;
		int l=0,r=m+1,mid;
		while(l+1!=r){ 
			mid=(l+r)/2;
			if(q[mid]<s){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		if(s<=q[1]){
			ans+=q[1]-s;
		} else{
			ans+=min(abs(q[r]-s),abs(s-q[l]));
		}
	}
	cout<<ans;
	return 0;
}
