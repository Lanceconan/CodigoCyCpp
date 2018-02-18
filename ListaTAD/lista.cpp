#include "TDA_lista.h"

main()
{
char op;
int cant = 0,lista_actual = 0,entero;
pPUNTERO apun=NULL,temporal;
do
{
       system("cls");
       printf("\t\t-----------------------------------\n");
       printf("\t\t    Listas enlazadas con enteros\n");
       printf("\t\t-----------------------------------\n\n\n");
       printf("\tActualmente trabaja con %d listas\n\n",cant);
       printf("\t1 - Crear lista\n");
       printf("\t2 - Agregar dato a la lista actual\n");
       printf("\t3 - Sacar dato de la lista\n");
       printf("\t4 - Buscar dato en la lista\n");
       printf("\t5 - Listar\n");
       printf("\t6 - Primero y ultimo\n");
       printf("\t7 - Salir\n");
       printf("\n\tIngrese la opcion a trabajar: ");
       fflush(stdin);scanf("%c",&op);
switch(op)
{
case '1':
     system("cls");
     printf("\n\nCreo una nueva lista\n\n");
     crea_lista(&apun);
     cant++;
     if(lista_actual==0)temporal=apun;
     
     getch();
break;

case '2':
     system("cls");
     printf("\n\nTrabaja agregando datos\n\n");
     if(cant==0)
     {
     printf("\nNo ha creado ninguna lista todavia.");
     getch();
     break;
     }
           else
         {
         if(temporal->puntero == NULL)printf("HOLA");
         printf("Ingrese el numero que va a agregar: ");
         scanf("%d",&entero);
         agrega_dato(&(temporal->puntero),entero);
         printf("\nEl dato se agrego correctamente\n");
         }
getch();
break;

case '3':
system("cls");
printf("\n\nTrabaja sacando datos\n\n");
if(cant==0)
     {
     printf("\nNo ha creado ninguna lista todavia.");
     getch();
     break;
     }
           else
         {
         printf("Ingrese el numero que va a agregar: ");
         scanf("%d",&entero);
         saca_dato(&(temporal->puntero),entero);
         }
getch();
break;

case '4':
system("cls");
printf("\n\nTrabaja buscando datos\n\n");
 if(cant==0)
     {
     printf("\nNo ha creado ninguna lista todavia.");
     getch();
     break;
     }
     else
     {
     printf("\n\nIngrese el numero buscado en la lista: ");
     scanf("%d",&entero);
     busca_dato(&(temporal->puntero),entero);
     
     }
getch();
break;

case '5':
system("cls");
printf("\n\nTrabaja listando datos\n\n");
     if(cant==0)
     {
     printf("\nNo ha creado ninguna lista todavia.");
     getch();
     break;
     }
     else
     listar_dato(temporal->puntero);
getch();
break;

case '6':
system("cls");
printf("\n\nTrabaja mostrando primer y ultimo dato\n\n");
     if(cant==0)
     {
     printf("\nNo ha creado ninguna lista todavia.");
     getch();
     break;
     }
     else
     pri_ult(temporal->puntero);        
getch();
break;

case '7':
system("cls");
printf("\n\n\tUsted Salio del programa\n\n");
getch();
break;

default:
printf("Tecleo una opcion no valida......");
getch();
break;
}
}
while(op != '7');
system("cls");
printf("\n\n\tPrograma creado por Daniel Gutierrez Pizarro\n");
printf("\tEstructura de datos 2009\n");
printf("\tPresione tecla para salir\n");
getch();
}
