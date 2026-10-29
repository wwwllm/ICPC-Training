#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> PIS;
const string str = "chatgpt";
const int N = 1e4 + 10;
void change(string &a)
{
    int len = a.length();
    for (int i = 0; i <= len; i++)
    {
        if (a[i] <= 'Z' && a[i] >= 'A')
        {
            a[i] = a[i] - 'A' + 'a';
        }
    }
}
map<string, int> mp;
PIS ans[N];
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int n;
    cin >> n;
    string x;
    getline(cin, x);
    for (int i = 1; i <= n; i++)
    {
        string id, s;
        getline(cin, id);
        getline(cin, s);
        change(s);
        int len = s.length();
        int cnt = 0;
        for (int j = 0; j <= len - 7; j++)
        {
            if (s.substr(j, 7) == str)
                cnt++;
        }
        mp[id] += cnt;
    }
    int top = 0;
    for (auto [id, cnt] : mp)
    {
        ans[++top] = {cnt, id};
    }
    sort(ans + 1, ans + 1 + top, [](const PIS &a, const PIS &b)
         { return a.first == b.first ? a.second < b.second : a.first > b.first; });
    for (int i = 1; i <= min(top, 3); i++)
    {
        auto [cnt, id] = ans[i];
        if (cnt == 0)
            break;
        cout << id << ' ' << cnt << endl;
    }
    return 0;
}