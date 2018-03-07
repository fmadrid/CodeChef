#include <iostream>
  // Calculates the geometric series 5^i from i = 0 to i = 12. Can be substituted with a constant
  // array but I wanted to show how it was computed
  int* calculatePowers(int maxExponent) {
    const int SIZE = maxExponent + 1;
    int* fivePowers = new int[SIZE];
    fivePowers[0] = 1;
    for(int i = 1; i < SIZE; i++) fivePowers[i] = 5 * fivePowers[i-1]; // Powers of 5
    for(int i = 1; i < SIZE; i++) fivePowers[i] += fivePowers[i-1];    // Cumulative summation
    return fivePowers;
  }
    
  // Starting at the target, repeatedly subtract out multiples of the largest element in powers
  bool canReachTarget(int target, int* powers, int SIZE) {
    for(int i = SIZE - 1; i >= 0; i--) {
      if(target / powers[i] >= 5) return false; // Ensure we never remove more than 5 multiples
      else target %= powers[i];                 // Subtract out multiples of largest power
    }
    return true;
  }
  int preimageSizeFZF(int K) {
    const int maxExponent = 12;
    int* powers = calculatePowers(maxExponent);
    int ret = 0;
    if(canReachTarget(K, powers, maxExponent+1)) ret = 5;  // If achievable, the answer is always 5
    delete[] powers;
    return ret;
  }

  int main(int argc, char** argv) {
    int K = atoi(argv[1]);
    std::cout << preimageSizeFZF(K) << " factorials have " << K << " trailing zeroes.\n";
    return 0;
  }