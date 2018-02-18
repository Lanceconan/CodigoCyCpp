#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct arbol{
        int numero;
        struct arbol *izq;
        struct arbol *der;
        struct arbol *padre;
        }ARBOL;
		
       
typedef ARBOL *pARBOL;
		

typedef struct punteros{
        pARBOL puntero;
        struct punteros *sig;
        }PUNTERO;
        
typedef PUNTERO *pPUNTERO;

/*ESTA FUNCION CREA UN NUEVO ARBOL CREANDO LA DIRECCION A LA RAIZ*/
void crea_arbol(pPUNTERO *puntero){
     pPUNTERO p1;
     p1=*puntero;
     /*CREARA LA DIRECCION PARA APUNTAR A LA RAIZ*/
          if(p1==NULL){
          p1=(pPUNTERO) malloc(sizeof(PUNTERO));
          p1->puntero=NULL;
          p1->sig=NULL;
          *puntero=p1;
          printf("\n\n\tCreo el principio del arbol\n\n");
          }
          /*EN CASO CONTRARIO MOSTRARA UN MENSAJE DE ....*/
          else
          printf("\n\n\tEl arbol ya fue creado...");
          /*AQUI ESTA LA OPCION PARA TRABAJAR CON VARIOS ARBOLES
          PERO NO QUIZE COMPLICAR MAS LAS COSAS*/
          }


/*ESTA FUNCION NOS PERMITIRA AGREGAR UN NUMERO
A NUESTRO ARBOL EN CASO DE SER EL PRIMERO ELEMENTO 
O DE SER EL ULTIMO*/          
void agregar_dato(pARBOL* puntero,int num){
     pARBOL p1,p2;
     p1=*puntero;
     if(p1==NULL){
     /*EN CASO DE SER NULL SE LE ASIGNA EL PRIMER ESPACIO DE MEMORIA AL PRIMER NODO DEL ARBOL*/
     p1=(pARBOL) malloc(sizeof(ARBOL));
     /*ALMACENAMOS LOS DATOS CORRESPONDIENTES PARA QUE SEA UN ARBOL BINARIO*/
                 p1->padre=NULL;
                 p1->izq=NULL;
                 p1->der=NULL;
                 p1->numero=num;
                 *puntero=p1;
                 }
     /*EN CASO DE NO SER EL PRIMERO*/
     else{
     		 	  
              
          /*SE DA UN NUEVO ESPACIO PARA OTRO NODO NUEVO*/
          p2=(pARBOL) malloc(sizeof(ARBOL));
          /*SE COMPLETAN LOS DATOS CARACTERISTICOS*/
          p2->padre=NULL;
          p2->izq=NULL;
          p2->der=NULL;
          p2->numero=num;
          
          
          /*CON EL SIGUIENTE PASO LOGRAREMOS ENLAZAR EL NODO CREADO AL ESPACIO EN
          DONDE CORRESPONDA IR SI ES MAYOR A LA DERECHA Y SI ES MENOR A LA IZQUIERDA*/
          while(1){
                  /*EN CASO DE SER MAYOR*/
                  if(num > p1->numero)
                  {
                     if(p1->der == NULL){
                     p1->der=p2;
                     p2->padre=p1;
                     return;
                     }
                     else{
                     p1=p1->der;
                     }
                  }
                  /*EN CASO DE SER MENOR*/ 
                  else{
                      if(p1->izq == NULL){
                      p1->izq=p2;
                      p2->padre=p1;
                      return;
                      }
                                      
                      else{
                      p1=p1->izq;
                      }
                      }
            }          
        }
     }
/*ESTA FUNCION NOS PERMITIRA BORRAR UN ELEMENTO A TRAVES DE UN FILTRO  
BUSCADOR PARA SABER SI EL NUMERO EXISTE O NO ESTA FUNCION  FUE PUESTA 
COMO INSTRUCCION EN EL ABB1.c Y DEFINIDO COMO FUNCION EN TDA_Arbol.h 
(buscar_dato) */
void borrar_dato(pARBOL* puntero,int num){
	pARBOL p1,p2,p3;
	/*PARA NO USAR TANTO ASTERISCO ASIGNAMOS EL PARAMETRO REFERENCIADO*/
    p1=*puntero;
			/*SE BUSCARA EL DATO HASTA ENCONTRARLO*/
	while(1){
         if(p1->numero==num){
         p1->numero=0;
         goto B;
         }
          else{
          if(num < p1->numero)p1=p1->izq;
          else if(num > p1->numero)p1=p1->der;
          }
        }	
	
	B:
	/*LUEGO DE HABER REMOVIDO EL DATO DEBEMOS ENCONTRAR EL 
    MENOR DE LOS MAYORES POR NORMA PARA QUE EL ARBOL NO QUEDE DISCONEXO*/
	while(p1->izq != NULL || p1->der != NULL){
		/*SI NO EXISTEN DATOS MENORES*/
		if(p1->izq == NULL){
			/*SE PONE EN LUGAR DEL NUMERO ELIMINADO EL DE SU HIJO DERECHO*/
			if(p1->padre != NULL){
			      if(p1->padre->izq == p1){
                        p1->padre->izq = p1->der;
                        p1->der->padre = p1->padre;
                        }
      			  else if(p1->padre->der == p1){
                        p1->padre->der = p1->der;
                        p1->der->padre = p1->padre;
                        }                                               
                  }
                  else{
                        *puntero=p1->der;
                        }
                        /*SE DEBE LIBERAR EL NODO ELIMINADO*/
			            free(p1);
               			/*TERMINA EL ASUNTO*/
			            return;
			      }
		/*EN CASO CONTRARIO*/
		else{
			/*AUNTARA A SU HIJO IZQUIERDO*/
			p2=p1->izq;
			/*Y LLEGAREMOS AL MAYOR DE SUS HIJOS*/
			while(p2->der != NULL)p2 = p2->der;
			/*LUEGO SE ASIGNA A SU NUMEROAL DATO DEL NODO QUE SE HABIA ELIMINADO*/
			p1->numero = p2->numero;
			p2->numero=0;
			p1 = p2;
			}
		}
	return;
	}

/*SE BUSCARA UN DATO A TRAVES DE UN RECORRIDO PREORDEN*/
int buscar_dato(pARBOL puntero,int num){
int hola,chao=0;
if (puntero != NULL){
if(puntero->numero == num)
hola = 1;
chao = buscar_dato(puntero->izq,num);
chao = buscar_dato(puntero->der,num);
}
if (hola == 1)
return hola;
else
return chao;
}

	
void preorden(pARBOL puntero){
if (puntero != NULL){
printf("%d >>> ",puntero->numero);
preorden(puntero->izq);
preorden(puntero->der);
}
}

void postorden(pARBOL puntero){
if (puntero != NULL){
postorden(puntero->izq);
postorden(puntero->der);
printf("%d >>> ",puntero->numero);
}
}

void inorden(pARBOL puntero){
if (puntero != NULL){
inorden(puntero->izq);
printf("%d >>> ",puntero->numero);
inorden(puntero->der);
}
}

