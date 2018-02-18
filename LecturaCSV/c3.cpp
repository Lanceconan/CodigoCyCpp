/*LECTURA DE ARCHIVO*/
# include <stdio.h>
# include <conio.h>

int i=0,n,cont=0,b;
main()
{
struct mystruct
{
int x;
char ch;       
};
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
struct mystruct arrcaracter[cont],arrent[cont],car[cont];
/*En este sector se vuelve al principio y se definen los arreglos*/
fseek ( ARCH3 , 0 , SEEK_SET );
while(cont > 0)
{
fscanf( ARCH3 , "%d" ,&arrent[b].x );
fscanf( ARCH3 , "%c" ,&car[b].ch );
fscanf( ARCH3 , "%c" ,&arrcaracter[b].ch );
printf("\nPosicion %d del valor del entero es [%d]",b,arrent[b].x);
/*Se muestran los valores encontrados corrovorando que el arreglo es correcto*/
printf(" y del valor del caracter es [%c]",arrcaracter[b].ch);
fprintf( ARCH3, "\n");
b++;
cont--;
}
fclose(ARCH3);
getch();
return 0;
}
