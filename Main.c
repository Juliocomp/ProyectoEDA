#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "ManipulacionArchivo.h"
int main(){
    int opcion, mostrar, orden;
    Facultad *facultad;
    facultad = crearFacultad();
    ObtenerDatos(facultad);
    //listarEstructura(facultad);
    do {
        printf("Bienvenido que deseas hacer :D");
        opcion = Menu("\n1)Buscar cafeterias dependiendo de la Facultad\n2)Fijar una orden en la cafeteria\n3)Descargar ticket para recoger\n4)Poner una review rapida\n5)Salir\nOpcion: ",5);
        switch (opcion){
        case 1:
            system("clear");
            //system("cls");
            printf("Las facultades son:\n");
            for (int i = 0; i < MAX_FACULTADES; i++){
                printf("\t%i) %s\n",(i+1), facultad[i].nombreFacultad);
            }
            mostrar = Menu("\tSelecciona la Facultad que desees para mostrarte sus cafeterias: ",9);
            system("clear");
            //system("cls");
            BuscarFacultad(facultad[(mostrar-1)]);
            PausarPantalla();
            break;
        case 2:
           system("clear");
           printf("Las facultades son:\n");
            for (int i = 0; i < MAX_FACULTADES; i++){
                printf("\t%i) %s\n",(i+1), facultad[i].nombreFacultad);
            }
           orden = Menu("Selecciona la Facultad que desees para fijar tu orden: ",9);
           system("clear");
           generarorden(facultad[(orden-1)]);
           PausarPantalla();
           break;
        case 3:
            system("clear");
            leerticket();
            PausarPantalla();
            break;
        case 4:
            break;
        }
        system("clear");
        //system("cls");
    } while (opcion != 5);
    LiberarMD(facultad);
    return 0;
}
