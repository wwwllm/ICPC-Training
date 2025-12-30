#include<bits/stdc++.h>
using namespace std;
//素数小结论:大于等于5的质数一定和6的倍数相邻
int a,b,p,ans=0;
int cnt=1;
int t[100050]={0},v[100050]={0};
int find(int x){//查找根 
	if(x==t[x])return x;
	return t[x]=find(t[x]);
}
void join(int a,int b){//合并 
	int roota=find(a),rootb=find(b);
	if(roota!=rootb){
		t[rootb]=roota;
	}
}
bool prime(int x)//判断素数 
{
    if(x==1)return 0;
    if(x==2||x==3)return 1;
    if(x==4)return 0;
    if((x%6!=1)&&(x%6!=5))return 0; 
    for(int i=5;i*i<=x;i+=6)
        if(!(x%i)||!(x%(i+2)))return 0;
    return 1;
}
void make_prime(){//找p到b的素数存在v中 
	for(int i=p;i<=b;i++){
		if(prime(i))v[cnt++]=i;
	}
}
int main(){
	cin>>a>>b>>p;
	for(int i=a;i<=b;i++){//并查集初始化 
		t[i]=i;
	}
	make_prime();
	for(int i=1;i<cnt;i++){
		int num=0;
		while(num*v[i]<a)num++;
		while((num+1)*v[i]<=b){
			join(num*v[i],(num+1)*v[i]);
			num++;
		}
	}
	for(int i=a;i<=b;i++){
		if(t[i]==i)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
