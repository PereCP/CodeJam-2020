#include <iostream>
using namespace std;

int abs(int n) {
    if (n > 0) return n;
    else return -n;
}

int main() {
    int cases;
    cin >> cases;
    for (int x = 1; x <= cases; ++x) {
        cout << "Case #" << x << ": ";
        int a, b;
        cin >> a >> b;
        if (a%2 == b%2) cout << "IMPOSSIBLE" << endl;
        else {
            string out;
            if (a%2 == 1) {
                if (a > 0) {
                    if (abs(abs(a) - abs(b)) == 3) {
                        --a;
                        out.push_back('E');
                    }
                    else {
                        ++a;
                        out.push_back('W');
                    }
                }
                else {
                    if (abs(abs(a) - abs(b)) == 3) {
                        ++a;
                        out.push_back('W');
                    }
                    else {
                        --a;
                        out.push_back('E');
                    }
                }
            }
            else {
                if (b > 0) {
                    if (abs(abs(a) - abs(b)) == 3) {
                        --b;
                        out.push_back('N');
                    }
                    else {
                        ++b;
                        out.push_back('S');
                    }
                }
                else {
                    if (abs(abs(a) - abs(b)) == 3) {
                        ++b;
                        out.push_back('S');
                    }
                    else {
                        --b;
                        out.push_back('N');
                    }
                }
            }
            int num = 2;
            bool except = false;
            while (not except and not (a == 0 and b == 0)) {
                if (((a != 0) and (abs(a) < abs(b))) or (b == 0)) {
                    if (a > 0) {
                        except = num > a;
                        a -= num;
                        out.push_back('E');
                    }
                    else if (a < 0) {
                        except = num > -a;
                        a += num;
                        out.push_back('W');
                    }
                }
                else {
                    if (b > 0) {
                        except = num > b;
                        b -= num;
                        out.push_back('N');
                    }
                    else if (b < 0) {
                        except = num > -b;
                        b += num;
                        out.push_back('S');
                    }
                }
                num *= 2;
            }
            if (except) cout << "IMPOSSIBLE" << endl;
            else cout << out << endl;
        }
    }
}