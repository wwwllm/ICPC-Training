#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> PSI;
signed main()
{
    int t;
    cin >> t;
    map<string, int> mp;
    queue<PSI> q;
    q.push({"123456789", 0});
    mp["123456789"] = 0;
    array<int, 4> pos = {0, 1, 3, 4};
    while (q.size())
    {
        auto [s, cnt] = q.front();
        q.pop();
        for (auto st : pos)
        {
            string tmp = s;
            char c = tmp[st];
            tmp[st] = tmp[st + 1];
            tmp[st + 1] = tmp[st + 4];
            tmp[st + 4] = tmp[st + 3];
            tmp[st + 3] = c;
            //cout << tmp << '\n';
            if (mp.find(tmp) == mp.end())
            {
                mp[tmp] = cnt + 1;
                q.push({tmp, cnt + 1});
            }
        }
    }
    while (t--)
    {
        string s = "";
        for (int i = 1; i <= 9; i++)
        {
            int x;
            cin >> x;
            s += '0' + x;
        }
        cout << mp[s] << '\n';
    }
}