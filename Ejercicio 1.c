#include <stdio.h>

typedef struct {
    char nombre[50];
    int nota;
} Alumno;

int main() {
    Alumno alumnos[3] = {
        {"Jose Vega", 20},
        {"Natalia Acurero", 18},
        {"Rose Collins", 7}
    };
    
    FILE *pt = fopen("lista_estudiantes.bin", "wb");
    if (pt == NULL) {
        printf("Error al abrir archivo para escritura\n");
        return 1;
    }
    
    fwrite(alumnos, sizeof(Alumno), 3, pt);
    fclose(pt);
  
    Alumno alumnos_leidos[3];
    pt = fopen("lista_estudiantes.bin", "rb");
    if (pt == NULL) {
        printf("Error al abrir archivo para lectura\n");
        return 1;
    }
    
    fread(alumnos_leidos, sizeof(Alumno), 3, pt);
    fclose(pt);

    printf("Lista de estudiantes:\n");
    for (int i = 0; i < 3; i++) {
        printf("Alumno %d: %s, Nota: %d\n", 
               i+1, alumnos_leidos[i].nombre, alumnos_leidos[i].nota);
    }
    
    return 0;
}
