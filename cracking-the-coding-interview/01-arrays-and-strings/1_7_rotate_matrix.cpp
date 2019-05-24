#include <iostream>
#include <vector>
using namespace std;

void RotateElement(vector<vector<int>> &matrix, int y, int x) {
    const int n = matrix.size();

    int temp = matrix[y][x];
    matrix[y][x] = matrix[n-x-1][y];
    matrix[n-x-1][y] = matrix[n-y-1][n-x-1];
    matrix[n-y-1][n-x-1] = matrix[x][n-y-1];
    matrix[x][n-y-1] = temp;
}

void RotateMatrix(vector<vector<int>> &matrix) {
    const int n = matrix.size();

    int y = 0;
    int x_start = 0;
    int x_end = n-2;

    while (x_start < x_end) {
        for (int x = x_start; x <= x_end; ++x) {
            int temp = matrix[y][x];
            RotateElement(matrix, y, x);
        }
        ++x_start;
        --x_end;
        ++y;
    }
}

int main() {
    vector<vector<int>> matrix;

    matrix.push_back(vector<int>(3,1));
    matrix.push_back(vector<int>(3,2));
    matrix.push_back(vector<int>(3,3));

    RotateMatrix(matrix);

    for (auto it1 : matrix) {
        for (auto it2: it1) {
            cout << it2 << " ";
        }
        cout << "\n";
    }

    return 0;
}

