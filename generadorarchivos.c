//gcc test1.c -lgmp -lm && ./a.out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <gmp.h>
#include <time.h>

#define I(a) (a - '0')
#define MAX 400000000
//para funcionar se debe cambiar el main de a.c a int main(mpt_z n) y borrar las declaración, iniciacion y liberación de n


int main(int argc, char const *argv[]) {
    
   	unsigned long long int largo, exp, i;
    double time;
	char *a = (char *)malloc(MAX);
	char *b = (char *)malloc(MAX);
    char *command = (char *)malloc(MAX);
  	system(  "echo -n "" > archivo_prueba.txt");


    //generación del número random  
    mpz_t n,m; //random
    mpz_init(n);
    mpz_init(m);
    gmp_randstate_t state; // semilla random
    gmp_randinit_default(state); //inicializa algoritmo random
    gmp_randseed_ui(state, 100); //semilla de random

        mpz_urandomb(n,state, 1000000); //genera un random desde 0.. 2^i-1
        mpz_urandomb(m,state, 1000000); //genera un random desde 0.. 2^i-1
        
        mpz_get_str(a,10,n); 
        mpz_get_str(b,10,m); 
        printf("%s %s\n", a,b);
//     	snprintf ( command, MAX-1,  "\" %s %s \" >> archivo_prueba.txt", a, b );
//     	system(command);


    gmp_randclear(state);
    mpz_clear(n);
    mpz_clear(m);
    free(a);
    free(b);
    free(command);
    return 0;
}

