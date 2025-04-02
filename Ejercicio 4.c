#include <stdio.h>
#include <string.h>

struct Alumno {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    struct Alumno alumnos[3] = {
        {"Juan Perez", 20, 8.5},
        {"Maria Garcia", 19, 9.1},
        {"Carlos Lopez", 21, 7.8}
    };
    
    FILE *archivo = fopen("alumno.dat", "wb");
    if (archivo == NULL) {
        printf("Error al crear archivo!");
        return 1;
    }
    
    fwrite(alumnos, sizeof(struct Alumno), 3, archivo);
    fclose(archivo);
    
    struct Alumno alumnos_lista[3];
    archivo = fopen("alumno.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir archivo!");
        return 1;
    }
    
    fread(alumnos_lista, sizeof(struct Alumno), 3, archivo);
    fclose(archivo);
    
    for (int i = 0; i < 3; i++) {
        printf("\nAlumno %d:\n", i+1);
        printf("Nombre: %s\n", alumnos_lista[i].nombre);
        printf("Edad: %d\n", alumnos_lista[i].edad);
        printf("Promedio: %.1f\n", alumnos_lista[i].promedio);
    }
    
    return 0;
}