// quadratic primes

#include <vector>
#include <iostream>

using namespace std;

vector<bool> prime_sieve(int n) {
    vector<bool> isprime(n+1, true);
    isprime[0] = isprime[1] = false;

    int div = 0;
    do {
        while (!isprime[++div]);
        for (int i = 2 * div; i < isprime.size(); i += div) {
            isprime[i] = false;
        }
    } while (div * div <= isprime.size());

    return isprime;
}


int main()
{
    int a_min = -1000, a_max = 1000;
    int b_min = -1000, b_max = 1000;
    int prime_max = 100000;

    auto _is_prime = prime_sieve(prime_max);
    auto is_prime = [&_is_prime](int n) -> bool { return n > 0 && _is_prime[n]; };

    int L = 0, A = 0, B = 0;
    for (int b=b_min; b <= b_max; ++b) {
        if (!is_prime(b)) {
            continue;
        }

        for (int a = a_min; a <= a_max; ++a) {
            int n =1;
            while (is_prime(n*n + a*n + b)) {
                n++;
            }

            if (n > L) {
                L = n;
                A = a;
                B = b;
            }
        }
    }

    cout << A * B << endl;

    return 0;
}
