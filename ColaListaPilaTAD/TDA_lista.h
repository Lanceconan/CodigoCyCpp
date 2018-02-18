#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
        int numero;
        struct lista* sig;
        struct lista* ant;
        }LISTA;
		
       
typedef LISTA *pLISTA;
		

typedef struct punteros{
        pLISTA puntero;
        struct punteros* sig;
        }PUNTERO;
        
typedef PUNTERO* pPUNTERO;

/*ESTA FUNCION CREA UNA NUEVA LISTA CREANDO EL PRIMER ELEMENTO 
O SIGUIENTE EN CASO DE SER NECESARIO*/

void crea_lista(pPUNTERO *puntero){
     pPUNTERO p1,p2;
     p1=*puntero;
     /*CREARA EL PRIMER ELEMENTO EN CASO DE NO EXISTIR*/
          if(p1==NULL){
          p1=(pPUNTERO) malloc(sizeof(PUNTERO));
          p1->puntero=NULL;
          p1->sig=NULL;
          *puntero=p1;
          }
          /*EN CASO CONTRARIO CREARA UNA SIGUIENTE LISTA*/
          else{
          while(p1->sig != NULL) 
          p1=p1->sig;
          p2 = (pPUNTERO) malloc(sizeof(PUNTERO));
          
          if(p2 != NULL){
             p2->puntero = NULL;
             p2->sig = NULL;
             p1->sig = p2;
             }
          }
          }
          
/*ESTA FUNCION NOS PERMITIRA AGREGAR UN NUEMERO
A NUESTRA LISTA EN CASO DE SER EL PRIMERO ELEMENTO 
O DE SER EL ULTIMO*/
     void agrega_dato(pLISTA* puntero, int num){
     pLISTA p1,p2;
     /*ASIGNAMOS EL VALOR DEL PUNTERO REFERENCIADO POR p1*/
     p1=*puntero;
	 /*SI ES VALOR NULL CREARA EL PRIMER ELEMENTO*/
     if(p1==NULL){
		 /*SE LE ASIGNA ESPACIO DE MEMORIA*/
           p1=(pLISTA) malloc(sizeof(LISTA));
           p1->numero=num;
           p1->sig=NULL;
		   p1->ant=NULL;
		   /*EL PUNTERO CREADO SERA EL PRIMERO*/
           *puntero=p1;
           }
	/*POR EL CASO CONTRARIO*/
     else{
		 /*DEBEMOS LLEGAR AL ULTIMO NODO CREADO*/
          while(p1->sig!=NULL)p1=p1->sig;
		  /*LUEGO SE REPITE EL PROCESO ANTERIOR*/
          p2=(pLISTA) malloc(sizeof(LISTA));
		  if(p2!=NULL){
          	p2->numero=num;
          	p2->sig=NULL;
			p2->ant=p1;
			/*Y EL ULTIMO NODO DE LA LISTA APuNTA AL NODO CREADO*/
          	p1->sig=p2;
			}
		}        
     }

void saca_dato(pLISTA *puntero, int num){
	pLISTA p1,p2;
	
	/*SE ASIGNA EL VALOR DEL PUNTERO REFERENCIADO A  p1*/
	p1=*puntero;
	
	/*SE VERIFICA SI EXISTE UN SOLO ELEMENTO EN LA LISTA*/
	if(p1->sig==NULL){
		if(p1->numero==num){
			*puntero=NULL;
			free(p1);			
			printf("El entero a sido eliminado de la lista: ");
			return;
			}
		else{
			printf("\nEl entero no fue encontrado en esta lista...");
			return;
			}
		}
	/*ANALIZAMOS SI ES EL PRIMER ELEMENTO EL QUE HA DE ELIMINARSE*/	
	if(p1->numero==num){
         /*p2 APUNTA AL NODO A EIMINAR*/
         p2=p1;
         p1=p1->sig;
         /*PUNTERO QUE APUNTA AL SIGUIENTE NODO*/
         *puntero=p1;
         /*ELIMINAMOS AQUEL NODO*/
         free(p2);
         printf("El entero a sido eliminado de la lista: ");
         return;
         }
	/*SE RECORRE LA LISTA HASTA QUE p1 APUNTA EL NODO QUE APUNTA AL NODO CON EL ENTERO A ELIMINAR*/
    	while(p1->sig->numero!=num){
		p1=p1->sig;
		/*SI LLEGAMOS AL ULTIMO NODO SIGNIFICA QUE EL ENTERO NO ESTA EN LA LISTA*/
		if(p1->sig==NULL){
			printf("\nEl entero no fue encontrado en esta lista...");
			return;
			}
		}
	p2=p1->sig;
	p1->sig=p1->sig->sig;
	free(p2);	
	printf("El entero a sido eliminado de la lista: ");
	}

/*ESTA FUNCION NOS PERMITIRA MOSTRAR LOS ELEMNTOS DE LA LISTA EN EL ORDEN EN LE QUE FUERON INRESADOS*/
void listar_dato(pLISTA puntero){
	pLISTA p1;
	p1=puntero;
	if(p1==NULL){
        printf("La lista esta vacia");
        return;         
        }
	//MOSTRAMOS LOS VALORES DE LA LISTA HASTA LLEGAR A LA ULTIMA*/
	while(p1!=NULL){
		printf("->%d",p1->numero);
		p1=p1->sig;
		}
	}

    /*FUNCION PARA MOSTRAR EL PRIMER Y ULTIMO NUMERO EN LA LISTA*/
void pri_ult(pLISTA puntero){
     /*SI LA LISTA ESTA VACIA DEBEMOS TERMINAR LA FUNCION*/
    if(puntero==NULL){
          printf("La lista esta vacia");	
          return;
          }
    /*DE NO SER ASI SE IMPRIME EL PRIMER NUMERO*/
	printf("Primero: %d\n",puntero->numero);
	
 /*LUEGO BUSCAMOS EL ULTIMO ITERATIVAMENTE*/
	while(puntero->sig!=NULL)puntero=puntero->sig;
 /*Y SE MUESTRA EL ULTIMO ELEMENTO DE LA LISTA*/
	printf("Ultimo: %d\n",puntero->numero);
 }

/*FUNCION QUE BUSCA UN VALOR EN UNA LISTA*/

void busca_dato(pLISTA* puntero, int num)
{
int position=0,n=0;;
pLISTA p1;
p1=*puntero;
	 /*SI ES VALOR NULL SIGNIFICA QUE NO HAY ELEMENTOS*/
     if(p1==NULL) return;
     
     else
     {
      while(p1->sig!=NULL || p1->numero == num)
      {
      position++;
      if(p1->numero == num){
      printf("El numero %d existe en la posicion %d \n",num,position);
      return;
      }
      else
      n++;  
      p1=p1->sig;
      }
     if(n != 0)
     printf("El numero no existe en la lista actual.....");
     }   
}

