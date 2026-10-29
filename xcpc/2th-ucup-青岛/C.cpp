#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector vis(n, vector<int>(256));
    struct option
    {
        string nme;
        int v;
        int addr;
    };
    vector<option> op(n);
    for (auto &[name, v, k] : op)
    {
        cin >> name >> v;
        if (name != "add")
            cin >> k, k--;
    }
    int pc = 0;
    int r = 0;
    while (1)
    {
        if (pc == n)
        {
            break;
        }
        if (vis[pc][r])
        {
            cout << "No\n";
            return;
        }
        vis[pc][r] = 1;
        auto [na, v, k] = op[pc];
        if (na == "add")
        {
            (r += v) %= 256;
            pc++;
        }
        else if (na == "beq")
        {
            pc = v == r ? k : pc + 1;
        }
        else if (na == "bne")
        {
            pc = v == r ? pc + 1 : k;
        }
        else if (na == "blt")
        {
            pc = r < v ? k : pc + 1;
        }
        else if (na == "bgt")
        {
            pc = r > v ? k : pc + 1;
        }
    }
    cout << "Yes\n";
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}