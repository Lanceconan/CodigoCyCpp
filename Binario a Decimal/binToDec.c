#include<stdio.h>
#include<math.h>

main()
{
int numero, opcion, copia, acumulador_decimal = 0, pivote = 1;
printf("Ingresar un numero: ");
scanf("%d",&numero);

printf("\n1 - Transformar a Decimal");
printf("\n2 - Transformar a Binario");
printf("\nIngrese opcion: "); fflush(stdin);scanf("%d",&opcion);

    if(opcion == 1)
        {
            copia = numero;
            while(numero != 0)
            {
                acumulador_decimal = acumulador_decimal + ((numero%10) * pivote);
                pivote = pivote*2;
            (int)numero = numero/10;
            }
        printf("\nEl numero %d a decimal es %d",copia,acumulador_decimal);
        }

    else if (opcion == 2)
        {
            printf("\nEl numero decimal %d a binario es: ", numero);

            while(numero != 0)
            {
            printf("%d", numero%2);
            numero = numero/2;
            }
        }

getch();
}
