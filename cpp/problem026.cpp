#include <vector>
#include <iostream>


using namespace std;

vector<int> prime_sieve(int n) {
    vector<bool> isprime(n+1, true);
    isprime[0] = isprime[1] = false;

    int div = 0;
    do {
        while (!isprime[++div]);
        for (int i = 2 * div; i < isprime.size(); i += div) {
            isprime[i] = false;
        }
    } while (div * div <= isprime.size());

    vector<int> primes;
    for (int i = 0; i < isprime.size(); ++i) {
        if (isprime[i]) {
           primes.push_back(i);
        }
    }
    return primes;
}

int find_length(int d) {
    int c = 1;
    if (d < 8) return 3;
    int mod = 10 % d;
    do {
        if (mod == 1) return c;
        mod = ((mod % d) * (10 % d)) % d;
        c ++;
    } while (true);
    return -1;
}

int main() {
    auto primes = prime_sieve(1000);
    int max = 0, maxn = 0;
    for (int p: primes) {
        int length = find_length(p);
        if (length > max) {
            max = length;
            maxn = p;
        }
    }
    cout << maxn << " " << max << endl;
    return 0;
}

