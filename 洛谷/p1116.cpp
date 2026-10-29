#include<bits/stdc++.h>
using namespace std;

int t[10050]={0};
int main(){
    int n,num=0,tmp;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            if (t[j]>t[j+1]){
                tmp=t[j];
                t[j]=t[j+1];
                t[j+1]=tmp;
                num++;
            }
        }

    }
    cout<<num;
    return 0;
}
/*int main(){//另一种解法:统计所有大于首项子序列项数之和(求冒泡排序交换次数）
    int n,num=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(t[j]>t[i])num++;
        }
    }
    cout<<num;
    return 0;
}//或者使用归并牌序or快速排序实现//*/
