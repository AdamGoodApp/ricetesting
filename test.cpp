#include "rice/Class.hpp"

using namespace Rice;

int rice_fibonacci(int n) {
  int a = 1, b = 1, c, i;
  if (n == 0) {
    return 0;
  }
  for (i = 3; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}
int rice_factorial(int max) {
  int i=max, result=1;
  while (i >= 2) { result *= i--; }
  return result;
}
int rice_pow(int a, int n) {
  return pow(a, n);
}

bool isPrime(int n) {
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;

    int upperLimit = (int) std::sqrt(n);
    int i = 3;
    while (i <= upperLimit) {
        if (n % i == 0)
            return false;
        i += 2;
    }
    return true;
}

/* count the number of primes up to limit */
int rice_prime(int lim) {
    int noPrimes = 0, limit = lim;
    for (int n = 0; n <= limit; n++) {
        if (isPrime(n))
            noPrimes++;
    }

    return noPrimes;
}

extern "C"

void Init_rice_test()
{
  Class rb_c = define_class("RiceTest")
    .define_method("fibonacci", &rice_fibonacci)
    .define_method("factorial", &rice_factorial)
    .define_method("pow", &rice_pow)
    .define_method("prime", &rice_prime);
}