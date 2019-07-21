#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool in_bound(int i, int j, int mini, int maxi, int minj, int maxj) {
    return mini > i || i >= maxi || minj > j || j >= maxj;
}


int product(const vector<vector<int>>& M, int i, int j, int rd, int cd, int n, int k)
{
    int prod = M[i][j];
    for (int l = 1; l < k; ++l) {
        if (in_bound(i += rd, j += cd, 0, n, 0, n)) {
            return -1;
        }
        prod *= M[i][j];
    }
    return prod;
}


int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
        }
    }

    int max = -1;
    for (int i = 0; i < n-k; ++i) {
        for (int j = 0; j < n-k; ++j) {
            vector<int> temp = {
                max,
                product(M, i, j, 1, -1, n, k),
                product(M, i, j, 1, 0, n, k),  
                product(M, i, j, 1, 1, n, k),
                product(M, i, j, 0, 1, n, k)
            };
            max = *max_element(begin(temp), end(temp));
        }
    }

    cout << "max product = " << max << endl;
    return 0;
}
