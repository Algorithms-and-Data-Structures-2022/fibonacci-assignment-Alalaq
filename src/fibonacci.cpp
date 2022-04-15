#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    double phi = (1 + sqrt(5)) / 2;
    double minus_phi = (1 - sqrt(5)) / 2;

    double m = ((pow(phi, n) - pow(minus_phi, n))/ sqrt(5));

    if (static_cast<int>(m) == fib_iterative(n)){
      return static_cast<int>(m);
    }

    return static_cast<int>(m) + 1;
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    int fib[n - 1];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++){
      fib[i] = fib[i - 1] + fib[i - 2];
    }

    int sumfib = 0;

    for (int elem : fib){
      sumfib += elem;
    }

    return sumfib + 1;
  }

  int64_t fib_recursive(int n) {
    if (n == 0){
      return 0;
    }

    else if (n == 1){
      return 1;
    }

    else return fib_recursive(n - 1) + fib_recursive(n - 2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      // Напишите здесь свой код ...
      return cache[n];
    }

    else{
      cache[n] = fib_recursive_memoization(n - 1, cache) + fib_recursive_memoization(n - 2, cache);
      return fib_recursive_memoization(n - 1, cache) + fib_recursive_memoization(n - 2, cache);
    }

    return 0;
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    // Tip: используйте реализованную функцию matrix_pow

    return 0;
  }

}  // namespace assignment
