/*LECTURA DE ARCHIVO*/
# include <stdio.h>
# include <conio.h>

int i=0,n;
main()
{
struct mystruct
{
int x;
char ch;       
};
/*Primero se incia un puntero a un archivo luego se inicializa el arreglo. 
OBS. De la forma struct mystruct array[10] = {2,5,3,2,1,2,4,5,6,7}; no toma los valores corrrespondiente
de modo que la inicilizacion la hare de forma manual*/
FILE *ARCH;
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
ARCH = fopen("nuevo.txt","w");
for(n=0;n<10;n++)
{
printf("\tEl valor para % d posicion es[%d]\n",n,array[n].x);
fprintf( ARCH ,"%d\n",array[n].x);
}
getch();
return 0;
}
