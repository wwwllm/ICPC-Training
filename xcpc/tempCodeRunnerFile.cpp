#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105922
const int N = 6666;
void solve()
{
    int cnt = 0;
    auto calc = [&](char c, string x, string y, string pc) -> string
    {
        string ok;
        cout << c << ' ' << x << ' ' << y << ' ' << pc << endl;
        cnt++;
        cin >> ok;
        return ok;
    };
    auto mod = [&](string x, string y, string tmp) -> void
    {
        // x=x%y
        calc('/', tmp, x, y);
        calc('*', tmp, tmp, y);
        calc('-', x, x, tmp);
    };
    auto swap = [&](string x, string y, string tmp) -> void
    {
        auto f = calc('-', tmp, tmp, tmp);
        f = calc('+', tmp, tmp, x);
        f = calc('-', x, x, x);
        f = calc('+', x, x, y);
        f = calc('-', y, y, y);
        f = calc('+', y, y, tmp);
        f = calc('-', tmp, tmp, tmp);
    };
    auto query = [&](string x, string y) -> string
    {
        cout << "? " << x << ' ' << y << endl;
        string c;
        cin >> c;
        return c;
    };
    auto answer = [&](string c)
    {
        cout << "! " << c << endl;
    };
    auto ff = [&]() -> string
    {
        string s;
        s = calc('/', "r0", "a", "b");
        s = calc('/', "r1", "c", "d");
        s = query("r0", "r1");
        bool ok = 0;
        while (s == "=" && cnt <= N / 2)
        {
            ok ^= 1;
            mod("a", "b", "r0");
            swap("a", "b", "r0");

            mod("c", "d", "r0");
            swap("c", "d", "r0");

            string sb, sd;
            if (sb == "=" && sd == "=")
            {
                s = "=";
                break;
            }
            else if (sb == "=")
            {
                s = ">";
                break;
            }
            else if (sd == "=")
            {
                s = "<";
                break;
            }

            s = calc('/', "r0", "a", "b");
            s = calc('/', "r1", "c", "d");
            s = query("r0", "r1");
        }
        if (s == "=")
        {
            s = calc('*', "r0", "a", "d");
            s = calc('*', "r1", "c", "b");
            s = query("r0", "r1");
        }
        if (ok)
        {
            if (s == ">")
                s = "<";
            else if (s == '<')
                s = ">";
        }
        return s;
    };
    answer(ff());
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}