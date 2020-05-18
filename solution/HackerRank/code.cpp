#include <cstdlib>


int checkMatrixIdentity(int* arr, int m_arr, int n_arr) {
    for (int i = 0; i < m_arr; ++i) {
        for (int j = 0; j < n_arr; ++j) {
            if (i == j) {
                if (*arr != 1)
                    return 0;
            }
            else if (*arr != 0)
                return 0;
            ++arr;
        }
    }
    return 1;
}


int* transMatrix(int* arr, int m_arr, int n_arr) {
    int n = n_arr*m_arr;
    int* ans = new int[n];
    for (int i = 0; i < m_arr; ++i)
        for (int j = 0; j < n_arr; ++j) {
            ans[j*m_arr + i] = *arr;
            ++arr;
        }
    return ans;
}


int* plusMatrix(int* arr1, int m_arr1, int n_arr1,
                int* arr2, int m_arr2, int n_arr2)
{
    if (m_arr1 != m_arr2 || n_arr1 != n_arr2)
        return NULL;
    int* ans = new int[m_arr1*n_arr1];
    int* p = ans;
    for (int i = 0; i < m_arr1; ++i)
        for (int j = 0; j < n_arr1; ++j) {
            *ans = *arr1 + *arr2;
            ++ans;
            ++arr1;
            ++arr2;
        }
    return p;
}


int* multiMatrixConst(int* arr, int m_arr, int n_arr, int val)
{
    int* ans = new int[m_arr*n_arr];
    int* p = ans;
    for (int i = 0; i < m_arr; ++i)
        for (int j = 0; j < n_arr; ++j) {
            *ans = (*arr) * val;
            ++ans;
            ++arr;
        }
    return p;
}


int main() {
    
    return 0;
}
