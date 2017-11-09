#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define I(a) (a - '0')
#define MAX 100000000

void longdiv(char *a, char *c);
void longmulti(const char *a, char *c);
void longsum(const char * a,  const char * b, char * c);


int main(int argc, char const *argv[]) {
	int la = strlen(argv[1]);
  int lb = strlen(argv[2]);
	char *a = (char *)malloc(la);
	char *aux =(char *)malloc(la);
	char *b = (char *)malloc(lb+MAX);
	char *aux2 = (char *)malloc(lb+MAX);
  char *result= (char *)malloc((la+lb)+MAX); //RESULTADO
	char *aux3 = (char *)malloc((la+lb)+MAX);

	strcpy(a,argv[1]);
	strcpy(b,argv[2]);

	clock_t start = clock();


	while (a[0]) {
		if( I(a[strlen(a)-1]) % 2){ //si a es impar
				longsum(b,result,aux3);
				strcpy(result,aux3);
		}
		longdiv(a,aux);
		strcpy(a,aux);
		longmulti(b,aux2);
		strcpy(b,aux2);
	}

	clock_t end = clock();
	long double elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
	printf("%LG", elapsed_time);

	//printf("\n Resultado = %s\n", result);
	free(a);
	free(b);
	free(result);
	free(aux);
	free(aux2);
	free(aux3);
	return 0;
}


void longdiv(char *a, char *c){
    int la = strlen(a);
    memset(c, '0', la);
    c[la] = '\0';
    int carry = 0;
    int n=0;
    int i;
    for(i=0; i<la; i=i+1){
        n = (carry*10 + I(a[i]))/2; //se divide un número de dos digitos, el primero es el carry y el segundo a dividir
        carry = (carry*10 + I(a[i])) - 2*n; //se calcula el resto de la división y se deja como carry
        c[i] = n + '0';
    }
    if(c[0] == '0'){ //se elimina el cero que quede adelante
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

        n = I(a[i]) * 2 + I(c[k]);
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
	//Crea un arreglo aux con el mismo largo que a pero con los valores de b y lleno adelante con ceros
	char *aux= (char *)malloc(la);
	memset(aux, '0', la-lb);
  aux[la-lb] = '\0';
	strcat(aux,b);
  while( la >  0) {
      sum = I(a[la-1]) + I(aux[la-1]) + carry; // se suman dos digitos más el carry
      carry = sum/10; //si es mayor a 10 el carry es zero
      c[la] = sum%10 + '0'; // se guarda el primer digito de la suma como resultado
      la--;
  }
	if (carry >0) { //si la última suma es mayor a 10 entonces
		c[0] = carry + '0';
	}
	la = lb = strlen(a);
  if(c[0] == '0'){ //se eliminan los ceros de adelante
      memmove(c, c + 1, la);
       c[la] = '\0';
     }

}
