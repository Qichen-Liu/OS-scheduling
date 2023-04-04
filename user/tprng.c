#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int main(void){
  int sum = 0;
  int max = 0;
  int min = 0;
  int tmp = prng()%10000;
  min = tmp;
  max = tmp;
  sum += tmp;

  for (int i = 1; i < 1000; i++){
    tmp = prng()%10000;
    if (tmp < 0) {
      printf(2, "negative num %d\n",tmp);
    } 
    sum += tmp;
    if (tmp > max) {
      max = tmp;
    }
    if (tmp < min) {
      min = tmp;
    }
  }
  printf(2, "max is %d\n", max);
  printf(2, "min is %d\n", min);
  printf(2, "mean is %d\n", sum/1000);
  exit();
}