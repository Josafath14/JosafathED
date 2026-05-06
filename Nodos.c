#include <stdio.h>
#include <stdlib.h>

struct Dato{
	int d;
	struct Dato *ptrSig;
};

int menu(void){
	int opcion;
    printf("\n...MENU...\n");
	printf("[1]... Crear dato\n");
    printf("[2]... funciones\n");
	printf("[3]... Mostrar dato\n");
	printf("[4]... Liberar dato\n");
	printf("[5]... Salir\n");
	printf("Escoga la opcion a utilizar: ");
	scanf("%d", &opcion);
	return opcion;
}

int submenu(void){
    int opc;
    printf("\n...Submenu...\n");
    printf("[1]... Buscar...\n");
    printf("[2]... Contar...\n");
    printf("[3]... Remplazar...\n");
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
void Remplazar(struct Dato *ptr);
void Ordenar(struct Dato *ptr);

int main (void){
	struct Dato *ptr = NULL;
	int opcion, opc;
    printf("bienvenido al codigo de nodos\n");

	do{
		opcion = menu();
		switch(opcion){
			case 1:
				crearDato(&ptr);
				break;
            case 2:
                submenu();
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
                        Remplazar(ptr);
                        break;
                    case 4:
                        Ordenar(ptr);
                        break;
                    case 5:
                        Salir(&ptr);
                        printf("Regresando...\n");
                    default:
                     printf("Opcion invalida\n");
                }
            } while(opc != 5);
                break;
			case 3:
				mostrarDato(ptr);
				break;
			case 4:
				liberarDato(&ptr);
				break;
			case 5:
				Salir(&ptr);
                printf("saliendo del programa...................\n");
				break;
			default:
				printf("Opcion invalida\n");
		}
	} while(opcion != 5);

}

void crearDato(struct Dato **ptr) {
    struct Dato *nuevo = (struct Dato *)malloc(sizeof(struct Dato));
    struct Dato *ptraux;

    if (nuevo == NULL) {
        printf("Error de memoria\n");
        return;
    }

    printf("Ingresa un numero: ");
    scanf("%d", &(nuevo->d));

    nuevo->ptrSig = NULL;

    if (*ptr == NULL) {
        *ptr = nuevo; 
    } else {
        ptraux = *ptr;
    
    while(ptraux != NULL){
        printf("%d ->",ptraux->d);
        ptraux = ptraux->ptrSig;
    }
    ptraux->ptrSig = nuevo;
}

        while (ptraux->ptrSig != NULL) {
            ptraux = ptraux->ptrSig;
        }
        ptraux->ptrSig = nuevo; 
    }


void mostrarDato(struct Dato *ptr){ 
    struct Dato *ptraux;

    if(ptr == NULL){
        printf("Lista vacia\n");
        return;
    }
    ptraux = ptr;
    
    while(ptraux != NULL){
        printf("%d ->",ptraux->d);
        ptraux = ptraux->ptrSig;
    }
    printf("NULL\n");
}

void liberarDato(struct Dato **ptr) {
    struct Dato *ptraux;
    struct Dato *anterior;

    if (*ptr == NULL) {
        printf("Lista vacia\n");
        }
    else{ 
    
        if ((*ptr)->ptrSig == NULL) {
            free(*ptr);
            *ptr = NULL;
            printf("se elimino el unico nodo\n");
            return;
            }
        else{ 
            ptraux = *ptr;
            while (ptraux->ptrSig != NULL) {
                anterior = ptraux;
                ptraux = ptraux->ptrSig;
                }
            anterior->ptrSig = NULL;
            free(ptraux);
            }
        printf("Se elimino el ultimo nodo\n");
        }   
}
void Salir(struct Dato **ptr){
    struct Dato *ptraux;

    while(ptr != NULL){
        ptraux = *ptr;
        *ptr =(*ptr)->ptrSig;
        free(ptraux);
    }

    printf("Lista liberada\n");
}

void Buscar(struct Dato *ptr){

    printf("usted eligio la opcion 1\n");
}

void contar(struct Dato *ptr){
    for( ; ; )


    printf("usted eligio opcion 2\n");
}

void Remplazar(struct Dato *ptr){

    printf("usted eligio opcion 3\n");
}

void Ordenar(struct Dato *ptr){

    printf("usted eligio opcion 4\n");
}
