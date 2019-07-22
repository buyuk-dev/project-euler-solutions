#include <iostream>
#include <vector>


using namespace std;


int factorial(int n)
{
    int f = 1, i = 1;
    while (++i <= n) f *= i;
    return f;
}


vector<int> factorialization(int n) {
    int k = 0;

    while (factorial(++k) < n);

    vector<int> v;
    while (k-- > 0) {
        int a = n / factorial(k);
        n -= a * factorial(k);
        v.push_back(a);
    }

    return v;
}


int main()
{
    int s = 10, n = 1000000;

    vector<int> S;
    for (int i = 0; i < s; ++i) S.push_back(i);

    for (int x: factorialization(n - 1)) {
        cout << S[x] << " ";
        S.erase(S.begin() + x);
    }

    cout << endl;
    return 0;
}
