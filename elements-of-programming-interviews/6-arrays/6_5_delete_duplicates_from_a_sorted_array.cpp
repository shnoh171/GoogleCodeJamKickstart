#include <vector>
using std::vector;

int DeleteDuplicates(vector<int>* A_ptr) {
    int read_index = 0, write_index = 0;
    int size = A_ptr->size();
    vector<int>& A = *A_ptr;
    int prev;

    while (read_index < size) {
        if (read_index == 0) {
            prev = A[read_index];
            ++read_index;
            ++write_index;
        } else {
            if (A[read_index] != prev) {
                A[write_index++] = A[read_index];
                prev = A[read_index];
            }   
            ++read_index;
        }   
    }   

    return write_index;
}

/* Solution */
int DeleteDuplicatesSolution(vector<int> *A_ptr) {
    vector<int> &A = *A_ptr;
    if (empty(A)) {
        return 0;
    }

    int write_index = 1;
    for (int i = 1; i < size(A); ++i) {
        if (A[write_index - 1] != A[i]) {
            A[write_index++] = A[i];
        }
    }
    return write_index;
}