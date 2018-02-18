#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pila{
        int numeros;
        struct pila* sig1;
        struct pila* ant1;
        }PILA;
		
       
typedef PILA *pPILA;
		

typedef struct punterosA{
        pPILA puntero1;
        struct punterosA* sig1;
        }PUNTERO1;
        
typedef PUNTERO1* pPUNTERO1;

/*ESTA FUNCION CREARA EL PRINCIPIO DE LA PILA*/
void crea_pila(pPUNTERO1 *puntero1){
     pPUNTERO1 p1,p2;
     p1=*puntero1;
     /*CREARA EL PRIMER ELEMENTO EN CASO DE NO EXISTIR*/
          if(p1==NULL){
          p1=(pPUNTERO1) malloc(sizeof(PUNTERO1));
          p1->puntero1=NULL;
          p1->sig1=NULL;
          *puntero1=p1;
          printf("Creo una pila.....");
          }
          /*EN CASO CONTRARIO MOSTRARA UN MENSAJE*/
          else
          printf("Ya existe la pila.....");
          }
          
/*ESTA FUNCION AGREGA UN ELEMENTO ENTERO A LA COLA*/
void agrega_pila(pPILA* puntero1, int num){
     pPILA p1,p2;
     /*ASIGNAMOS EL VALOR DEL PUNTERO REFERENCIADO POR p1*/
     p1=*puntero1;
	 /*SI ES VALOR NULL CREARA EL PRIMER ELEMENTO*/
     if(p1==NULL){
		 /*SE LE ASIGNA ESPACIO DE MEMORIA*/
           p1=(pPILA) malloc(sizeof(PILA));
           p1->numeros=num;
           p1->sig1=NULL;
		   p1->ant1=NULL;
		   /*EL PUNTERO CREADO SERA EL PRIMERO*/
           *puntero1=p1;
           }
	/*POR EL CASO CONTRARIO*/
     else{
		 /*DEBEMOS LLEGAR AL ULTIMO NODO CREADO*/
          while(p1->sig1!=NULL)p1=p1->sig1;
		  /*LUEGO SE REPITE EL PROCESO ANTERIOR*/
          p2=(pPILA) malloc(sizeof(PILA));
		  if(p2!=NULL){
          	p2->numeros=num;
          	p2->sig1=NULL;
			p2->ant1=p1;
			/*Y EL ULTIMO NODO DE LA LISTA APuNTA AL NODO CREADO*/
          	p1->sig1=p2;
			}
		}        
     }
     
/*FUNCION QUE PERMITE LISTAR LOS DATOS DE UNA COLA*/
/*Creara un array con los elemntos de la pila para visualizar
su correcto orden dentro de pila....*/
void listar_pila(pPILA puntero1,int cantidad){
	pPILA p1;
	int array[cantidad-1];
	p1=puntero1;
	if(p1==NULL){
        printf("La cola esta vacia");
        return;         
        }
	//MOSTRAMOS LOS VALORES DE LA COLA HASTA LLEGAR Al ULTIMO VALOR*/
	int i=0;
    while(p1!=NULL){
        array[i] = p1->numeros;
		//printf("->%d",array[i]);
		p1=p1->sig1;
		i++;
        }
	while(i>0)
	{
    i--;
	printf("->%d",array[i]);
	}
    }
    
/*ESTA FUNCION COMPROBARA SI LA PILA ESTA VACIA*/
/*Nos mostrara un mensaje de cantidad de elementos 
ademas afirmara que la pila posee datos o si no 
los tiene*/
void comprobar_pila(pPUNTERO1 *puntero,int ent){
     if(puntero==NULL){
        printf("La pila esta vacia");
        return;         
        }
     else{
     printf("La pila existe y posee %d elementos.....",ent); 
}
return;        
} 


/*FUNCION QUE PERMITE SABER CUAL ES EL TOPE O PRIMER ELEMENTO DE LA PILA*/
/*Nos mostrara el ultimo elemto ingresado en la pila 
o bien el ultimo numero ingresado*/
void tope_pila(pPILA puntero){
     if(puntero==NULL)
     printf("La pila esta vacia...");
     else
     while(puntero->sig1!=NULL)puntero=puntero->sig1;
     printf("El tope de la pila es: %d",puntero->numeros);
     }
     
/*FUNCION QUE PERMITE SACAR EL PRIMER DATO DE LA PILA O EL ULTIMO INGREASADO*/
void sacar_pila(pPILA *puntero){
     pPILA p1,p2,paux;
     int DATO;
     /*Primero se encuentra el ultimo valor de la lista, o sea
     el primer valor de la pila*/
     paux=*puntero;
     while(paux->sig1!=NULL)paux=paux->sig1;
     DATO=paux->numeros;
     /*Luego de obtenerlo usamos un algoritmo para eliminar
     un elemento en una posicion n*/
     p1=*puntero;
     if(p1->sig1==NULL){
		if(p1->numeros==DATO){
			*puntero=NULL;
			free(p1);			
			printf("\nEl valor de la pila fue removido...");
			return;
			}
		
		}
	/*ANALIZAMOS SI ES EL PRIMER ELEMENTO EL QUE HA DE ELIMINARSE*/	
	if(p1->numeros==DATO){
         /*p2 APUNTA AL NODO A ElIMINAR*/
         p2=p1;
         p1=p1->sig1;
         /*PUNTERO QUE APUNTA AL SIGUIENTE NODO*/
         *puntero=p1;
         /*ELIMINAMOS AQUEL NODO*/
         free(p2);
         printf("\nEl valor de la pila fue removido...");
         return;
         }
	     /*SE RECORRE LA LISTA HASTA QUE p1 APUNTA EL NODO QUE APUNTA AL NODO CON EL ENTERO A ELIMINAR*/
    	while(p1->sig1->numeros!=DATO){
		p1=p1->sig1;
		
		}
	    p2=p1->sig1;
	    p1->sig1=p1->sig1->sig1;
     	free(p2);	
        printf("\nEl valor de la pila fue removido...");
     return;
     }
              

