#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool comp(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    if (a.first.first == b.first.first) return a.first.second < b.first.second;
    return a.first.first < b.first.first;
}

bool safe(const list<pair<int, int> >& l, const pair<int, int>& n) {
    list<pair<int, int> >::const_iterator end = l.end();
    for (list<pair<int, int> >::const_iterator it = l.begin(); it != end; ++it) {
        if (not (((*it).second <= n.first) or (n.second <= (*it).first))) return false;
    }
    return true;
}

int main() {
    int cases;
    cin >> cases;
    for (int x = 1; x <= cases; ++x) {
        cout << "Case #" << x << ": ";
        list<pair<int, int> > c, j;
        list<pair<pair<int, int>, int> > l;
        int n;
        cin >> n;
        vector<char> output(n);
        bool abort = false;
        for (int i = 0; i < n; ++i) {
            pair<pair<int, int>, int> p;
            p.second = i;
            cin >> p.first.first >> p.first.second;
            l.insert(l.end(), p);
        }
        l.sort(comp);
        list<pair<pair<int, int>, int> >::const_iterator end = l.end();
        for (list<pair<pair<int, int>, int> >::const_iterator it = l.begin(); it != end; ++it) {
            pair<int, int> p = (*it).first;
            if (safe(c, p)) {
                c.insert(c.end(), p);
                output[(*it).second] = 'C';
            }
            else if (safe(j, p)) {
                j.insert(j.end(), p);
                output[(*it).second] = 'J';
            }
            else {
                abort = true;
                break;
            }
        }
        if (abort) cout << "IMPOSSIBLE";
        else for (int i = 0; i < n; ++i) cout << output[i];
        cout << endl;
    }
}