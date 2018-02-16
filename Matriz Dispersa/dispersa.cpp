#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<time.h>
#include <iostream>
#define M 9 // columna
#define N 4 //fila
#define T 2 //tamaño byte de un int

using namespace std;

int contador;

class Matriz{
   //Matriz();
   public:
      // Datos miembro de la clase matriz
      int MatrizClase[N][M];
      /*De la matriz compacta */
      int MatrizCompacta [N*M];
      int Fila[N*M], Columna [N*M];
      int CantidadNulos, CantidadNoDispersos;
   public:


      /* Funcion para llenar aleatoriamente la imagen asegurandose que la mayor cantidad de elementos sean ceros*/
      void LlenarMatriz(void)
      {
           int ref = 0;
           for(int i = 0; i <= N; i++)
           for(int j = 0; j <= M; j++)
           {
               if (ref == 6) {MatrizClase [i][j] = (rand () % 1023); ref = 0;}
               else { MatrizClase [i][j] = 0; ref++ ;}
           }

      }
      /*Muestra la imagen rotada 90° a la derecha [transpuesta]*/
      void RotarMatriz(void)
      {
           printf("\t\t");
           for(int i = 0; i <= M; i++)
           {
              for(int j = N; j >= 0; j--)
              {
                 printf("%d\t", MatrizClase[j][i]);
              }
           printf("\n\n\t\t");
           }
      }
      /*Funcion para compactar una imagen, guardando las posiciones correpondientes a los datos distintos de 0*/
      void CompactarMatriz(void)
      {
         int i,j,contador = 0, nulos = 0;
         int ColumnaAux[N*M], FilaAux[N*M];
         for(i = 0; i <= N; i++)
         {
           for(j = 0; j <= M; j++)
           {

              if (MatrizClase [i][j] != 0)
                 {
                 MatrizCompacta[contador] = MatrizClase [i][j];
                 Columna[contador] = j;
                 Fila[contador] = i;
                 //printf("%d Valor %d No disperso con posicion [%d] Fila [%d] Columna\n",contador ,MatrizCompacta[contador], Fila [contador], Columna[contador]);

                 fflush(stdin);contador++;
                 }
              else nulos++;
           }
         }
      //for(int job = 0; job <= contador; job++) {Columna[job] = ColumnaAux[job]; Fila[job] = FilaAux [job];}
      CantidadNoDispersos = contador;
      CantidadNulos = nulos;
      }

      /*Muestra la posicion y la */
      void MostrarMatrizCompacta(void)
      {
         for(int in = 0; in < CantidadNoDispersos; in++)
             printf("\t[%.2d] Pixel Compactado %d con posicion Fila [%d] Columna [%d]\n",(in+1) , MatrizCompacta[in], Fila [in], Columna[in]);
      }

      /*Funcion para encontrar el espacio total  utilizado en imagen*/
      int EspacioMatriz(void)
      {
      /*Como las matrices tienen ic = if = 0 no se toman en cuenta*/
          int S = (N+1)*T;
          return (N*S) + (M*T) + T;
          /* se le sumo T para obtener el tamaño total de registro,
          ya que sin T solo nos mostraria la ubicacion del inicio del ultimo registro*/
      }

      /*Funcion para encontrar el espacio total  utilizado en imagen compacta*/
      int EspacioMatrizCompacta(void)
      {
        /*Como las matrices tienen li = 0 no se toma en cuenta*/
        return (T*CantidadNoDispersos) + T;
        /* se le sumo T para obtener el tamaño total de registro,
          ya que sin T solo nos mostraria la ubicacion del inicio del ultimo registro*/
      }

      /*Funcion para desplegar la imagen*/
      void MostrarMatriz(void)
      {
           for(int i = 0; i <= N; i++)
           {
              for(int j = 0; j <= M; j++)
              {
                 printf("%d\t", MatrizClase[i][j]);
              }
           printf("\n\n");
           }
      }

};

void MensajesEstandar (void)
{
system("cls");
printf("\n\n\t\t--------------------------------------\n");
printf("\t\t\t Tratamiento de Imagenes\n");
printf("\t\t______________________________________\n\n\n");
printf("\n");
}

int main ()
{
int Opcion;
system("color 0A");
Matriz MatrizA, MatrizB;
MatrizA.LlenarMatriz();
MatrizB.LlenarMatriz();
MatrizA.CompactarMatriz();
MatrizB.CompactarMatriz();

do
{
  system("cls");
  printf("\n\n\t\t--------------------------------------\n");
  printf("\t\t\t Tratamiento de Imagenes\n");
  printf("\t\t______________________________________\n\n\n");
  printf("\tSeleccione tarea y presione Enter\n\n\n");
  printf("\t\t1 - Almacenar las versiones campactas de las imagenes\n");
  printf("\t\t2 - Determinar el espacio para guardar las imagenes\n");
  printf("\t\t3 - Determinar cantidad de puntos de coincidencia\n");
  printf("\t\t4 - Rotar una Imagen en 90 grados [derecha]\n");
  printf("\t\t5 - Desplegar una imagen\n");
  printf("\t\t6 - Salir\n\n");
  printf("\t\t Ingrese opcion: ");
  fflush(stdin);scanf("%d", &Opcion);

switch(Opcion)
{
case 1:
MensajesEstandar();
MatrizA.MostrarMatrizCompacta();
getch();

break;

case 2:
MensajesEstandar();
printf("\n\n\tEl espacio Total utilizado para almacenar la imagen de: \n\n\t%d x %d Pixeles\n\n\tFue %d bytes", (M + 1), (N + 1), MatrizA.EspacioMatriz());
printf("\n\n\tEl espacio Total utilizado para almacenar la imagen compacta de: \n\n\t%d x %d Pixeles\n\n\tFue %d bytes", (M + 1), (N + 1), MatrizA.EspacioMatrizCompacta());
getch();
break;

case 3:
int i, j,ContadorElementos;
ContadorElementos = 0;
    for(i = 0; i <= N; i++)
    {
        for(j = 0; j <= M; j++)
        {
            if (MatrizA.MatrizClase [i][j] == MatrizB.MatrizClase [i][j] ) ContadorElementos++;
        }
    }
MensajesEstandar();
printf("\n\n\tLa cantidad de puntos coincidentes entre las imagenes fue : %d", ContadorElementos);
getch();

break;

case 4:
MensajesEstandar();
MatrizA.RotarMatriz();
getch();
break;

case 5:
MensajesEstandar();
MatrizA.MostrarMatriz();
getch();
break;

case 6:
system("cls");
printf("\n\n\t\t\tUsted ha salido del programa....\n\t\t\tPresione tecla para Cerrar\n\n");
printf("\n\n\t\t---------------------------------------------\n");
printf("\t\t\t *PROGRAMADO POR LANCECONAN*\n");
printf("\t\t\t  DANIEL GUTIERREZ PIZARRO\n");
printf("\t\t______________________________________________\n\n\n");
break;

default:
system("cls");
            printf("\n\n\t\t--------------------------------------\n");
            printf("\t\t\t Tratamiento de Imagenes\n");
            printf("\t\t______________________________________\n\n\n");
            printf("\n\n\t\t    Opcion No valida por el momento!!!!");
            printf("\n\t\t    Presione una tecla para continuar...");
            getch(); fflush(stdin);
break;
}
}
while (Opcion != 6);
getch();
return 0;
}
