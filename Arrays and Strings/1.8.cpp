#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

//slow straightforward solution
void setZeroes0(vector<vector<int>> &matrix) {
    unordered_set<int> r, c;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                r.insert(i);
                c.insert(j);
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (r.find(i) != r.end()) {
                matrix[i][j] = 0;
            }
            if (c.find(j) != c.end()) {
                matrix[i][j] = 0;
            }
        }
    }
}

//O(1) space solution
void setZeroes1(vector<vector<int>> &matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    bool r1 = false;
    bool c1 = false;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 0) {
                if (i == 0)
                    r1 = true;
                if (j == 0)
                    c1 = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (matrix[i][0] == 0 or matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if (r1) {
        for (int i = 0; i < c; i++)
            matrix[0][i] = 0;
    }
    if (c1) {
        for (int j = 0; j < r; j++)
            matrix[j][0] = 0;
    }
}

int main() {
    vector<vector<int>> v{{1, 0},
                          {2, 5}};
    setZeroes0(v);
    setZeroes1(v);
    return 0;
}