#!/bin/zsh

# hola, si estás leyendo esto es que estás curioseando/intentando añadir un test
# si es la segunda solo tienes que añadir el la carpeta test el input y sumarle 1 a la 
# variable cantidad de tests, si quieres añadir uno con unos parámetros especiales, 
# solo tienes que ir a la parte de if-elif y copiar el contenido cambiando los parámetros

let cuantasfallan=0
cantidadDeTests=9

rm ./a.out 2>/dev/null

g++ -Wall ./prac2.cc 2>/dev/null

# descomentar la linea para habilitar la funcionalidad de cantidad de test en los argumentos. 
# Si estás en el fango (añadiendo y programando en la tarde de antes), te recomiendo activarlo para mayor comodidad
#for i in {1..$1};
for i in {1..$cantidadDeTests};
do
    if [ $i -eq 3 ]; then

        rm -r  /tmp/prueba$i 2>/dev/null;
        mkdir /tmp/prueba$i 2>/dev/null;

        rm -r teachers.bin 2>/dev/null;

        ./prac2 -f ./tests/archivo.txt -s< ./tests/tests$i.txt > /tmp/prueba$i/salida-correcta.txt;

        rm -r teachers.bin 2>/dev/null;

        valgrind --quiet ./a.out -f ./tests/archivo.txt -s < ./tests/tests$i.txt > /tmp/prueba$i/salida-obtenida.txt;

        rm -r teachers.bin 2>/dev/null;
        
    elif [ $i -eq 6 ]; then

        rm -r  /tmp/prueba$i 2>/dev/null;
        mkdir /tmp/prueba$i 2>/dev/null;

        rm -r teachers.bin 2>/dev/null;

        ./prac2 -f ./tests/archivo.txt < ./tests/tests$i.txt > /tmp/prueba$i/salida-correcta.txt;

        rm -r teachers.bin 2>/dev/null;

        valgrind --quiet ./a.out -f ./tests/archivo.txt < ./tests/tests$i.txt > /tmp/prueba$i/salida-obtenida.txt;

        rm -r teachers.bin 2>/dev/null;

    else
        rm -r  /tmp/prueba$i 2>/dev/null;
        mkdir /tmp/prueba$i 2>/dev/null;

        rm -r teachers.bin 2>/dev/null;

        ./prac2 < ./tests/tests$i.txt > /tmp/prueba$i/salida-correcta.txt;

        rm -r teachers.bin 2>/dev/null;

        valgrind --quiet ./a.out < ./tests/tests$i.txt > /tmp/prueba$i/salida-obtenida.txt;

        rm -r teachers.bin 2>/dev/null;
    fi



    echo "---------------------------------------";
    echo "PRUEBA: $i";
    echo "---------------------------------------";

    diff /tmp/prueba$i/salida-obtenida.txt /tmp/prueba$i/salida-correcta.txt;
    if [ $? -eq 0 ];
    then
        echo "OK";
        cat /tmp/prueba$i/error.txt 2>/dev/null;
        rm -r  /tmp/prueba$i 2>/dev/null;
    else
        echo "FALLA";
        cat /tmp/prueba$i/error.txt 2>/dev/null;
        echo "comprueba los resultados en /tmp/prueba$i";
        let cuantasfallan=$cuantasfallan+1;
    fi


done
echo "Fallan $cuantasfallan pruebas";

# rm vgcore* 2>/dev/null

