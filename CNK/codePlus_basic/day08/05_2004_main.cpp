/*
조합 0의 개수
https://www.acmicpc.net/problem/2004
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, m, t, f;   // 인수 2, 인수 5 개수
    t = f = 0LL;
    cin >> n >> m;    
    
    // 2의 배수
    for(long long i = 2; i <= n; i*=2) {
        t += n/i;
    }
    for(long long i = 2; i <= (n-m); i*=2) {
        t -= (n-m)/i;
    }
    for(long long i = 2; i <= m; i*=2) {
        t -= m/i;
    }

    // 5의 배수
    for(long long i = 5; i <= n; i*=5) {
        f += n/i;
    }
    for(long long i = 5; i <= (n-m); i*=5) {
        f -= (n-m)/i;
    }
    for(long long i = 5; i <= m; i*=5) {
        f -= m/i;
    }
    cout << min(t, f) << "\n";
    return 0;
}