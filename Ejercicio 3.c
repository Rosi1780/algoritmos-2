#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo_origen, *archivo_copia;
    char caracter;

    archivo_origen = fopen("origen.txt", "r");

    if (archivo_origen == NULL) {
        printf("'El archivo 'origen.txt' no existe.\n");
        return 1; 
    }

    archivo_copia = fopen("copia.txt", "w");
    
    if (archivo_copia == NULL) {
        printf("'No se pudo crear el archivo 'copia.txt'.\n");
        fclose(archivo_origen);
        return 1;
    }

    while ((caracter = fgetc(archivo_origen)) != EOF) {
        fputc(caracter, archivo_copia);
    }

    fclose(archivo_origen);
    fclose(archivo_copia);

    printf("El archivo se ha copiado exitosamente a 'copia.txt'.\n");

    return 0;
}