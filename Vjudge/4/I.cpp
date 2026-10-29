#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2e5 + 50;
int a[maxn];
void solve()
{
    int n, h;
    cin >> n >> h;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int k = 0; k < 3;k++){
        int y1 = 2, y2 = 1;
        int power = h;
        for (int i = 1; i <= n;i++){
            if(power>a[i]){
                power += a[i] / 2;
            }else{
                while(power<=a[i]){
                    if(y1==k&&y2>0){
                        power *= 3;
                        y2--;
                    }else if(y1>0){
                        power *= 2;
                        y1--;
                    }else{
                        break;
                    }
                }
                if(power<=a[i]){
                    break;
                }
                power += a[i] / 2;
            }
            ans = max(i, ans);
        }
    }
    cout << ans << endl;
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
