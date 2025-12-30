#include <bits/stdc++.h>
using namespace std;

vector<int> sub(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    for (int i = 0, t = 0; i < a.size(); i++)
    {
        t = a[i] - t;
        if (i < b.size())
            t -= b[i];
        ans.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    while (ans.size() > 1 && !ans.back())
        ans.pop_back();
    return ans;
}
bool cmp(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return true;
}
int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    if (cmp(A, B))
    {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--)
            cout << C[i];
    }
    else
    {
        auto C = sub(B, A);
        cout << '-';
        for (int i = C.size() - 1; i >= 0; i--)
            cout << C[i];
    }
    return 0;
}