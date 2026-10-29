#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<string> s(n);
    auto spilt = [&](string &s)
    {
        int len = s.size();
        string tmp = "";
        vector<string> res;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == ' ')
            {
                res.push_back(tmp);
                tmp = "";
            }
            else
            {
                tmp += s[i];
            }
        }
        if (tmp != "")
            res.push_back(tmp);

        return res;
    };
    vector<vector<string>> name;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
        auto res = spilt(s[i]);
        name.push_back(res);
        len = max(len, (int)res.size());
    }
    vector cur(n, vector<string>());
    map<vector<string>, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (auto word : name[i])
        {
            string tmp = "";
            tmp += word[0];
            cur[i].push_back(tmp);
        }
        mp[cur[i]]++;
    }
    for (int i = 0; i < len; i++)
    {
        auto pre = mp; 

        for (int j = 0; j < n; j++)
        {
            if (pre[cur[j]] != 1)
            {
                if (cur[j].size() > i)
                {
                    mp[cur[j]]--;
                    cur[j][i] = name[j][i];
                    mp[cur[j]]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto word : cur[i])
        {
            cout << word;
        }
        cout << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}