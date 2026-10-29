#include <bits/stdc++.h>
using namespace std;
 
signed main() {
    int n, h, m;
    cin >> n >> h >> m;
     
    string Date = to_string(h) + "-";
    if (m < 10) {
        Date += "0" + to_string(m);
    }else {
        Date += to_string(m);
    }
    set<string> A, B, C;
    while (n--) {
        string user, date, time;
        cin >> user >> date >> time;
        if (date.substr(0, 7) != Date) {
            continue;
        }
        string h = time.substr(0, 2);
        if (h == "07" || h == "08" || time == "09:00:00" ||
            h == "18" || h == "19" || time == "20:00:00") {
            A.insert(user);
        }
        if (h == "11" || h == "12" || time == "13:00:00") {
            B.insert(user);
        }
        if (h == "22" || h == "23" || h == "00" || time == "01:00:00") {
            C.insert(user);
        }
    }
    cout << A.size() << " " << B.size() << " " << C.size() << "\n";
}
