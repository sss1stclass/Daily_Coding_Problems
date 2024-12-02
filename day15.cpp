
#include <bits/stdc++.h>

using namespace std;

//void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
//    // set all non-zero elements as -1 in the row i:
//    for (int j = 0; j < m; j++) {
//        if (matrix[i][j] != 0) {
//            matrix[i][j] = -1;
//        }
//    }
//}
//
//
//void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
//    // set all non-zero elements as -1 in the col j:
//    for (int i = 0; i < n; i++) {
//        if (matrix[i][j] != 0) {
//            matrix[i][j] = -1;
//        }
//    }
//}
//
//vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
//
//    // Set -1 for rows and cols
//    // that contains 0. Don't mark any 0 as -1:
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (matrix[i][j] == 0) {
//                markRow(matrix, n, m, i);
//                markCol(matrix, n, m, j);
//            }
//        }
//    }
//
//    // Finally, mark all -1 as 0:
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (matrix[i][j] == -1) {
//                matrix[i][j] = 0;
//            }
//        }
//    }
//
//    return matrix;
//}




void setZeroes(vector<vector<int>> &matrix, int n, int m) {
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    for (auto it: matrix) {
        for (auto ele: it) {
            cout << ele << " ";
        }
        cout << endl;
    }
}

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    for (auto it: matrix) {
        for (auto ele: it) {
            cout << ele << " ";
        }
        cout << endl;
    }

}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 0, 6},
                                  {7, 8, 9}};
    int n = matrix.size();
    int m = matrix[0].size();
    setZeroes(matrix, n, m);
    return 0;
}

