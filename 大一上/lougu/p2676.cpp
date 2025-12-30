#include<bits/stdc++.h>

using namespace std;

int t[20050]={0};
//void px(int a,int b);
bool cmp(int a,int b);
int main(){
    int n,h,sum=0,num=1;
    cin>>n>>h;
    for (int i=1;i<=n;i++)  cin>>t[i];
    sort(t+1,t+n+1,cmp);
    do{
        sum+=t[num];
        num++;
    }while(sum<h&&num<=n);

    cout<<num-1;
    return 0;
}
bool cmp(int a,int b){
    return a>b;
}
/*void px(int a,int b){//选择排序
    for(int i=a;i<=b;i++){
        for(int j=i+1;j<=b;j++){
            if(t[i]<t[j]){
                t[i]=t[j]-t[i];
                t[j]-=t[i];
                t[i]+=t[j];
            }
        }
    }
}*/
/*void px(int a,int b){//冒泡排序
    for(int i=a;i<=b;i++){
        for(int j=a;j<b-i+1;j++){
            if(t[j]<t[j+1]){
                t[j]=t[j+1]-t[j];
                t[j+1]-=t[j];
                t[j]+=t[j+1];
            }
        }
    }
}*/
/*void px(int a,int b){//插入排序
    int now;
    for(int i=a;i<=b;i++){
        now=t[i];
        int j=i-1;
        for( ;j>=a;j--){
            if(now>t[j]){
                t[j+1]=t[j];
            }
            else    break;
        }
        t[j+1]=now;
    }
}*/
/*void px(int a,int b){//快速排序
    int flag=t[(a+b)/2],i=a,j=b,tmp;
    do{
        while(flag<t[i])i++;
        while(flag>t[j])j--;
        if(i<=j){
            tmp=t[i];
            t[i]=t[j];
            t[j]=tmp;
            i++;
            j--;
        }
    }while(i<=j);
    if(a<j) px(a,j);
    if(b>i) px(i,b);
}*/
