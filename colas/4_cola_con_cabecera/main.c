#include <stdio.h>
#include <stdlib.h>

#define TAM_CADENA 10
#include "cola.h"

int main() {
    Cola *cola = crear_cola();
    Nodo *nodo_extraer = NULL;
    int opcion, id;
    char id_cadena[TAM_CADENA];
    limpiar_pantalla();

    do {
        menu(&opcion);
        switch (opcion) {
            case 1:
                id = lee_numero("\n\tIntroduce id para el nodo: ");
                limpiar_pantalla();
                Nodo *nuevo_nodo = crear_nodo(id);
                if (nuevo_nodo == NULL) {
                    printf("\n\t***NO SE PUDO CREAR EL NODO***\n\n");
                    return 1;
                } else {
                    insertar_nodo(cola, nuevo_nodo);
                    printf("\tNodo agregado: [%d]\n\n", id);
                }
                break;

            case 2:  // extraer nodo
                if (cola->primero == NULL) {
                    limpiar_pantalla();
                    printf("No hay nada que extraer...\n\n");
                } else {
                    limpiar_pantalla();
                    nodo_extraer = extraer_nodo(cola);
                    printf("Se extrajo el nodo[%d]\n\n", nodo_extraer->id);
                }
                break;

            case 3:  // eliminar nodo
                if (cola->primero == NULL) {  // si es NULL esta vacia
                    limpiar_pantalla();
                    printf("*** La cola esta vacia ***\n\n");
                } else {
                    limpiar_pantalla();
                    eliminar_nodo(cola);
                    printf("Primer Nodo eliminado\n");
                }
                break;
            case 4:  // imprimir cola
                limpiar_pantalla();
                imprimir_cola(cola);
                break;

            case 5:  // numero de nodos
                limpiar_pantalla();
                printf("Cantidad de elementos en cola: [%d]\n\n", numero_elementos_cola(cola));
                break;

            case 6:
                if (nodo_extraer != NULL) {
                    limpiar_pantalla();
                    insertar_nodo(cola, nodo_extraer);
                    printf("Nodo [%d] se recupero a la cola\n\n", nodo_extraer->id);
                    nodo_extraer = NULL;                    
                } else {
                    limpiar_pantalla();
                    printf("No se encontro nodo a recuperar...\n\n");
                }
                break;

            case 7:  // salir
                printf("\n\n\tSaliendo...\n");
                break;

            default:
                limpiar_pantalla();
                printf("*** Opcion invalida ***\n");
                break;
        }
        
    } while (opcion != 7);

    return 0;
}
