//gcc test2.c -lgmp -lm && ./a.out
//multiplica número random a por un número ramdon fijo de 2^15-1 bits

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <gmp.h>
#include <time.h>

#define I(a) (a - '0')
#define MAX 400000000
//para funcionar se debe cambiar el main de a.c a int main(mpt_z n) y borrar las declaración, iniciacion y liberación de n


void longdiv(const char *a, char *c);
void longmulti(const char *a, char *c);
void longsum(const char * a,  const char * b, char * c);
double russianmul(char *a, char *b);


int main(int argc, char const *argv[]) {
    
   	unsigned long long int largo, exp, i;
    double time;
	char *a = (char *)malloc(MAX);
	char *b = (char *)malloc(MAX);
    char *command = (char *)malloc(100);
  	system(  "echo -n "" > result2-s.txt");


    //generación del número random  
    mpz_t n,m; //random
    mpz_init(n);
    mpz_init(m);
    gmp_randstate_t state; // semilla random
    gmp_randinit_default(state); //inicializa algoritmo random
    gmp_randseed_ui(state, 100); //semilla de random

    mpz_urandomb(m,state, 100); //genera un random desde 0.. 2^15-1
    mpz_get_str(b,10,m); 

    for (i = 10000; i < 400000; i=i+10000){
        mpz_urandomb(n,state, i); //genera un random desde 0.. 2^i-1

        
        mpz_get_str(a,10,n); 


        time = russianmul(a,b);
        printf("%llu %f\n    ", i,time);
     	snprintf ( command, 100,  "echo  %llu %f  >> result2-s.txt", i, time );

     	system(command);

    }
    gmp_randclear(state);
    mpz_clear(n);
    mpz_clear(m);
    free(a);
    free(b);
    free(command);
    return 0;
}


double russianmul(char *a, char *b) {
	//Declaración  de variables
	int la = strlen(a);
    int lb = strlen(b);
	char *aux =(char *)malloc(la+1);
	char *aux2 = (char *)malloc(lb+MAX+1);
    char *result= (char *)malloc((la+lb)+MAX); //RESULTADO
	char *aux3 = (char *)malloc((la+lb)+MAX);

    
    clock_t start, end;
    start = clock();
    
    double elapsed_time;
	//Ciclo Multiplicación rusa
	while (a[0]) { //Mientras a no sea 0
		if( I(a[strlen(a)-1]) % 2){ //si a es impar
				longsum(b,result,aux3); //Se suma el primer segundo número por el resultado
				strcpy(result,aux3);
		}
		longdiv(a,aux); //se divide el primer número por 2
		strcpy(a,aux);
		longmulti(b,aux2); //Se multiplica el segundo número por dos
		strcpy(b,aux2);
	}

	end = clock();
	elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
	//printf("%f largo a= %i largo b = %i", elapsed_time, la , lb);
//    printf("%f", elapsed_time);
	//printf("\n Resultado = %s\n", result);

	//Liberación memoria
	free(result);
	free(aux);
	free(aux2);
	free(aux3);

    return elapsed_time;
}


void longdiv(const char *a, char *c){
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
	char *aux= (char *)malloc(la+2);
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
    free(aux);
}
