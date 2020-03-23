#include <stdio.h>
#include "menu.h"

int Menu (char texto[], int n) {
   int opcion;
   do {
       printf("%s ",texto);
       scanf("%d", &opcion);
       if (opcion < 1 || opcion > n)
        printf("Error: opcion no valida...\n");
   } while (opcion < 1 || opcion > n);
   return opcion;
}


