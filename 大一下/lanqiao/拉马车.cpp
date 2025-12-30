#include <bits/stdc++.h>
using namespace std;

stack<char> S;
bool f[128];
deque<char> a, b;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
        a.push_back(s1[i]);
    for (int i = 0; i < s2.length(); i++)
        b.push_back(s2[i]);
    int time = 0;
    bool flag = 1;
    S.push(a.front());
    f[a.front()] = 1;
    a.pop_front();
    while (time <= 10000 && !a.empty() && !b.empty())
    {
        if (flag)
        {
            auto it = b.front();
            if (f[it])
            {
                b.pop_front();
                b.push_back(it);
                while (!S.empty() && S.top() != it)
                {
                    b.push_back(S.top());
                    f[S.top()] = 0;
                    S.pop();
                }
                b.push_back(S.top());
                f[S.top()] = 0;
                S.pop();
            }
            else
            {
                S.push(b.front());
                f[b.front()] = 1;
                b.pop_front();
                flag = !flag;
            }
        }
        else
        {
            auto it = a.front();
            if (f[it])
            {
                a.pop_front();
                a.push_back(it);
                while (!S.empty() && S.top() != it)
                {
                    a.push_back(S.top());
                    f[S.top()] = 0;
                    S.pop();
                }
                a.push_back(S.top());
                f[S.top()] = 0;
                S.pop();
            }
            else
            {
                S.push(a.front());
                f[a.front()] = 1;
                a.pop_front();
                flag = !flag;
            }
        }
        time++;
    }
    if (time > 10000)
        cout << -1 << endl;
    else
    {
        if (a.empty())
        {
            while (!b.empty())
            {
                cout << b.front();
                b.pop_front();
            }
            cout << endl;
        }
        else
        {
            while (!a.empty())
            {
                cout << a.front();
                a.pop_front();
            }
            cout << endl;
        }
    }
    return 0;
}