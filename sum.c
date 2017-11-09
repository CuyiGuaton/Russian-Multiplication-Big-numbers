#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define I(a) (a - '0')


void longsum(const char * a,  const char * b, char * c);

int main(int argc, char const *argv[]) {
  char *c= (char *)malloc(strlen(argv[1]) + strlen(argv[2]));
	longsum(argv[1],argv[2],c);
	//printf("%s + %s = %s\n", argv[1],argv[2],c);
	return 0;
}


void longsum(const char * a,  const char * b, char * c){
  int la = strlen(a);
  int lb = strlen(b);
  int carry = 0;
  int sum;
  memset(c, '0', la+1); //llena c de 0
	//Crea un arreglo aux con el mismo largo que a pero con los valores de b
	char *aux= (char *)malloc(la);
	memset(aux, '0', la-lb);
  aux[la-lb] = '\0';
	strcat(aux,b);
  while( la >  0) {
      sum = I(a[la-1]) + I(aux[la-1]) + carry;
      carry = sum/10;
      c[la] = sum%10 + '0';
      la--;
  }
	if (carry >0) {
		c[0] = carry + '0';
	}
	la = lb = strlen(a);
  if(c[0] == '0'){
      memmove(c, c + 1, la);
       c[la] = '\0';
     }

}
