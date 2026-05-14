#include <stdio.h>
#include <stdlib.h>

struct Dato{
	int d;
	struct Dato *ptrSig;
};

int menu(){
	int opcion;

    printf("\n...MENU...\n");
	printf("[1]... Crear dato\n");
    printf("[2]... Funciones\n");
	printf("[3]... Mostrar dato\n");
	printf("[4]... Liberar dato\n");
	printf("[5]... Salir\n");
	printf("Escoga la opcion a utilizar: ");
	scanf("%d", &opcion);

	return opcion;
}

int submenu(){

    int opc;

    printf("\n...Submenu...\n");
    printf("[1]... Buscar...\n");
    printf("[2]... Contar...\n");
    printf("[3]... Reemplazar...\n");
    printf("[4]... Ordenar...\n");
    printf("[5]... Salir...\n");
    printf("Eliga la opcion deseada..\n");
    scanf("%d",&opc);

    return opc;
}

void crearDato(struct Dato **ptr);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);
void Salir(struct Dato **ptr);

void Buscar(struct Dato *ptr);
void contar(struct Dato *ptr);
void Reemplazar(struct Dato *ptr);
void Ordenar(struct Dato *ptr);

int main(){

	struct Dato *ptr = NULL;

	int opcion, opc;

    printf("Bienvenido al codigo de nodos\n");

	do{

		opcion = menu();

		switch(opcion){

			case 1:

				crearDato(&ptr);

				break;

            case 2:

                do{

                    opc = submenu();

                    switch(opc){

                        case 1:

                            Buscar(ptr);

                            break;

                        case 2:

                            contar(ptr);

                            break;

                        case 3:

                            Reemplazar(ptr);

                            break;

                        case 4:

                            Ordenar(ptr);

                            break;

                        case 5:

                            printf("Regresando...\n");

                            break;

                        default:

                            printf("Opcion invalida\n");
                    }

                }while(opc != 5);

                break;

			case 3:

				mostrarDato(ptr);

				break;

			case 4:

				liberarDato(&ptr);

				break;

			case 5:

				Salir(&ptr);

                printf("Saliendo del programa...\n");

				break;

			default:

				printf("Opcion invalida\n");
		}

	}while(opcion != 5);

	return 0;
}

void crearDato(struct Dato **ptr){

    struct Dato *nuevo = (struct Dato *)malloc(sizeof(struct Dato));
    struct Dato *ptraux;

    if(nuevo == NULL){

        printf("Error de memoria\n");

        return;
    }

    printf("Ingresa un numero: ");
    scanf("%d",&nuevo->d);

    nuevo->ptrSig = NULL;

    if(*ptr == NULL){

        *ptr = nuevo;
    }
    else{

        ptraux = *ptr;

        while(ptraux->ptrSig != NULL){

            ptraux = ptraux->ptrSig;
        }

        ptraux->ptrSig = nuevo;
    }

    printf("Nodo agregado correctamente\n");
}

void mostrarDato(struct Dato *ptr){

    struct Dato *ptraux;

    if(ptr == NULL){

        printf("Lista vacia\n");

        return;
    }

    ptraux = ptr;

    while(ptraux != NULL){

        printf("%d -> ",ptraux->d);

        ptraux = ptraux->ptrSig;
    }

    printf("NULL\n");
}

void liberarDato(struct Dato **ptr){

    struct Dato *ptraux;
    struct Dato *anterior;

    if(*ptr == NULL){

        printf("Lista vacia\n");
    }
    else{

        if((*ptr)->ptrSig == NULL){

            free(*ptr);

            *ptr = NULL;

            printf("Se elimino el unico nodo\n");

            return;
        }
        else{

            ptraux = *ptr;

            while(ptraux->ptrSig != NULL){

                anterior = ptraux;

                ptraux = ptraux->ptrSig;
            }

            anterior->ptrSig = NULL;

            free(ptraux);

            printf("Se elimino el ultimo nodo\n");
        }
    }
}

void Salir(struct Dato **ptr){

    struct Dato *ptraux;

    while(*ptr != NULL){

        ptraux = *ptr;

        *ptr = (*ptr)->ptrSig;

        free(ptraux);
    }

    printf("Lista liberada\n");
}

void Buscar(struct Dato *ptr){

    int num;
    int band = 0;

    if(ptr == NULL){

        printf("Lista vacia\n");

        return;
    }

    printf("Ingresa el numero a buscar: ");
    scanf("%d",&num);

    while(ptr != NULL){

        if(ptr->d == num){

            band = 1;
        }

        ptr = ptr->ptrSig;
    }

    if(band == 1){

        printf("Numero encontrado\n");
    }
    else{

        printf("Numero no encontrado\n");
    }
}

void contar(struct Dato *ptr){

    int cont = 0;

    if(ptr == NULL){

        printf("Lista vacia\n");

        return;
    }

    while(ptr != NULL){

        cont++;

        ptr = ptr->ptrSig;
    }

    printf("Cantidad de nodos: %d\n",cont);
}

void Reemplazar(struct Dato *ptr){

    int viejo, nuevo;
    int band = 0;

    if(ptr == NULL){

        printf("Lista vacia\n");

        return;
    }

    printf("Numero a reemplazar: ");
    scanf("%d",&viejo);

    printf("Nuevo numero: ");
    scanf("%d",&nuevo);

    while(ptr != NULL){

        if(ptr->d == viejo){

            ptr->d = nuevo;

            band = 1;
        }

        ptr = ptr->ptrSig;
    }

    if(band == 1){

        printf("Numero reemplazado\n");
    }
    else{

        printf("Numero no encontrado\n");
    }
}

void Ordenar(struct Dato *ptr){

    struct Dato *i;
    struct Dato *j;

    int aux;

    if(ptr == NULL){

        printf("Lista vacia\n");

        return;
    }

    for(i = ptr; i != NULL; i = i->ptrSig){

        for(j = i->ptrSig; j != NULL; j = j->ptrSig){

            if(i->d > j->d){

                aux = i->d;
                i->d = j->d;
                j->d = aux;
            }
        }
    }

    printf("Lista ordenada correctamente\n");
}
