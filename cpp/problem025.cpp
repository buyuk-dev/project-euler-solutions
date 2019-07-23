#include <iostream>
#include <cmath>


using namespace std;



int main() {
    // using fibonacci estimation equation: round(phi^n / sqrt(5))
    // floor(log(phi^n / sqrt(5)) + 1) = floor(log(phi^n) - log(sqrt(5))) + 1 =
    // = floor(n * log(phi) - log(sqrt(5))) + 1
    double n = 1000.0, k = 1.0;
    double r5 = sqrt(5.0);
    double phi = (r5 + 1.0) / 2.0;
    double lp = log10(phi);
    double lr5 = log10(r5);
    while (k * lp - lr5 + 1.0 < n) k++;
    cout << k << endl;
    return 0;    
}
