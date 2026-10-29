#include<bits/stdc++.h>
using namespace std;

const int N=105;
double p[N];
int num[N];
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin >> p[i];
    int cnt,pos;
    while(cin>>pos>>cnt,pos){
        num[pos] += cnt;
    }
    double ans = 0;
    for(int i=1;i<=n;i++)
        cout << num[i] << endl,ans+=num[i]*p[i];
    cout <<fixed<<setprecision(2)<< ans << endl;
    return 0;
}