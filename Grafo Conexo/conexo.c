#include<stdio.h>
#include<math.h>
#define Nodo 6

int i, j, n = 1, contadoraristas = 0, MatrizAdyacencia [Nodo][Nodo], NodosPillados[Nodo], MatrizLista [Nodo][Nodo];
int pivote = 1;

void llenarmatriz(void)
{
for(i = 1; i <= Nodo; i++){
for(j = n; j <= Nodo; j++)
{
if (i == j) MatrizAdyacencia[i][j] == 0;
else {MatrizAdyacencia[i][j] = rand()%2; MatrizAdyacencia[j][i] = MatrizAdyacencia[i][j];}
MatrizLista[i][j] = 0;
}
n++;
}
}

void MostrarMatriz(void){
for(i = 1; i <= Nodo; i++)
{
    for(j = 1; j <= Nodo; j++)
    {
        if( MatrizAdyacencia[i][j] == 1)
        {
        contadoraristas++;
        MatrizLista [i][pivote] = j;
        pivote++;
        }
    printf(" %d |", MatrizAdyacencia[i][j]);
    }
pivote = 1;
printf("\n\n");
}
}

void encontrarconexos(void)
{
for(i = 1; i <= Nodo; i++)
{
  for(j = 1; j <= Nodo; j++)
  {
    if(MatrizLista [i][j] )
  }
}
}

main()
{
llenarmatriz();
MostrarMatriz();
if ((int)(contadoraristas/2) < Nodo) { printf("\n Es un grafo no conexo"); goto salir;}
printf("\n\n");

salir:
getch();
}
