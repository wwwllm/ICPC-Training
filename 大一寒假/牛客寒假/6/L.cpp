#include <bits/stdc++.h>
//#define int long long
using namespace std;

//chicken
const int maxn = 1e5 + 50;
char a[maxn];
int c[26];
const string s = "CHICKEN";
void solve()
{
    int n;
    cin >> n;
    memset(c, 0, sizeof(c));
    int maxt = 0;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int top = 0;
    for (int i = 1; i <= n;i++){
        if(a[i]==s[top]&&top<=7){
            top++;
        }else{
            c[a[i]-'A']++;
            maxt = max(maxt, c[a[i] - 'A']);
        }
    }
    if(n%2==1&&top==7&&maxt<=(n-7)/2)cout<<"YES"<<endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
