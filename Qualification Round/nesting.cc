#include <iostream>
#include <string>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int x = 1; x <= cases; ++x) {
        cout << "Case #" << x << ": ";
        string s;
        cin >> s;
        int lim = s.size();
        int n = 0;
        for (int i = 0; i < lim; ++i) {
            int num = s[i] - '0';
            if (num > n) {
                for (int k = n; k < num; ++k) cout << '(';
            }
            else if (num < n) {
                for (int k = n; k > num; --k) cout << ')';
            }
            n = num;
            cout << num;
        }
        if (n != 0) for (int i = 0; i < n; ++i) cout << ')';
        cout << endl;
    }
}