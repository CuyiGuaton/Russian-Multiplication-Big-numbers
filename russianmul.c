#include <stdio.h>
#include <string.h>

#define I(a) (a - '0')
#define MAX 2048

void longdiv(const char *a, char *c);
void longmulti(const char *a, char *c);
void longsum(const char * a,  const char * b, char * c);

int main()
{
    //camibar a y b por argv[1] y argv[2]
		char a[MAX] = "111111";
		char b[MAX] = "111111";
		char aux[MAX];
    int la = strlen(a);
    //Guarda el resultado, el resultado de la multiplicación de dos digitos no va a tener más digitos que la suma de los digitos de ambos números
    int lr = la + strlen(b);
    char result[lr + 1];
    while( strcmp(a,"0") != 0){ //mientras a no sea zero
        if(a[strlen(a)-1] % 2==1){ //si a es impar
            longsum(b,result,aux);
            strcpy(result,aux);
        }
        //divide a por 2
        longdiv(a,aux);
        strcpy(a,aux);
        //multiplica b por 2
        longmulti(b,aux);
        strcpy(b,aux);
        printf("%s %s %s\n", a,b,result);
    }

    printf("%s\n", result);
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
		while (c[0] == '0' && la > 1) {
				memmove(c, c + 1, la--);
		}
}



void longmulti(const char *a, char *c)
{
	int i = 0, k = 0, carry, n, la;


    /// Le asignamos un tama�o al resultado.
	la = strlen(a);
	memset(c, '0', la + 1);
	c[la + 1] = '\0';

///--------/ Multiplicaci�n de "a" por 2 /-----------------------------------//
	for (i = la - 1, k = i + 1; i >= 0; i--){
       carry = 0;
        n = I(a[i]) * 2 + I(c[k]) + carry;
        carry = n / 10;
        c[k] = (n % 10) + '0';
        k--;
		c[k] += carry;
	}                                       // Se convierte "a" en char
	//while (c[0] == '0' && la > 1) {
	//	memmove(c, c + 1, la--);
	//}
}

void longsum(const char * a,  const char * b, char * c)
{
	int i = 0, j = 0, k = 0, carry, n, la, lb;
  char aux[1024];

	la = strlen(a);
	lb = strlen(b);

	// Agregamos ceros delante del numero menor para que tenga la misma cantidad de digitos que el numero mayor.
	memset(aux, '0', la - lb);
	aux[la - lb] = '\0';

	strcat(aux,b);
///-----------/ Suma /-----------------------------------------------------------------//

	memset(c, '0', la + 1);
	c[la + 1] = '\0';
	for (i = la - 1, k = i + 1; i >= 0; i--)
	{
			n = I(a[i]) + I(aux[i]) + I(c[k]);
			carry = n / 10;

			c[k] = (n % 10) + '0';
			k--;
			c[k] += carry;
	}

	if (c[0] == '0'){ memmove(c, c + 1, la + 1); }       // Se le asigna el valor al resultado.
}
