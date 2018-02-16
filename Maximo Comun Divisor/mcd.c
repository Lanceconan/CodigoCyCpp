#include<stdio.h>
#include<math.h>

main()
{
int i,j, menor, cantidad, numeros[10],pivote = 1;
int flag = 0, MCD = 1;
printf("Ingrese la cantidad de numeros a analizar: ");
scanf("%d",&cantidad);
    for(i = 0;i < cantidad; i++)
    {
    printf("\nIngrese el %d- numero:",i+1);
    scanf("%d",&numeros[i]);
    }
menor = numeros[0];
for(i = 1; i < cantidad; i++) {if (menor > numeros[i]) menor = numeros[i];}

while (pivote <= menor)
{
    for(j = 0;j < cantidad; j++)
    {
        if(numeros[j]%pivote != 0) flag = 1;
    }
if (flag == 0) MCD = pivote;
flag = 0;
pivote++;
}
printf("El maximo comun (MCD) divisor es: %d ", MCD);


}
