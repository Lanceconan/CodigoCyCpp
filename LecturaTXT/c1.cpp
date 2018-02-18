/*LECTURA DE ARCHIVO*/
# include <stdio.h>
# include <conio.h>

int i=0;
main()
{
struct mystruct
{
int x;
char ch;       
};

FILE *ARCH;

ARCH = fopen("coma.txt","r");
i=0;
fflush(stdin);
struct mystruct carac;
while((carac.ch = getc(ARCH)) != EOF)
{
fflush(stdin);
if(carac.ch != '\n')
i++;
fprintf(ARCH,"\n");
}
getch();
printf("el valor de i %d",i);
getch();
struct mystruct arreglo[i];
fseek ( ARCH , 0 , SEEK_SET );
while(i>0)
{
fscanf( ARCH , "%d" ,&arreglo[i].x );
printf("\nel valor es [%d]",arreglo[i].x);
fprintf( ARCH, "\n");
--i;
}

getch();
return 0;
}
