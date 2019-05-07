#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

#define LAST_NUM 1000

using namespace std;

unsigned char sieve[(LAST_NUM + 7) / 8 + 1];

bool isPrime(int k) {
    return sieve[k >> 3] & (1 << (k & 7));
}

void setComposite(int k) {
    sieve[k >> 3] &= ~(1 << (k & 7));
}

void eratosthenes() {
    memset(sieve, 255, sizeof(sieve));
    setComposite(0);
    setComposite(1);
    int sqrtn = int(sqrt(LAST_NUM));
    for (int i = 2; i <= sqrtn; i++)
        if (isPrime(i))
            for (int j = i * i; j <= LAST_NUM; j += i)
                setComposite(j);
}

int main() {
    eratosthenes();
    for (int i = 0; i <= LAST_NUM; i++) {
        if (isPrime(i))
            printf("%d\n", i);
    }
    return 0;
}
