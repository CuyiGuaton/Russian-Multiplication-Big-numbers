#include <stdio.h>
#include <string.h>

#define I(a) (a - '0')
#define MAX 1024

void longdiv(const char *a, int la, char *c);
void longmulti(const char *a, int la, char *c);
void longsum(const char * a,  const char * b, int la, int lb, char * c) ;
int iszero(const char *a, int size);


int iszero(const char *a, int size){
    int i = 0;
    while(i != size-1)
        if(a[i] != '0')
            return 0;
    return 1;
}

int main()
{
    int la,lb;
	char a[MAX] = "132121";
	char b[MAX] = "18";
	char aux[MAX];
	char result[MAX];
	la = strlen(a);
	result[la] = '\0';
	while(iszero(a,la) != 1){
        la = strlen(a);
        lb = strlen(b);
        longdiv(a,la,aux);
        strcpy(a,aux);
        longmulti(b,lb,aux);
        strcpy(b,aux);
        printf("%s %s\n", a,b);
	}
	printf("%s\n", result);
	return 0;
}




void longdiv(const char *a, int la, char *c){
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
}



void longmulti(const char *a, int la, char *c)
{
	int i = 0, k = 0, carry, n;


    /// Le asignamos un tamaño al resultado.
	memset(c, '0', la + 1);
	c[la + 1] = '\0';

///--------/ Multiplicación de "a" por 2 /-----------------------------------//
	for (i = la - 1, k = i + 1; i >= 0; i--){
       carry = 0;
        n = I(a[i]) * 2 + I(c[k]) + carry;
        carry = n / 10;
        c[k] = (n % 10) + '0';
        k--;
		c[k] += carry;
	}                                       // Se convierte "a" en char
}

void longsum(const char * a,  const char * b, int la, int lb, char * c) {
  int i = 0, j = 0, k = 0, carry, n;
  char aux[1024];

  //la = strlen(a);
  //lb = strlen(b);

  ///----------/ Ver número mas grande /-------------------------------------//
  if (la == lb) {

    ///-----------/ Suma /-----------------------------------------------------------------//
    memset(c, '0', la + 1);
    c[la + 1] = '\0';

    for (i = lb - 1, k = i + 1; i >= 0; i--) {
      carry = 0;
      n = I(a[i]) + I(b[i]) + I(c[k]) + carry;
      carry = n / 10;

      c[k] = (n % 10) + '0';
      k--;
      c[k] += carry;
    }
    if (c[0] == '0') {
      memmove(c, c + 1, la + 1);
    } // Se le asigna el valor al resultado.
  } else {
    if (la > lb) {
      // Agregamos ceros delante del numero menor para que tenga la misma cantidad de digitos que el numero mayor.
      memset(aux, '0', la - lb);
      aux[la - lb] = '\0';

      strcat(aux, b);

      ///-----------/ Suma /-----------------------------------------------------------------//

      memset(c, '0', la + 1);
      c[la + 1] = '\0';
      for (i = la - 1, k = i + 1; i >= 0; i--) {
        carry = 0;
        n = I(a[i]) + I(aux[i]) + I(c[k]) + carry;
        carry = n / 10;

        c[k] = (n % 10) + '0';
        k--;
        c[k] += carry;
      }
      if (c[0] == '0') {
        memmove(c, c + 1, la + 1);
      } // Se le asigna el valor al resultado.
    } else {
      // Agregamos ceros delante del numero menor para que tenga la misma cantidad de digitos que el numero mayor.
      memset(aux, '0', lb - la);
      aux[lb - la] = '\0';

      strcat(aux, a);

      ///-----------/ Suma /-----------------------------------------------------------------//

      memset(c, '0', lb + 1);
      c[lb + 1] = '\0';
      for (i = lb - 1, k = i + 1; i >= 0; i--) {
        carry = 0;
        n = I(b[i]) + I(aux[i]) + I(c[k]) + carry;
        carry = n / 10;
        c[k] = (n % 10) + '0';
        k--;
        c[k] += carry;

      }
      if (c[0] == '0') {
        memmove(c, c + 1, lb + 1);
      } // Se le asigna el valor al resultado.
    }
  }
}
