#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define I(a) (a - '0')

void longmulti(const char *a, char *c);

int main(int argc, char const *argv[]) {
  char *c= (char *)malloc(strlen(argv[1]));
	longmulti(argv[1],c);
	printf("%s * 2 = %s\n", argv[1],c);
	return 0;
}

void longmulti(const char *a, char *c){
	int i = 0, k = 0, carry, n, la;

	la = strlen(a);
	memset(c, '0', la + 1);
	c[la + 2] = '\0';
	for (i = la - 1, k = i + 1; i >= 0; i--){
       carry = 0;
        n = I(a[i]) * 2 + I(c[k]) + carry;
        carry = n / 10;
        c[k] = (n % 10) + '0';
        k--;
		c[k] += carry;
	}

  if(c[0] == '0'){
			memmove(c, c + 1, la);
	     c[la] = '\0';
     }
}
