#include <iostream>
#include <list>
using namespace std;

typedef pair<int, int> card;

void print_list(const list<card>& l) {
    for (list<card>::const_iterator it = l.begin(); it != l.end(); ++it) {
        cout << (*it).first << ' ' << (*it).second << endl;
    }
}

void genlist(list<card>& l, int r, int s) {
    for (int i = 1; i <= s; ++i) {
        for (int j = 1; j <= r; ++j) {
            l.push_front(pair<int, int>(j, i));
        }
    }
}


int main() {
    int cases;
    cin >> cases;
    for (int x = 1; x <= cases; ++x) {
        cout << "Case #" << x << ": ";
        int r, s;
        cin >> r >> s;
        int total = r * s;
        list<card> l;
        genlist(l, r, s);
        int k = 1;
        bool finish = false;
        list<card>::reverse_iterator pos = l.rbegin();
        int moves = 0;
        if (r == 0 or s == 0) cout << 0 << endl;
        else {
            string out;
            while (not finish) {
                int i = 1;
                list<card>::iterator it = l.begin();
                while ((*it).first != k) {
                    ++i;
                    ++it;
                }
                ++it;
                list<card> a;
                a.splice(a.begin(), l, l.begin(), it);
                int j = 0;
                list<card>::reverse_iterator rit = pos;
                while ((*rit).first == k) {
                    ++j;
                    ++rit;
                }
                j = l.size() - j - (k-1)*s;
                it = l.begin();
                advance(it, j);
                list<card> b;
                b.splice(b.begin(), l, l.begin(), it);
                l.splice(l.begin(), a, a.begin(), a.end());
                l.splice(l.begin(), b, b.begin(), b.end());
                int num = 0;
                rit = pos;
                while ((*rit).first == k) {
                    ++num;
                    ++rit;
                }
                if (num == s) {
                    ++k;
                    pos = rit;
                }
                finish = k == r;
                ++moves;
                out.push_back(char(i + int('0')));
                out.push_back(char(j + int('0')));
            }
            cout << moves << endl;
            int n = out.length();
            for (int i = 0; i < n; i += 2) cout << out[i] << ' ' << out[i + 1] << endl;
        }
    }
}