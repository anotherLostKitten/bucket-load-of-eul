#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int num_digits(__int128 num) {
  int t = 0;
  while (num > 0) {
    num /= 10;
    t++;
  }
  return t;
}

__int128 reverse(__int128 num, int total_digits) {
  if (num <= 0)
    return num;
  else
    return (num % 10) * pow(10, total_digits - 1) + reverse(num / 10, total_digits - 1);
}

int palindrome(__int128 num) {
  return num == reverse(num, num_digits(num));
}

int lyrchrel(__int128 cur) {
  for (int i = 0; i < 50; i++) {
    cur += reverse(cur, num_digits(cur));
    if (palindrome(cur))
      return 0;
  }
  return 1;
}

int main() {
  int sum = 0;
  for (int i = 1; i < 10000; i++) {
    sum += lyrchrel(i);
  }
  printf("problem 55: %d", sum);
  return 0;
}
