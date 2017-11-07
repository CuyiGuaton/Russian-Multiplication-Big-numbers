#include <stdio.h>
#include <string.h>

void longsum(const char *a, const char *b, char *c)
{
	int i = 0, j = 0, k = 0, carry, n, la, lb;
    char aux[1024];

	la = strlen(a);
	lb = strlen(b);
	printf("%i \t", la);
	printf("%i \n", lb);

///----------/ Ver n�mero mas grande /-------------------------------------//
	if ( la == lb )
	{

///-----------/ Suma /-----------------------------------------------------------------//
        memset(c, '0', la + 1);
        c[la + 1] = '\0';

        # define I(a) (a - '0')                           // Se convierte "a" en int
        for (i = lb - 1, k = i + 1; i >= 0; i--)
        {   carry = 0;
            n = I(a[i]) + I(b[i]) + I(c[k]) + carry;
            carry = n / 10;

            c[k] = (n % 10) + '0';
            k--;
            c[k] += carry;
        }
        # undef I                                         // Se convierte "a" en char
        if (c[0] == '0'){ memmove(c, c + 1, la + 1); }       // Se le asigna el valor al resultado.
	}
	else
    {
        if ( la > lb )
        {
            // Agregamos ceros delante del numero menor para que tenga la misma cantidad de digitos que el numero mayor.
            memset(aux, '0', la - lb);
            aux[la - lb] = '\0';

            strcat(aux,b);

///-----------/ Suma /-----------------------------------------------------------------//

            memset(c, '0', la + 1);
            c[la + 1] = '\0';

            # define I(a) (a - '0')                           // Se convierte "a" en int
            for (i = la - 1, k = i + 1; i >= 0; i--)
            {   carry = 0;
                n = I(a[i]) + I(aux[i]) + I(c[k]) + carry;
                carry = n / 10;

                c[k] = (n % 10) + '0';
                k--;
                c[k] += carry;
            }
            # undef I                                         // Se convierte "a" en char
            if (c[0] == '0'){ memmove(c, c + 1, la + 1); }       // Se le asigna el valor al resultado.
        }
        else
        {
            // Agregamos ceros delante del numero menor para que tenga la misma cantidad de digitos que el numero mayor.
            memset(aux, '0', lb - la);
            aux[lb - la] = '\0';

            strcat(aux,a);

///-----------/ Suma /-----------------------------------------------------------------//

            memset(c, '0', lb + 1);
            c[lb + 1] = '\0';

            # define I(a) (a - '0')                           // Se convierte "a" en int
            for (i = lb - 1, k = i + 1; i >= 0; i--)
            {   carry = 0;
                n = I(b[i]) + I(aux[i]) + I(c[k]) + carry;
                carry = n / 10;
                c[k] = (n % 10) + '0';
                k--;
                c[k] += carry;

            }
            # undef I                                         // Se convierte "a" en char
            if (c[0] == '0'){ memmove(c, c + 1, lb + 1); }       // Se le asigna el valor al resultado.
        }
    }
}

///---------------/ Funci�n Principal /-----------------------------------------------------------------//

int main()
{
	char c[1024];
	longsum("93206755555468135990499406208888 ", "17789410441116115177595283657", c);
	printf("%s\n", c);

	return 0;
}
