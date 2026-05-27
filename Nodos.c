#include<stdio.h>
#include<stdlib.h>

struct arbol{
    int dato;
    struct arbol *izq, *der;
};

struct arbol *crearnodo(){

    struct arbol *nuevo;

    nuevo = (struct arbol *)malloc(sizeof(struct arbol));

    if(nuevo == NULL){

        printf("Error de memoria\n");

        return NULL;
    }

    printf("Ingrese el dato: ");
    scanf("%d",&nuevo->dato);

    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

void mostrar(struct arbol *raiz){

    if(raiz != NULL){

        mostrar(raiz->izq);

        printf("%d ", raiz->dato);

        mostrar(raiz->der);
    }
}

int menu(void){

	int opcion;

    printf("\n...MENU...\n");
	printf("[1]... Crear dato\n");
    printf("[2]... Mostrar\n");
    printf("[3]... Salir\n");
	printf("Escoga la opcion a utilizar: ");

	scanf("%d", &opcion);

	return opcion;
}

int main(void){

    struct arbol *raiz, *ptrtemp, *ptrcop;

    int opcion;

    raiz = NULL;

	do{

		opcion = menu();

		switch(opcion){

			case 1:

				ptrtemp = crearnodo();

                if(ptrtemp == NULL)
                    printf("No se creo el nodo\n");

                else{

                    if(raiz == NULL)
                        raiz = ptrtemp;

                    else{

                        ptrcop = raiz;

                        do{

                            if(ptrtemp->dato < ptrcop->dato){

                                if(ptrcop->izq == NULL){

                                    ptrcop->izq = ptrtemp;
                                    break;
                                }

                                else
                                    ptrcop = ptrcop->izq;
                            }

                            else{

                                if(ptrcop->der == NULL){

                                    ptrcop->der = ptrtemp;
                                    break;
                                }

                                else
                                    ptrcop = ptrcop->der;
                            }

                        }while(1);
                    }
                }

				break;

			case 2:

                mostrar(raiz);

				break;
            
            case 3:

                printf("Saliendo del programa...\n");

				break;

			default:
				printf("Opcion invalida\n");
		}

	}while(opcion != 3);

return 0;
}
