#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int k;
    cin >> k;
    int y = 1;
    for (int i = 1; i <= 21;i++){
        y *= i;
    }
    cout << k << '\n'
         << y << '\n';
    return 0;
}