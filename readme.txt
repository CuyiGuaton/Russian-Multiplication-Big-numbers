Multiplicación rusa para números grandes en C
Nombres: Sergio Salinas, Danilo Abellá
Compilador: gcc 5.4.0
IDLE: gedit
SO de prueba: Xubuntu 16.06 x86

Compilación

Se leen los datos desde un archivo, este archivo tiene separados los dos números a multiplicar separados por un espacio, cada par de números a multiplicar esta separado por un salto de linea.

El archivo se envia a través de argumentos, se debe ingresar el nombre del archivo con su extención cuando se ejecuta en terminal.

Compilación de los archivos de prueba, los archivos de prueba tienen un total de 100 números por 100 números, a exepción del archivo4 que solo tiene dos números. Los archivos se diferencian entre si por el largo de bits de estos. Los números son al azar y fueron generados usando la librería gmp para c.

Probando archivo 1: Multiplicación de 100 números dos números de 100 bits 
gcc russianmul.c && ./a.out archivo1.txt

Probando archivo 2: numeros de 100 bits por números de 100000 bits
gcc russianmul.c && ./a.out archivo2.txt

Probando archivo 3: numeros de 100000 bits por números de 100 bits
gcc russianmul.c && ./a.out archivo3.txt

Probando archivo 3: Dos numeros de 1000000 bits multiplicados entre si.
gcc russianmul.c && ./a.out archivo4.txt
