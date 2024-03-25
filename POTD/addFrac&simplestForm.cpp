#include <iostream>
#include <vector>

using namespace std;

int finGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return finGCD(b, a % b);
}

vector<long long int> addFraction(int a, int b, int c, int d) {
    vector<long long int> result;
    int num = (a * d) + (b * c);
    int denom = (b * d);
    int gcd = finGCD(num, denom);
    num /= gcd;
    denom /= gcd;
    result.push_back(num);
    result.push_back(denom);
    return result;
}

int main() {
    int a = 1, b = 2, c = 1, d = 3;
    vector<long long int> result = addFraction(a, b, c, d);

    cout << "Result: " << result[0] << "/" << result[1] << endl;

    return 0;
}
