#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, numero_leido;
    char crear_archivo[] = "archivo_binario.bin";
    FILE *archivo;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    archivo = fopen(crear_archivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return 1;
    }

    fwrite(&numero, sizeof(int), 1, archivo);
    fclose(archivo);

    archivo = fopen(crear_archivo, "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    fread(&numero_leido, sizeof(int), 1, archivo);
    fclose(archivo);

    printf("El numero del archivo es: %d\n", numero_leido);

    return 0;
}