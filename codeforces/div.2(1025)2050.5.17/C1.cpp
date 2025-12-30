#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, op;
    cin >> n;
    cout << "mul 3" << endl;
    cin >> op;
    cout << "digit" << endl;
    cin >> op;
    cout << "digit" << endl;
    cin >> op;
    cout << "digit" << endl;
    cin >> op;

    cout << "add -3" << endl;
    cin >> op;
    if (op == 0)
    {
        cout << "add -2" << endl;
        cin >> op;
        cout << "add " << n - 1 << endl;
        cin >> op;
        cout << "!" << endl;
        cin >> op;
    }
    else
    {
        cout << "add -3" << endl;
        cin >> op;
        cout << "add " << n - 3 << endl;
        cin >> op;
        cout << "!" << endl;
        cin >> op;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
