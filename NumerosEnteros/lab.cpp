#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
/*Existe un determinado uso de funcion clearscreen para odenar y hacer mas ameno la interaccion con el programa*/


main()                                                      /*programa principal*/
{
char op;
int i=0,n,cont=0,b=0;
/*Declaracion de la estructura predefinida*/
struct mystruct
{
int x;
char ch;
};

/*Inicio de la secuencia de menu de seleccion*/

/*A continuacion las opciones de menu del programa*/
system("cls");
printf("\n\n\tSeleccione una opcion para operar:\n");
printf("\n\tA - Leer archivo para formar arreglo");
printf("\n\tB - Escribir el arreglo en un archivo");
printf("\n\tC - Arreglo de estructuras");
printf("\n\n\tCual es la opcion :");                            /*Ingresar la opcion para trabajar*/
fflush(stdin);scanf("%c",&op);
op = toupper(op);                                         /*Anula la diferencia entre mayusculas y minusculas haciendolas una sola*/
switch(op)
{
/*leer un archivo de texto que contenga un entero en cada línea, y llenar un arreglo con esos datos*/
case 'A':

system("cls");
printf("\n\tLeer enteros en el archivo\n");
                 /*Se trabaja con un archivo llamado enteros.txt el cual cumple la funcion 
                 de entregar los enteros asignados al arreglo*/
                 FILE *ARCH;
                 ARCH = fopen("enteros.txt","r");
                 i=0;
                 fflush(stdin);
                 struct mystruct carac;
                 while((carac.ch = getc(ARCH)) != EOF)
                 {
                 fflush(stdin);
                 /*Comparacion de importante valor ya que esta es la que cuenta 
                 la cantidad de enteros para asi conformar un arreglo de cualquier cantidad 
                 razonable de elementos del vector */
                 if(carac.ch != '\n')
                 i++;
                 fprintf(ARCH,"\n");
                 }
                 printf("\tLa cantidad de enteros fue i %d\n",i);
                 struct mystruct arreglo[i];
                 /*En este sector se vuelve a recorrer el archivo desde un principio
                 para generar luego el arreglo o vector*/
                 fseek ( ARCH , 0 , SEEK_SET );
                 while(i>0)
                 {
                 fscanf( ARCH , "%d" ,&arreglo[i].x );
                 printf("\n\tEl valor en la posicion es [%d]",arreglo[i].x);
                 fprintf( ARCH, "\n");
                 --i;
                 }
                 fclose(ARCH);        /*Se cierra el archivo con el cual trabajamos*/
                 printf("\n\tPresione una tecla cara salir.....");
                 getch();
break;

/*El contenido de un arreglo de enteros*/
case 'B':
system("cls");
printf("\n\tEscribir arreglo en un archivo\n\n");
/*Primero se incia un puntero a un archivo luego se inicializa el arreglo. 
OBS. De la forma struct mystruct array[10] = {2,5,3,2,1,2,4,5,6,7}; no toma los valores correspondiente
de modo que la inicilizacion la hare de forma manual*/

   FILE *ARCH2;
   struct mystruct array[10]; /*= {2,5,3,2,1,2,4,5,6,7};*/

   array[0].x = -3;
   array[1].x = 4;
   array[2].x = 5;
   array[3].x = -67;
   array[4].x = 23;
   array[5].x = -59;
   array[6].x = 56;
   array[7].x = 50;
   array[8].x = -34;
   array[9].x = 345;

   /*for(i=0;i<10;i++)
   array[i].x = i + 2;*/
   /*Se crea un archivo de texto el cual permitira amacenar los valores del arreglo previamene inicializado*/
   ARCH2 = fopen("nuevo.txt","w");
   for(n=0;n<10;n++)
   {
   printf("\tEl valor para % d posicion es[%d]\n",n,array[n].x);
   fprintf( ARCH2 ,"%d\n",array[n].x);
   }
   printf("\n\tPresione una tecla cara salir.....");
   getch();
   fclose(ARCH2);                     /*Se cierra el archivo con el cual trabajamos*/
break;

/*Arreglo de estructuras para un entero y un caracter*/
case 'C':
system("cls");
printf("\n\tArreglo de estructuras\n\n");
                    /*Iniciacion del puntero al archivo coma.csv de forma lectura
                    se abre el archivo y se define el numero de comas para saber cuantos
                    valores tendremos*/
                    FILE *ARCH3;
                    ARCH3 = fopen("coma.csv","r");
                    i=0;
                    fflush(stdin);
                    struct mystruct tres;
                    while((tres.ch = getc(ARCH3)) != EOF)
                    {
                    if(tres.ch == ',')
                    cont++;
                    printf("%d",cont);
                    }
                    /*Comienzan las lecturas de caracteres y enteros separados por comas*/
                    struct mystruct arrcaracter[cont],car[cont];
                    struct mystruct arrent[cont];
                    /*En este sector se vuelve al principio y se definen los arreglos*/
                    fseek ( ARCH3 , 0 , SEEK_SET );

                    while(cont > 0)
                    {
                    fscanf( ARCH3 , "%d",&arrent[b].x );
                    fscanf( ARCH3 , "%c",&car[b].ch );
                    fscanf( ARCH3 , "%c",&arrcaracter[b].ch );
                    printf("\nPosicion %d del valor del entero es [%d]",b,arrent[b].x);
                    /*Se muestran los valores encontrados corrovorando que el arreglo es correcto*/
                    printf(" y del valor del caracter es [%c]",arrcaracter[b].ch);
                    fprintf( ARCH3, "\n");
                    b++;
                    cont--;
                    }
                    fclose(ARCH3); /*Se cierra el archivo con el cual trabajamos*/
printf("\n\tPresione una tecla cara salir.....");
getch();
break;

/*Caso en el cual se acepta una opcion no valida*/
default:
system("cls");
printf("\n\n\tEsta opcion no esta disponible\n\n\tPresione una tecla para salir");
getch();
break;
}
return 0;
}

