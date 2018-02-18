#include "TDA_pila.h"
#include "TDA_cola.h"

main()
{
/*Variables enteras para las pilas*/
int number1=0,contpila=0,listaactual=0,datospila=0;
/*Variables enteras para las colas*/
int datoscola=0,number2=0,contcola=0,lista_actual=0;
/*Punteros validos para trabajar con colas*/
pPUNTERO2 apun2=NULL,temporal2;
/*Punteros validos para trabajar con pilas*/
pPUNTERO1 apun1=NULL,temporal1;
/*Caracteres validos para trabajar con opciones de menu*/
char op,op2;
do
{                                           /*Apertura de DO principal*/
/*Menu principal*/
      system("cls");
      printf("\t\t-------------------------------------\n");
      printf("\t\t  Aprendiendo a usar pilas y colas\n");
      printf("\t\t           MENU PRINCIPAL\n");
      printf("\t\t-------------------------------------\n");
      printf("\n\n\t  Usted desea trabajar con:\n\n");
      printf("\t1 - Con Pilas\n");
      printf("\t2 - Con Colas\n");
      printf("\t3 - Salir\n\n");
      printf("\t   Ingrese la opcion: ");
      fflush(stdin);scanf("%c",&op);

switch(op)
{
case '1':
/*CASO 1 CUANDO DE TRABAJA CON PILAS*/
do
{                          /*INICIO DE MENU DE PILAS*/
system("cls");
printf("\t\t-------------------------------------\n");
printf("\t\t         MENU DE PILAS\n\n");
printf("\t\t-------------------------------------\n\n");
             
             printf("1 - Crear pila\n");
             printf("2 - Comprobar la pila\n");
             printf("3 - Tope de la pila\n");
             printf("4 - Agregar pila\n");
             printf("5 - Sacar pila\n");
             printf("6 - Listar pila\n");
             printf("7 - largo pila\n");
             printf("8 - Salir de MENU DE PILA\n\n");
             printf("Ingrese con que opcion va a trabajar: ");
             fflush(stdin);scanf("%c",&op2);
             switch(op2)
             {
             case '1':
             /*Crear pila*/
             system("cls");
             crea_pila(&apun1);
             contpila++;
             if(listaactual==0)temporal1=apun1;
             getch();
             break;
             
             case '2':
             /*Comprobar la pila*/
             system("cls");
             if(contpila == 0)
             printf("La pila no existe...");
             else
             comprobar_pila(&apun1,datospila);
             getch();
             break;
             
             case '3':
             /*Tope de la pila*/
             system("cls");
             tope_pila(temporal1->puntero1);
             getch();
             break;
             
             case '4':
             /*Agregar pila*/
             system("cls");
             if(contpila==0)
             {
             printf("\nNo ha creado la pila.");
             getch();
             break;
             }
             else
             {
             printf("Ingrese el numero que va a agregar a la pila: ");
             scanf("%d",&number1);
             agrega_pila(&(temporal1->puntero1),number1);
             printf("\nEl dato se agrego correctamente a la pila\n");
             getch();
             datospila++;
             }
             break;
             
             case '5':
             /*Sacar pila*/
             system("cls");
             if(datospila == 0)
             printf("\n\nLa pila no posee datos...");
             else
             {
             sacar_pila(&(temporal1->puntero1));
             datospila--;
             }
             getch();
             break;
             
             case '6':
             /*Listar pila*/
             system("cls");
             if(contpila==0)
             {
             printf("\nNo ha creado la pila aun....");
             getch();
             break;
             }
             else
             printf("La pila esta con el siguiente orden:\n\n");
             listar_pila(temporal1->puntero1,datospila);
             getch();
             break;
             
             case '7':
             /*largo pila*/
             system("cls");
             if(datospila > 0)
             printf("El largo de pila es %d elementos...",datospila);
             else
             printf("La pila no posee datos...");
             getch();
             break;
             
             case '8':/*Valido para salir de menu pila*/
             break;
             
             
             default:
             printf("Tecleo una opcion no valida....");
             getch();
             break;
             }
}
while(op2 != '8');     /*CIERRE DE MENU DE PILAS*/
break;                 /*CIERRE DE CASO 1 MENU PRINCIPAL*/



case '2':
/*CASO 1 CUANDO DE TRABAJA CON COLAS*/
do
{                                           /*APERTURA DE MENU DE COLAS */
system("cls");
printf("\t\t-------------------------------------\n");
printf("\t\t           MENU DE COLAS\n\n");
printf("\t\t-------------------------------------\n");

             printf("1 - Crear cola\n");
             printf("2 - Comprobar la cola\n");
             printf("3 - Primero y Ultimo cola\n");
             printf("4 - Agregar cola\n");
             printf("5 - Sacar cola\n");
             printf("6 - Listar cola\n");
             printf("7 - largo cola\n");
             printf("8 - Salir de MENU DE COLAS \n\n");
             printf("Ingrese con que opcion va a trabajar: ");
             fflush(stdin);scanf("%c",&op2);
             switch(op2)
             {
             case '1':
             /*Crear cola*/
             system("cls");
             crea_cola(&apun2);
             contcola++;
             if(lista_actual==0)temporal2=apun2;
             getch();
             break;
             
             case '2':
             /*Comprobar la cola*/
             system("cls");
             if (contcola == 0)
             printf("La cola no existe...");
             else
             comprobar_cola(&apun2,datoscola);
             getch();
             break;
             
             case '3':
             /*Primero y Ultimo cola*/
             system("cls");
             prim_ulti(temporal2->puntero);
             getch();
             break;
             
             case '4':
             /*Agregar cola*/
             system("cls");
             if(contcola==0)
             {
             printf("\nNo ha creado la cola todavia...");
             getch();
             break;
             }
             else
             {
             printf("Ingrese el numero que va a agregar a la cola: ");
             scanf("%d",&number2);
             agrega_cola(&(temporal2->puntero),number2);
             printf("\nEl dato se agrego correctamente a la cola\n");
             getch();
             datoscola++;
             }
             break;
             
             case '5':
             /*Sacar cola*/
             system("cls");
             if(datoscola == 0)
             printf("\n\nLa cola no posee datos...");
             else
             {
             sacar_cola(&(temporal2->puntero));
             datoscola--;
             printf("La cola fue removida...");
             }
             getch();
             break;
             
             case '6':
             /*Listar cola*/
             system("cls");
             if(contcola==0)
             {
             printf("\nNo ha creado la cola aun....");
             getch();
             break;
             }
             else
             printf("La cola esta con el siguiente orden:\n\n");
             listar_cola(temporal2->puntero);
             getch();
             break;
             
             case '7':
             /*largo cola*/
             system("cls");
             if(datoscola > 0)
             printf("El largo de cola es %d elementos...",datoscola);
             else
             printf("La cola no tiene datos...");
             getch();
             break;
             
             case '8':/*Valido para salir del menu colas*/
             break;
             
             
             default:
             printf("Tecleo una opcion no valida....");
             getch();
             break;
             }

}                                           /*CIERRE DE MENU DE COLAS*/
while(op2 != '8');             
break;                                      /*CIERRE DE CASO 2 MENU PRINCIPAL*/


case '3':
/*SALIR DEL PROGRAMA PRINCIPAL.......*/
system("cls");
printf("\n\n\t\tUsted salio del programa principal\n");
getch();
break;

default:
printf("Esta opcion no esta disponible....\n");
getch();
break;
}


}                                          /*Cierre de DO principal*/
while(op != '3');
system("cls");
printf("\n\n\tPrograma creado por Daniel Gutierrez Pizarro");
printf("\n\tEstructura de datos 2009");
printf("\n\tPRESIONA TECLA PARA CONTINUAR......");
getch();
return 0;
} 
