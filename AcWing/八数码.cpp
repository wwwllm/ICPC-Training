#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const string T = "12345678x";
queue<string> q;
unordered_map<string, int> d;
PII sw[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
signed main()
{
    string s;
    for (int i = 1; i <= 9; i++)
    {
        char c;
        cin >> c;
        s += c;
    }
    q.push(s);
    d[s] = 0;
    while (!q.empty())
    {
        auto t = q.front();
        if (t == T)
        {
            cout << d[t] << endl;
            return 0;
        }
        int dt = d[t], p = t.find('x');
        int y0 = p / 3, x0 = p % 3;
        q.pop();
        for (auto [x, y] : sw)
        {
            int xx = x0 + x, yy = y0 + y;
            if (xx >= 0 && xx <= 2 && yy >= 0 && yy <= 2)
            {
                swap(t[xx + yy * 3], t[p]);
                if (!d.count(t))
                {
                    d[t] = dt + 1;
                    q.push(t);
                }
                swap(t[xx + yy * 3], t[p]);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}