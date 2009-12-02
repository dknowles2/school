#import <stdio.h>


int main()
{
  int a[1000] = { [0] = 4, [1] = 3, [998] = 9, [999] = 7 };

  int i = 0;
  for (i = 0; i < 1000; i++) {
    printf("a[%d] = %d\n", i, a[i]);
  }
}
