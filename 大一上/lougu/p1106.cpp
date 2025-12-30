#include<bits/stdc++.h>
using namespace std;
//注意前导0，和输出为0的样例！！！ 
int s[255]={0};
int main(){
	string n;
	int t;
	cin>>n;
	cin>>t;
	int len=n.length();
	int k=0,j=1;
	for(int i=1;i<=len;i++){
		s[i]=n[i-1]-'0';
	}
	while(k<t){
		if(s[j]>s[j+1]){
			int z=j;
			while(z<len){
				s[z]=s[z+1];
				z++;
			}
			len--;
			k++;
			j--;
		}
		else	j++;
		
	}
	int l=1;
	while(s[l]==0&&l<len){
		l++;
	}
	for(int z=l;z<=len;z++){
		cout<<s[z];
	}
	return 0;
}
