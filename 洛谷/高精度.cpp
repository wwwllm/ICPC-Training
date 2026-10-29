#include<bits/stdc++.h>
using namespace std;

#define maxn 100//定义最大位数； 
struct bigint{
	int len,a[maxn]={0};
	//len记录长度，a[maxn]记录每一位数字；
	bigint (int x=0){
		for(len=1;x;len++){
			a[len]=x%10;
			x/=10;
		}
	} 
	int &operator[](int i){//重载[],使可以直接使用x[]代替x.a[] 
		return a[i];
	}
	void flatten(int l){//进位（展平）操作 
		len=l;
		for(int i=1;i<=len;i++){
			a[i+1]+=a[i]/10;
			a[i]%10;
		}
		for(;!a[len];)	len--;
	}
	void print(){//输出 
		for(int i=max(len,l);i>=1;i--){
			cout<<a[i];
		}
	}
};
bigint operator+(bigint a,bigintb){
	bigint c;
	int len=max(a.len,b.len);
	for(int i=1;i<=len;i++){
		c[i]=a[i]+b[i];
	}
	c.flatten(len+1);
	return c;
} 
bigint operator*(bigint a,bigint b){
	bigint c;
	int len=max(a.len,b.len);
	for(int i=1;i<=len;i++){
		c[i]=a[i]*b[i];
	}
	c.flatten(len*2);
	return c;
}
int main(){
	return 0;
}
