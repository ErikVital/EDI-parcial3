/*
    Escriba un programa en C que dada la siguiente declaración de estructuras:
    typedef struct {
        char nombre[40];
        char pais[25];
    }DatosPersonales;
    typedef struct{
        DatosPersonales datos;
        char deporte[30];
        int numMedallas;
    }Deportista;
    1. Realice una función que lea de un archivo de TEXTO la información de los deportistas.
    2. Realice una función que reciba los deportistas leídos y calcule e imprima el número de medallas por
    deporte.
    Nota: Dentro del código existe un arreglo que contiene los nombres de todos los deportes que existen en el archivo.
        char deporte[6][30] = {"Natación", "Atletismo", "Ciclismo", "Gimnasia", "Equitacion", "Esgrima"};
*/

#include <stdio.h>
#include <string.h>


//la verdad no tuve claro lo que hice, no pierda mucho tiempo viendo esto una disculpa

typedef struct {

    char nombre[40];
    char pais[25];

}DatosPersonales;

typedef struct{
    DatosPersonales datos;
    char deporte[30];
    int numMedallas;

}Deportista;

int main()
{
    Deportista deportistas[100];
    // Puede cambiar la declaración de este arreglo a donde lo considere necesario
    char deporte[6][30] = {"Natación", "Atletismo", "Ciclismo", "Gimnasia", "Equitacion", "Esgrima"};

	archivoLee(deportistas);

    return 0;
}

void archivoLee(struct Deportista dep[100])
{
	FILE *archivo;
	int cerrado;
	int i=0, j, k;

	char read[50];
	archivo = fopen("deportistas.txt", "r");//read

	if(archivo==NULL)
	{
		printf("No se ha podido abrir");
	}
	
	
	while(!feof(archivo))
	{
		fgets(read, 50, archivo);
		i++;
	}
	
	rewind(archivo);
	
	dep = (Deportista*)malloc(i*sizeof(Deportista));
	if(dep==NULL)
	{
		printf("No se ha podido");
	}

	for(j=0; !feof(archivo); j++)
	{
		vaciar(read);
		aux = '0';
		for(k=0; aux!='-'; k++)//???
		{
			aux=fgetc(archivo);
			if(aux!='-')
			{
				read[k]=aux;
			}
		}
		copiar(read, i);
	}
	
	cerrado = fclose(archivo);
	
	if(cerrado == E0F)
		printf("El archivo no se cerro bien");
}

void archivoRecibe()//???
{
	FILE *archivo;
	int cerrado;
	int i;
	

	archivo = fopen("deportistas.txt", "w");//write

	
	
	
	
	do{
		fscanf(archivo, "%s", nombre);
		fscanf(archivo, "%d", &valor);
		
		printf("%s - %d", nombre, valor);
	}while(finalArchivo != E0F);
	

	
	
	cerrado = fclose(archivo);
	
	if(cerrado == E0F)
		primtf("El archivo no se cerro bien");
		
	return 0;
}
//me hice bolas
