#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//#include "russianmul.c"

#define I(a) (a - '0')
#define MAX 100000000

int main(){

	unsigned long long int largo, exp, i;
	char *a = (char *)malloc(MAX);
	char *b = (char *)malloc(MAX);
    char *command = (char *)malloc(MAX*2);
    system(  "echo -n "" > result1.txt");
	for ( exp = 1; exp <= 100000; exp = exp + 1 )
	{
//		printf("Exp  %llu \n \n", exp);
		largo = pow(2,exp) - 1;			// Calculamos el largo del numero.
//		printf("Largo  %llu \n \n", largo);

		// Le asignamos el size al numero(char).
		memset(a, '0', largo);
       	a[largo] = '\0';

		memset(b, '0', largo);
		b[largo] = '\0';

		// Asignarle valor aleatorio al num.
		for ( i =  0; i < largo ; i++ )
		{
			if( i == 0 ){ 
                a[i] = (1 + rand()%(9)) + '0'; 
                b[i] = (1 + rand()%(9)) + '0'; 
            }else{
               a[i] = (rand()%(10)) + '0'; 
               b[i] = (rand()%(10)) + '0'; 
            }
		}
        memset(command, '0', largo);
          
       snprintf ( command, MAX,  "echo  %llu $(./bfnp  %s %s \n)  >> result1.txt", exp, a,b );
       system(command);

	}

	free(a); 
    free(b);
    return 0;
}
