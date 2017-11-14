#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <gmp.h>
#define MAX 400000000
//para funcionar se debe cambiar el main de a.c a int main(mpt_z n) y borrar las declaración, iniciacion y liberación de n

int main(int argc, char const *argv[]) {
    
   	unsigned long long int largo, exp, i;
	char *a = (char *)malloc(MAX);
	char *b = (char *)malloc(MAX);
    char *command = (char *)malloc(MAX*2);
  	system(  "echo -n "" > result1.txt");


    //generación del número random  
    mpz_t n,m; //random
    mpz_init(n);
    mpz_init(m);
    gmp_randstate_t state; // semilla random
    gmp_randinit_default(state); //inicializa algoritmo random
    gmp_randseed_ui(state, 100); //semilla de random
    for (i = 0; i < 10000; i++){
        mpz_urandomb(n,state, i); //genera un random desde 0.. 2^i-1
        mpz_urandomb(m,state, i); //genera un random desde 0.. 2^i-1
        //gmp_printf ("%i %Zd %Zd\n", i,n,m);

		largo = pow(2,i) - 1;			// Calculamos el largo del numero.
   		memset(a, '0', largo);
     	a[largo+1] = '\0';

		memset(b, '0', largo);
		b[largo+1] = '\0';
        
        mpz_get_str(a,10,n); 
        mpz_get_str(b,10,m); 
        
//        printf("%llu %s %s\n    ", i,a,b);
        memset(command, '0', largo);
          
       	snprintf ( command, MAX,  "echo  %llu $(./bfnp  %s %s \n)  >> result1.txt", largo, a,b );
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
