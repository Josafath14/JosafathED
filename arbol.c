#include<stdio.h>

struct arbol{
    int dato;
    struct arbol *izq, *der;
};

int menu(void){
	int opcion;
    printf("\n...MENU...\n");
	printf("[1]... Crear dato\n");
    printf("[2]... Salir\n");
	printf("Escoga la opcion a utilizar: ");
	scanf("%d", &opcion);
	return opcion;
}





int main(void){
    struct arbol *raiz, *ptrtemp, *ptrcop;
    int opcion;
    raiz=NULL;
    ptrcop=raiz;

do{
		opcion = menu();
		switch(opcion){
			case 1:
				ptrtemp = crearnodo();
                if(ptrtemp==NULL)
                    printf("no se creo el nodo");
                else{
                    if(raiz==NULL)
                        raiz= ptrtemp;
                    else{
                        do(){
                            if(ptrcop->dato<ptrtemp)
                                if(ptrcop->izq=!NULL)
                                    ptrcop->izq=ptrtemp;

                                else{ 
                                    ptrcop=ptrcop->izq;
                                }

                            else{
                                if(ptrcop->der=!NULL)
                                    ptrcop->der=ptrtemp;

                                else{ 
                                    ptrcop=ptrcop->der;
                                }
                            }
                        }
                    }
                }
				break;
			case 2:
				Salir();
                printf("saliendo del programa...................\n");
				break;
			default:
				printf("Opcion invalida\n");
		}
	} while(opcion != 2);

return 0;
}

