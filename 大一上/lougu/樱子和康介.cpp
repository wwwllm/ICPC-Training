#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        if(m%2==1)cout<<"Kosuke";
        else    cout<<"Sakurako"; 
    }
    return 0;
}
