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
    auto query = [&](string x, string y) -> string
    {
        cout << "? " << x << ' ' << y << endl;
        string c;
        cin >> c;
        cnt++;
        return c;
    };
    auto answer = [&](string c)
    {
        cout << "! " << c << endl;
    };
    auto ff = [&]() -> string
    {
        string a = "a", b = "b", c = "c", d = "d";
        string qa = "r0", qc = "r1";
        string s;
        s = calc('/', qa, a, b);
        s = calc('/', qc, c, d);
        s = query("r0", "r1");
        bool ok = 0;
        while (s == "=" && cnt + 12 <= N)
        {
            ok ^= 1;
            calc('*', qa, qa, b);
            calc('-', a, a, qa);

            calc('*', qc, qc, d);
            calc('-', c, c, qc);
            swap(a, b);
            swap(c, d);

            string sb = query(b, "r3");
            string sd = query(d, "r3");
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

            s = calc('/', qa, a, b);
            s = calc('/', qc, c, d);
            s = query(qa, qc);
        }
        if (s == "=")
        {
            s = calc('*', qa, a, d);
            s = calc('*', qc, c, b);
            s = query(qa, qc);
        }
        if (ok)
        {
            if (s == ">")
                s = "<";
            else if (s == "<")
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