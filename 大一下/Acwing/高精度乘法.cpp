#include <bits/stdc++.h>
using namespace std;

vector<int> mul(vector<int> &a,int b){
    vector<int> ans;
    for (int i = 0,t=0; i < a.size()||t;i++){
        if(i<a.size())t += a[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while (ans.size() > 1 && !ans.back())
        ans.pop_back();
    return ans;
} 
int main()
{
    int b;
    string a;
    cin >> a>>b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    return 0;
}