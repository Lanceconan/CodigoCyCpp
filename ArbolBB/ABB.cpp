#include "TDA_Arbol.h"
#include <ctype.h>

main()
{
int entero,contar=-1,primero,buscar;
char op1,op2;
pPUNTERO apun=NULL,temporal;
pARBOL borrador;
do
{
system("cls");
printf("\n\n\t\t-----------------------------------\n");
printf("\t\t   ARBOL DE BUSQUEDA BINARIA...\n");
printf("\t\t-----------------------------------\n\n");
printf("\t1 - Crear el Arbol\n");
printf("\t2 - Ingresar dato entero\n");
printf("\t3 - Borrar dato\n");
printf("\t4 - Ir a submenu de mostrar arbol\n");
printf("\t5 - Salir\n");
printf("\n\n\tIngrese su opcion: ");
fflush(stdin);scanf("%c",&op1);
switch(op1)
{
case '1':
/*OPCION PARA CREAR UN ARBOL BINARIO*/
system("cls");
crea_arbol(&apun);
if(contar == -1)
contar++;
temporal=apun;
getch();
break;

case '2':
/*OPCION PARA INSERTAR UN DATO AL ARBOL*/
system("cls");

if(contar == -1)
{
printf("No ha creado el arbol..");
getch();
break;
}
else
  {
  /*EN CASO DE HABER CREADO EL PRINCIPIO DEL ARBOL PODREMOS LUEGO
  AGREGAR DATOS Y AQUI LA RAIZ SE FIJA COMO NUMERO ESPECIAL Y SE 
  REALIZA TAMBIEN UN PROCEDIMIENTO PARA QUE LOS DATOS NO VUELVAN A REPETIRSE*/
  if(contar == 0) printf("Ingrese el numero a insertar como raiz en el arbol: ");
  else if(contar > 0) printf("Ingrese el numero a insertar en el arbol: ");
  fflush(stdin);scanf("%d",&entero);
  if(contar == 0)primero=entero;  
  buscar = buscar_dato(temporal->puntero,entero);
  if(buscar == 0)
  {
  printf("El dato se agrego correctamente...");
  agregar_dato(&(temporal->puntero),entero);
  contar++;
  }
  else
  printf("El dato ya existe por ende no se agregara...");
  }
getch();
break;

case '3':
/*OPCION PARA BORRAR UN DATO*/
system("cls");
if(contar == -1)
{
printf("\n\n\tNo ha creado el arbol..");
getch();
break;
}
else if(contar == 0)
{
printf("\n\n\tEl arbol no posee datos...");
getch();
break;
}
else
{
  if(contar > 0) 
  {
  printf("Ingrese el numero distinto al de la raiz para borrar en el arbol: ");
  fflush(stdin);scanf("%d",&entero);
  /*AQUI LIMITARE QUE NO SE BORRE LA RAIZ DE UN NUMERO, ESTA SERA PERMANENTE*/
  if((buscar_dato(temporal->puntero,entero)==1) && (entero != primero))
  {
  borrar_dato(&(temporal->puntero),entero);
  contar--;
  printf("El dato ha sido removido...");
  }
  else
  printf("\n\n\tPosiblemente el dato no se encuentra en el \n\tarbol o bien es la raiz de este...");
}
}
getch();
break;

case '4':
/*OPCION MOSTRAR EL ARBOL BINARIO*/

      do
      {
      system("cls");
      printf("\n\n\t\t-----------------------------------------\n");
      printf("\t\t   MOSTRAR ARBOL DE BUSQUEDA BINARIA...\n");
      printf("\t\t-----------------------------------------\n\n");
      printf("\tA - PREORDEN\n");
      printf("\tB - INORDEN\n");
      printf("\tC - POSTORDEN\n");
      printf("\tD - POR NIVELES\n");
      printf("\tE - Salir\n");
      printf("\n\n\tIngrese su opcion: ");
      fflush(stdin);scanf("%c",&op2);
      op2 = toupper(op2);
         switch(op2)
         {
         case 'A':
         /*OPCION MOSTRAR POR PREORDEN*/
         system("cls");
         preorden(temporal->puntero);
         getch();
         break;
         
         case 'B':
         /*OPCION MOSTRAR POR INORDEN*/
         system("cls");
         inorden(temporal->puntero);
         getch();
         break;
         
         case 'C':
         /*OPCION MOSTRAR POR POSTORDEN*/
         system("cls");
         postorden(temporal->puntero);
         getch();
         break;
         
         case 'D':
         /*OPCION MOSTRAR POR NIVELES*/
         system("cls");
         printf("Esta funcion aun no esta disponible...");
         getch();
         break;
         
         case 'E':
         /*OPCION SALIR DEL SUBMENU DEL PROGRAMA*/
         system("cls");
         break;
         
         default:
         /*OPCION EN CASO DE NO EXISTIR LA OPCION DE MENU PRINCIPAL*/
         
         break;
      }  
      }
      while(op2 != 'E');
break;

case '5':
/*OPCION SALIR DEL PROGRAMA*/
system("cls");
printf("\n\n\tPrograma creado por Daniel Gutierrez Pizarro\n");
printf("\tEstructura de datos 2009\n");
printf("\tPresione tecla para salir\n");
getch();
break;

default:
/*OPCION EN CASO DE NO EXISTIR LA OPCION DE MENU PRINCIPAL*/

break;
}
}
while(op1 != '5');
}
