#include <iostream>
#include <vector>
using namespace std;

bool is_magic_square(const vector<vector<int>>& matrix) {
    int n = matrix.size();

    
    int reference_sum = 0;
    for (int j = 0; j < n; j++) {
        reference_sum += matrix[0][j];
    }

    
    for (int i = 1; i < n; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += matrix[i][j];
        }
        if (row_sum != reference_sum) {
            return false;
        }
    }

    
    for (int j = 0; j < n; j++) {
        int col_sum = 0;
        for (int i = 0; i < n; i++) {
            col_sum += matrix[i][j];
        }
        if (col_sum != reference_sum) {
            return false;
        }
    }

    
    int main_diag_sum = 0;
    for (int i = 0; i < n; i++) {
        main_diag_sum += matrix[i][i];
    }
    if (main_diag_sum != reference_sum) {
        return false;
    }

    
    int secondary_diag_sum = 0;
    for (int i = 0; i < n; i++) {
        secondary_diag_sum += matrix[i][n - i - 1];
    }
    if (secondary_diag_sum != reference_sum) {
        return false;
    }

    
    return true;
}

int main() {
    vector<vector<int>> matrix = {
        {16, 3, 2, 13},
        {5, 10, 11, 8},
        {9, 6, 7, 12},
        {4, 15, 14, 1}
    };

    bool is_magic = is_magic_square(matrix);
    if (is_magic) {
        cout << "It's a magic square!" << endl;
    } else {
        cout << "It's NOT a magic square." << endl;
    }

    return 0;
   }
