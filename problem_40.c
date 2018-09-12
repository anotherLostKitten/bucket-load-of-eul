#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int whichDigit(int number, int digitIndex, int digits) {
  if (digitIndex == 0) {
    digitIndex += digits;
    number -= 1;
  }
  while (digitIndex < digits) {
    number /= 10;
    digitIndex++;
  }
  return number % 10;
}


int whichNumber(int index, int digits, int maxIndex) {
  if (index <= maxIndex * digits) {
    return whichDigit(index / digits + maxIndex / 9, index % digits, digits);
  } else {
    return whichNumber(index - maxIndex * digits, digits + 1, maxIndex * 10);
  }
}

int wrapper(int index) {
  return whichNumber(index, 1, 9);
}

int main() {
  int product = 1;
  for (int i=1; i <= 1000000; i*=10) {
    product *= wrapper(i);
  }
  printf("problem 40: %d", product);
  return 0;
}
