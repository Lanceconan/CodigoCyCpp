#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cola{
        int numero;
        struct cola* sig;
        struct cola* ant;
        }COLA;
		
       
typedef COLA *pCOLA;
		

typedef struct punteros{
        pCOLA puntero;
        struct punteros* sig;
        }PUNTERO2;
        
typedef PUNTERO2* pPUNTERO2;

/*ESTA FUNCION CREARA EL PRINCIPIO DE LA COLA*/
void crea_cola(pPUNTERO2 *puntero){
     pPUNTERO2 p1,p2;
     p1=*puntero;
     /*CREARA EL PRIMER ELEMENTO EN CASO DE NO EXISTIR*/
          if(p1==NULL){
          p1=(pPUNTERO2) malloc(sizeof(PUNTERO2));
          p1->puntero=NULL;
          p1->sig=NULL;
          *puntero=p1;
          printf("Creo una cola.....");
          }
          /*EN CASO CONTRARIO CREARA UNA SIGUIENTE LISTA*/
          else
          printf("Ya existe la cola.....");
          }
          
/*ESTA FUNCION AGREGA UN ELEMENTO ENTERO A LA COLA*/
void agrega_cola(pCOLA* puntero, int num){
     pCOLA p1,p2;
     /*ASIGNAMOS EL VALOR DEL PUNTERO REFERENCIADO POR p1*/
     p1=*puntero;
	 /*SI ES VALOR NULL CREARA EL PRIMER ELEMENTO*/
     if(p1==NULL){
		 /*SE LE ASIGNA ESPACIO DE MEMORIA*/
           p1=(pCOLA) malloc(sizeof(COLA));
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
          p2=(pCOLA) malloc(sizeof(COLA));
		  if(p2!=NULL){
          	p2->numero=num;
          	p2->sig=NULL;
			p2->ant=p1;
			/*Y EL ULTIMO NODO DE LA LISTA APUNTA AL NODO CREADO*/
          	p1->sig=p2;
			}
		}        
     }
     
/*FUNCION QUE PERMITE LISTAR LOS DATOS DE UNA COLA*/
void listar_cola(pCOLA puntero){
	pCOLA p1;
	p1=puntero;
	if(p1==NULL){
        printf("La cola esta vacia");
        return;         
        }
	/*MOSTRAMOS LOS VALORES DE LA COLA HASTA LLEGAR Al ULTIMO VALOR*/
	while(p1!=NULL){
		printf("->%d",p1->numero);
		p1=p1->sig;
		}
	} 
    
/*ESTA FUNCION COMPROBARA SI LA COLA ESTA VACIA*/
/*Mostrara la cantidad de elementos establecidos por 
una variable en el archivo .c*/
void comprobar_cola(pPUNTERO2 *puntero,int ent){
     if(puntero==NULL){
        printf("La cola esta vacia");
        return;         
        }
     else{
     printf("La cola existe y posee %d elementos.....",ent); 
}
return;        
}

/*FUNCION QUE PERMITE MOSTRAR EL PRIMER Y ULTIMO DATO DE LA COLA*/
void prim_ulti(pCOLA puntero){
     pCOLA p1;
     p1=puntero;
     /*Revisa si la cola esta vacia*/
     if(puntero == NULL){
     printf("La cola esta vacia...");
     return;
     }
     /*En caso de no estar vacia se recorre hasta dar con 
     el ultimo elemento de la cola y mostrarlo y como sabemos 
     cual es el primer elemento simplemente lo mostramos*/
     else
     while(puntero->sig!=NULL)puntero=puntero->sig;
     printf("\nEl primer valor da la cola es: %d",p1->numero);
     printf("\nEl ultimo valor de la cola es: %d",puntero->numero);
     }
/*FUNCION QUE PERMITE SACAR EL PRIMER ELEMENTO INGRESADO A LA COLA*/
/*Localiza el primer elemento de lista para asi poder eliminarlo, luego el nodo siguiente
se deja como el principal*/
void sacar_cola(pCOLA *puntero){
     pCOLA p1;
     p1=*puntero;
     *puntero=p1->sig;
     free(p1);
     return;
     }
