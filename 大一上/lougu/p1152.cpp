#include<bits/stdc++.h>
using namespace std;
//因为连续差数量为n-1所以连续差所构成的序列一定是由1到n-1的一种排列 
int t[1050]={0},p[1050]={0};
string jianyan(int n){//判断是否1--(n-1)都存在 
	for(int i=1;i<n;i++){
		if(p[i]!=1)	return "Not jolly";
	}
	return "Jolly";
}
int main(){//差的绝对值过大导致数组越界从而导致报错。 
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int i=1;i<n;i++){
		if(abs(t[i]-t[i+1])>n||p[abs(t[i]-t[i+1])]==1){
			cout<<"Not jolly";
			return 0;
		}
		p[abs(t[i]-t[i+1])]=1; 
	}
	cout<<jianyan(n);
	return 0;
} 
/*

int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int i=1;i<n;i++){
		p[i]=abs(t[i]-t[i+1]);
	}
	sort(p+1,p+n);
	for(int i=1;i<n;i++){
        if(p[i]!=i){
			cout<<"Not jolly\n";
			return 0;
		}//判断输出
    }
    cout<<"Jolly\n";//如果未能输出，则为正确答案
    return 0;
} */
