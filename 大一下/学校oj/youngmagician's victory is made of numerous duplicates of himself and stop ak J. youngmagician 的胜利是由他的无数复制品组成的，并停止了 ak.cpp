#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = (1 << 20) + 10;
int a[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= (1<<n);i++){
        cin >> a[i];
    }
    bool flag = 0;//有1
    while(!flag&&n>-1){
        int top = 0;
        n--;
        flag = 1;
        for (int i = 1; i <= (1 << n);i++){
            if(a[2*i-1]==1&&a[2*i]==1)
                a[++top] = 1,flag=0;
            else
                a[++top] = 2;
        }
    }
    int ans = 1 << (n+1);
    cout << "we are top " << ans << " !" << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //    cin >> t;
    while (t--)
        solve();
    return 0;
}
