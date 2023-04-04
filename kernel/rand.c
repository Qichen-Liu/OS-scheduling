#include "kernel/types.h"
#include "kernel/defs.h"
#include "kernel/param.h"

static uint random_seed = 1;

#define RANDOM_MAX ((1u << 31u) - 1u);

uint lcg_parkmiller(uint *state){
  const uint N = 0x7fffffff;
  const uint G = 48271u;
  uint div = *state / (N / G);
  uint rem = *state % (N / G);
  uint a = rem * G;
  uint b = div * (N % G);
  return *state = (a > b) ? (a - b) : (a + (N - b));
}

uint next_random() {
  return (lcg_parkmiller(&random_seed));
}