#include<stdio.h>
#include<math.h>

main()
{
int numero, sumaparcial = 0, pivote = 1 ;
printf("Ingresar un numero: ");
scanf("%d",&numero);

    while(pivote < numero)
    {
        if((numero%pivote)== 0)
            sumaparcial = sumaparcial + pivote;
        pivote++;

    }
if(sumaparcial == numero)
printf("El numero %d es un numero perfecto", numero);
else printf("El numero %d NO es un numero perfecto", numero);
getch();
}
