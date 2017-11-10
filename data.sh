#!/bin/bash
#g++ main.cpp -lgmp && ./a.out 4 3 1

function nVaria {
  #elimina todo el contenido del archivo a guardar si es que existe.
  echo -n "" > plots/plot$2n$1.txt;
  for ((i=2; i<=$1; i= i + 10000));
  do
    echo -e $i $(./bfnp  $i \n)  >> plots/plot$2n$1.txt
  done

  
}


echo "Se están creando las gráficas, por favor espere"
#Crea las gráficas para los 5 metodos

n=1000000000000
nVaria $n 5
