#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matrix;

int main() {
    int cases;
    cin >> cases;
    for (int x = 1; x <= cases; ++x) {
        int trace, rows, cols, n;
        trace = rows = cols = 0;
        cin >> n;
        Matrix m(n, Fila(n));
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
        int k = 0;
        while (k < n) {
            trace += m[k][k];
            ++k;
        }
        for (int i = 0; i < n; ++i) {
            vector<bool> row(n+1, false);
            for (int j = 0; j < n; ++j) {
                if (row[m[i][j]]) {
                    ++rows;
                    break;
                }
                else row[m[i][j]] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            vector<bool> col(n+1, false);
            for (int i = 0; i < n; ++i) {
                if (col[m[i][j]]) {
                    ++cols;
                    break;
                }
                else col[m[i][j]] = true;
            }
        }
        cout << "Case #" << x << ": " << trace << ' ' << rows << ' ' << cols << endl;
    }
}