#include <stdio.h>
#include <string.h>

#define I(a) (a - '0')
#define MAX 1024


int main()
{
	char a[MAX] = "99999";
	char b[MAX] = "1111";
  char c[MAX];


  int la = strlen(a);
  int lb = strlen(b);
  int carry = 0;
  int sum;
  memset(c, '0', la+1);
  c[la+1] = '\0';
  while( lb >  0) {
      sum = I(a[la-1]) + I(b[lb-1]) + carry;
      carry = sum/10;
      c[la] = sum%10 + '0';
      //printf("%c\n", c[la]);
      la--;
      lb--;
  }

  while (la>0) {
    c[la] = a[la-1];
    la--;
  }

  printf("%s + %s = %s\n", a,b,c);

	return 0;
}
