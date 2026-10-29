#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n, t[N];
bool cmp(int a,int b){
    return a > b;
}
signed main(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> t[i];
    sort(t + 1, t + 1 + n,cmp);
    int ans = 0;
    for (int i = 1; i <= n;i++)
        ans += t[i] * (i - 1);
    cout << ans << endl;
    return 0;
}