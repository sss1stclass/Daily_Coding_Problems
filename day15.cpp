
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
        for (int j = i + 1; j < n; j++) {
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

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;
    vector<int> ans;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
//    for (auto it: ans) {
//        cout << it << " ";
//    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {{5,  1,  9,  11},
                                  {2,  4,  8,  10},
                                  {13, 3,  6,  7},
                                  {15, 14, 12, 16}};
    int n = matrix.size();
    int m = matrix[0].size();
//    setZeroes(matrix, n, m);
//    rotate(matrix);
//    spiralOrder(matrix);
    cout << matrix[1][0];
    return 0;
}

