#include <iostream>
#include <vector>
using namespace std;

bool byte(int n, int& times) {
    cout << n << endl;
    char c;
    cin >> c;
    ++times;
    return c == '1';
}

bool fluc(int times) {
    return times%10 == 1;
}

void complement(vector<bool>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) v[i] = not v[i];
}

void reverse(vector<bool>& v) {
    int iz = 0;
    int de = v.size() - 1;
    while (iz < de) {
        bool aux = v[iz];
        v[iz] = v[de];
        v[de] = aux;
    }
}

bool print_result(const vector<bool>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i]) cout << '1';
        else cout << '0';
    }
    cout << endl;
    char c;
    cin >> c;
    return c == 'Y';
}

int main() {
    int cases, b;
    cin >> cases >> b;
    for (int x = 1; x <= cases; ++x) {
        int aux;
        vector<bool> v(b, false);
        int t = 1;
        int iz = 1;
        int de = b;
        bool comp = false;
        bool diff = false;
        pair<int, int> c, d;
        while (not (comp and diff) and iz < de) {
            bool prevc = comp;
            bool prevd = diff;
            bool a = byte(iz, t);
            bool b = byte(de, t);
            comp = a == b;
            diff = a != b;
            if (comp and not prevc) {
                c.first = iz;
                c.second = de;
            }
            if (diff and not prevd) {
                d.first = iz;
                d.second = de;
            }
            ++iz;
            --de;
        }
        if (t%10 > 7 or t%10 == 0 or t%10 == 1) bool trash = byte(1, t);
        if (comp) {
            v[c.first-1] = byte(c.first, t);
            v[c.second-1] = byte(c.second, t);
        }
        if (diff) {
            v[d.first-1] = byte(d.first, t);
            v[d.second-1] = byte(d.second, t);
        }
        iz = 0;
        while (iz < b) {
            if (fluc(t)) {
                if (diff) {
                    bool test = byte(c.first, t);
                    bool needs_compl = v[c.first-1] != test;
                    bool needs_rev;
                    bool test1 = byte(d.first, t);
                    if (needs_compl) {
                        needs_rev = v[d.first-1] == test1;
                    }
                    else {
                        needs_rev = v[d.first-1] != test1;
                    }
                    if (needs_compl) complement(v);
                    if (needs_rev) reverse(v);
                }
                else if (comp and not diff) {
                    bool test = byte(c.first, t);
                    if (test != v[c.first-1]) {
                        complement(v);
                    }
                }
            }
            v[iz] = byte(iz+1, t);
            ++iz;
        }
        if (not print_result(v)) break;
    }
}