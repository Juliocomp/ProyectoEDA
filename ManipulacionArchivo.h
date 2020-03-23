//Constantes
#define MAX_TEXT 30
#define MAX_PLATILLOS 3
#define MAX_CAFETERIAS 2
#define MAX_FACULTADES 9
//Estructura para Leer Archivo
typedef struct{
    int idPlatillo[MAX_PLATILLOS];
    float precio[MAX_PLATILLOS];
    char nombrePlatillo[MAX_PLATILLOS][MAX_TEXT];
    char nombreCafeteria[MAX_TEXT];
    char nombreFacultad[MAX_TEXT];
}Lectura;
//Estructuras
typedef struct{
    int idPlatillo;
    char nombrePlatillo[MAX_TEXT];
    float precio;
}Platillo;
typedef struct{
    char nombreCafeteria[MAX_TEXT];
    Platillo *platillo;
}Cafeteria;
typedef struct{
    char nombreFacultad[MAX_TEXT];
    Cafeteria *cafeteria;
}Facultad;
//Prototipos
Facultad *crearFacultad();
void ObtenerDatos(Facultad *facultad);
void LlenarArchivo();
void listarEstructura(Facultad *facultad);
void BuscarFacultad(Facultad facultad);
void PausarPantalla();
void LiberarMD(Facultad *facultad);
void generarorden(Facultad facultad);
void leerticket();
