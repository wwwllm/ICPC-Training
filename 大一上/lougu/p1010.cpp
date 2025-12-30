#include<bits/stdc++.h>
using namespace std;


/*void f(int n,int k){//k为阶数，
	if(n==0){
		cout<<"0";
		return ;
	}
	if(n==2){
		cout<<"2";
		return ;
	}
	if(n==1){
		cout<<"2(0)";
		return ;
	}	
	if(n==3){
		cout<<"2+2(0)";
		return ;
	}
	if(n==(1<<k)){
		cout<<"2(";
	
		int r=k,i=0;
		while(r>0){
			r=r>>1;
			i++;
		}
		f(k,i-1);
		cout<<")";
		return ;
	}
	cout<<"2(";
	int r=k,i=0;
	while(r>0){
		r=r>>1;
		i++;
	}
	f(k,i-1);
	cout<<")+";
	n=n-(1<<k);
	int z=n,j=0;
	while(z>0){
		z=z>>1;
		j++;
	}
	f(n,j-1);
	
}*/
void f(int x)
{
    for(int i=14;i>=0;i--) //两万的数据最多是2（14）
    {
        if(pow(2,i)<=x){
        //pow（n，m）在cmath库中，返回n^m；枚举出第一个幂次方
            if(i==1) cout<<"2"; //2（1）不用再往后分解了且2^1输出为2，单独出来
            else if(i==0) cout<<"2(0)"; //2（0）也不用再往后分解了，单独出来
            else{ //若i>1则继续分解指数i
                cout<<"2(";
            fff(i);
            cout<<")";
            }
            x-=pow(2,i); //继续循环分解余下的
            if(x!=0) cout<<"+";
            //加号处理的最简单方法：若此x还没分解完，则后面还有项，所以输出一个+号
        }
    }
}
int main(){
	int n;
	cin>>n;
	int r=n,k=0;
	while(r>0){
		r=r>>1;
		k++;
	}
	f(n,k-1);
	return 0;
}
