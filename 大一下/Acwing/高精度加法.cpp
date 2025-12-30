#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> &a, vector<int> &b)
{
    int len = max(a.size(), b.size());
    vector<int> ans;
    int x = 0;
    for (int i = 0; i < len; i++)
    {
        if (i < a.size())
            x += a[i];
        if (i < b.size())
            x += b[i];
        ans.push_back(x % 10);
        x /= 10;
    }
    if(x)
        ans.push_back(x);
    return ans;
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
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    return 0;
}