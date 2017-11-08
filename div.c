#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define I(a) (a - '0')

void longdiv(const char *a, char *c);

int main(int argc, char const *argv[]) {
  char *c= (char *)malloc(strlen(argv[1]));
	longdiv(argv[1],c);
	printf("%s / 2 = %s\n", argv[1],c);
	return 0;
}

void longdiv(const char *a, char *c)
{
    int la = strlen(a);
    memset(c, '0', la);
    c[la] = '\0';
    int carry = 0;
    int n=0;
    int i;
    for(i=0; i<la; i=i+1){
        n = (carry*10 + I(a[i]))/2;
        carry = (carry*10 + I(a[i])) - 2*n;
        c[i] = n + '0';
    }
    if(c[0] == '0'){
  			 memmove(c, c + 1, la);
  	     c[la] = '\0';
    }
}
