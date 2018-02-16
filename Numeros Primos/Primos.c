#include<stdio.h>
#include<math.h>
#define CANTIDAD 100

main()
{
    int pivote = 2, numero = 1, ref = 1, contador = 0;
    while(ref <= CANTIDAD)
    {

    while(pivote < numero)
    {
        if(numero%pivote == 0) goto flag;
        pivote++;
    }
    flag:
    if(pivote == numero)
        {
        printf("[%d] - %d\n", ++contador, numero);
        ref++;
        }

    numero++;
    pivote = 2;
    }
}
