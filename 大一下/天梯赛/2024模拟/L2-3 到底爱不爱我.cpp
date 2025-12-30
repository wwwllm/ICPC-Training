#include <bits/stdc++.h>

using namespace std;

// 1:&
// 2:|
// 3:!
const int N = 40;
struct Node
{
    int op, l, r;
} tr[N];
string v;
bool has_f[N];
int top = 0, root = -1;
bool dfs(int u)
{
    if (u == 0)
    {
        bool ans = v[top++] - '0';
        return ans;
    }
    auto [op, l, r] = tr[u];
    if (op == 3)
    {
        bool ans = dfs(l);
        return !ans;
    }
    else
    {
        bool ansl = dfs(l);
        bool ansr = dfs(r);
        if (op == 2)
            return ansl || ansr;
        else
            return ansl && ansr;
    }
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int op, l, r;
        cin >> op;
        if (op == 3)
        {
            cin >> l;
            tr[i] = {op, l, 0};
            has_f[l] = 1;
        }
        else
        {
            cin >> l >> r;
            tr[i] = {op, l, r};
            has_f[l] = 1, has_f[r] = 1;
        }
    }
    root = -1;
    for (int i = 1; i <= n; i++)
        if (!has_f[i])
        {
            root = i;
            break;
        }
    int k;
    cin >> k;
    getline(cin, v);
    while (k--)
    {
        getline(cin, v);
        top = 0;
        if (dfs(root))
            cout << "Ai" << endl;
        else
            cout << "BuAi" << endl;
    }
    return 0;
}