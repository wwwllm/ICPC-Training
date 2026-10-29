#include <bits/stdc++.h>
using namespace std;

//将分数小的人排在前面，取出来放大的上面
struct peo{
    int b, pos;
};
const int maxn = 2e5 + 50;
peo s[maxn];
bool cmp(peo a,peo b){
    return a.b < b.b;
}
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int manum = n / m + 1, mat = n % m, minum = n / m, mit = m - n % m;
    for (int i = 1; i <= n;i++){
        s[i].b = 0;
        s[i].pos = i;
    }
    while(k--){
        sort(s + 1, s + 1 + n, cmp);
        int x = 1;
        for (int i = 1; i <= mat;i++){
            cout << manum << " ";
            for (int j=1; j <= manum;j++){
                cout << s[x].pos << ' ';
                s[x].b++;
                x++;
            }
            cout << endl;
        }
        for (int i = 1; i <= mit; i++)
        {
            cout << minum << " ";
            for (int j=1; j <= minum; j++)
            {
                cout << s[x].pos << ' ';
                x++;
            }
            cout << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
    return 0;
}
