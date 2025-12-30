#include <bits/stdc++.h>
using namespace std;

vector<int> div(vector<int> &a, int b, int &r)
{
    vector<int> ans;
    r = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        r = r * 10 + a[i];
        ans.push_back(r / b);
        r %= b;
    }
    reverse(ans.begin(), ans.end()); // 把数组反一下
    while (ans.size() > 1 && !ans.back())
        ans.pop_back();
    return ans;
}
int main()
{
    int b;
    string a;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    int mod = 0;
    auto C = div(A, b, mod);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl
         << mod << endl;
    return 0;
}