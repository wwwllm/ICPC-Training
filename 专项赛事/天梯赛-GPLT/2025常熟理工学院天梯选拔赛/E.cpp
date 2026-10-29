#include <bits/stdc++.h>
#define ll long long
using namespace std;


signed main()
{
    string s;
    getline(cin, s);
    string op;
    ll len = s.length();
    ll pos = s.length();
    while (cin >> op)
    {
        if (op == "CTRL")
        {
            string opp;
            cin >> opp;
            if (opp == "S")
                cout << s << endl;
            else
            {
                int x = 0;
                for (int i = 1; i < opp.size(); i++)//x可能大于10，赛时忘记了
                    x = x * 10 + opp[i] - '0';
                char c = s[pos - 1];
                s.insert(pos, x, c);
                len += x;
                pos += x;
            }
        }
        else if (op == "LEFT")
            pos = max(0ll, pos - 1);
        else
            pos = min(len, pos + 1);
    }
    cout << s << endl;
    return 0;
}
