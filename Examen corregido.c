#include<stdio.h>
#include<stdlib.h>

struct Dato{
    int d;
    struct Dato *sig,*ant;
};

int menu(void){

    int op;

    printf("***MENU***\n");
    printf("[1]...Insertar\n");
    printf("[2]...Eliminar\n");
    printf("[3]...Mostrar\n");
    printf("[4]...Salir\n");
    scanf("%d",&op);

    return op;
}

int main(){

    struct Dato *ptr=NULL,*nuevo=NULL,*ptraux,*ultimo;
    int op,dato,band;

    do{

        op=menu();

        switch(op){

        case 1:

            nuevo=(struct Dato*)malloc(sizeof(struct Dato));

            if(nuevo==NULL){

                printf("No se reservo memoria\n");

            }else{

                printf("Ingrese dato: ");
                scanf("%d",&nuevo->d);

                if(ptr==NULL){

                    ptr=nuevo;
                    nuevo->sig=nuevo;
                    nuevo->ant=nuevo;

                }else{

                    ultimo=ptr->ant;

                    ultimo->sig=nuevo;
                    nuevo->ant=ultimo;

                    nuevo->sig=ptr;
                    ptr->ant=nuevo;
                }

                printf("Nodo insertado\n");
            }

            break;

        case 2:

            if(ptr==NULL){

                printf("Lista vacia\n");

            }else{

                printf("Dato a eliminar: ");
                scanf("%d",&dato);

                ptraux=ptr;
                band=0;

                do{

                    if(ptraux->d==dato){

                        band=1;

                        if(ptraux->sig==ptraux){

                            ptr=NULL;

                        }else{

                            ptraux->ant->sig=ptraux->sig;
                            ptraux->sig->ant=ptraux->ant;

                            if(ptraux==ptr){

                                ptr=ptraux->sig;
                            }
                        }

                        free(ptraux);

                        printf("Nodo eliminado\n");

                        break;
                    }

                    ptraux=ptraux->sig;

                }while(ptraux!=ptr);

                if(band==0){

                    printf("Dato no encontrado\n");
                }
            }

            break;

        case 3:

            if(ptr==NULL){

                printf("Lista vacia\n");

            }else{

                ptraux=ptr;

                printf("\nDatos:\n");

                do{

                    printf("%d -> ",ptraux->d);

                    ptraux=ptraux->sig;

                }while(ptraux!=ptr);

                printf("(inicio)\n");
            }

            break;

        case 4:

            printf("Saliendo...\n");

            while(ptr!=NULL){

                if(ptr->sig==ptr){

                    free(ptr);
                    ptr=NULL;

                }else{

                    ptraux=ptr->ant;

                    ptraux->sig=ptr->sig;
                    ptr->sig->ant=ptraux;

                    nuevo=ptr;
                    ptr=ptr->sig;

                    free(nuevo);
                }
            }

            break;

        default:

            printf("Opcion invalida\n");
        }

    }while(op!=4);

    return 0;
}