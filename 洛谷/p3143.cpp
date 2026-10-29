#include<bits/stdc++.h>
using namespace std;

const int maxn=50050;
int n,k;
int p[maxn],l[maxn],r[maxn],ans=0;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>p[i];
	sort(p+1,p+1+n);
	l[1]=1;r[n]=1;
	for(int i=2,j=1;i<=n;i++){
        while(p[i]-p[j]>k)
            j++;
        l[i]=max(l[i-1],i-j+1);
    }
    for(int i=n-1,j=n;i>=1;i--){
        while(p[j]-p[i]>k)
            j--;
        r[i]=max(r[i+1],j-i+1);
    }
	for(int i=1;i<n;i++){
		ans=max(ans,l[i]+r[i+1]);
	}
	cout<<ans;
	return 0;
}
