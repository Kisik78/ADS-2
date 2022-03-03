// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double uni = 1;
  while (n != 0) {
    n--;
    uni *= value;
  }
  return uni;
}

uint64_t fact(uint16_t n) {
  if (n < 0) {
    return 0;
  }
  if (n == 0) {
    return 1;
  } else {
      return n * fact (n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return pown (x, n) / fact (n);
}

double expn(double x, uint16_t count) {
  double uni = 0;
  for (int n = 0; n <= count; n++) {
    uni += calcItem(x, n);
  }
  return uni;
}

double sinn(double x, uint16_t count) {
  double uni = 0;
  while (count != 0) {
        uni += pown(-1, count - 1) * calcItem(x, 2 * count - 1);
        count--;
  }
  return uni;
}

double cosn(double x, uint16_t count) {
  double uni = 0;
  for (uint16_t n = 1; n <= count; n++) {
    uni += pown(-1, (n - 1)) * calcItem(x, (2 * n - 2));
  }
  return uni;
}
