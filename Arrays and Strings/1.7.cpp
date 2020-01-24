#include <bits/stdc++.h>

using namespace std;

void rotateClockwise(vector<vector<int>> &v) {
    //find transpose
    //then swap elements from each ends of each row
    int rows = v.size();
    int cols = v[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = i; j < cols; j++)
            swap(v[i][j], v[j][i]);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++)
            swap(v[i][j], v[i][cols - j - 1]);
    }
}

void rotateClockwise2(vector<vector<int>> &v) {
    reverse(v.begin(), v.end());
    //for anticlockwise first reverse each row then swap symmetrically
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v[0].size(); j++)
            swap(v[i][j], v[j][i]);
    }
}

int main() {
    vector<vector<int>> v{{1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}};
    rotateClockwise2(v);
    int rows = v.size();
    int cols = v[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;

    }
    return 0;
}