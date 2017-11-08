#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define I(a) (a - '0')


void longdiv(const char *a, char *c);
void longmulti(const char *a, char *c);
void longsum(const char * a,  const char * b, char * c);

int main(int argc, char const *argv[]) {
	int la = strlen(argv[1]);
  int lb = strlen(argv[2]);

	char *a = (char *)malloc(la);
	char *b = (char *)malloc(lb);
  char *result= (char *)malloc(la+lb); //RESULTADO

	char *aux = la > lb ? (char *)malloc(la) : (char *)malloc(lb) ;
	strcpy(a,argv[1]);
	strcpy(b,argv[2]);
	//longdiv(a,result);
	//printf("%s / 2 = %s\n", a,result);
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

void longsum(const char * a,  const char * b, char * c){
  int la = strlen(a);
  int lb = strlen(b);
  int carry = 0;
  int sum;
  memset(c, '0', la+1); //llena c de 0
	//Crea un arreglo aux con el mismo largo que a pero con los valores de b
	char *aux= (char *)malloc(la-lb);
	memset(aux, '0', la - lb);
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
	while (c[0] == '0' && la > 1) {
			memmove(c, c + 1, la--);
			c[lb] = '\0';
	}
}
