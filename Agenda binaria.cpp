#include <stdio.h>
#include <string.h>
typedef struct {
char nombre[100];
char apellido[100];
int grado;
int registro;
char correo[100];
}jugador;

jugador ingresarDatosJugador(void);
void imprimirJugadores(jugador *);
int buscar_esto(jugador* jugadores, int size);
void buscar_nombre(jugador* jugadores,  int size, char nombre1[100]);
int comparar_cadenas(char nombre[100], char nombre1[100]);
void imprimir_jugador(jugador j);
void buscar_apellido(jugador* jugadores,  int size, char apellido2[100]);
void comparar_grado(jugador* jugadores,  int size, int grado3);
int comparar_dominios(char correo[100], char dominio6[100]);
void buscar_dominio(jugador* jugadores, int size, char dominio6[100]);
void buscar_correo(jugador* jugadores,  int size, char correo5[100]);
void comparar_registro(jugador* jugadores,  int size, int registro4);

int main(void) {
	int size=2;
FILE *myFile;
  jugador jugadores[size];
myFile = fopen("C:\\Users\\danym\\OneDrive\\Documentos\\Agenda.txt", "wb");

  for(int i=0;i<2;i++)
    {
      jugadores[i] = ingresarDatosJugador();
    }
    
for(int i = 0; i < 2; i++){
	fwrite(&jugadores[i],1,sizeof(jugador),myFile);
}
int tamanio;
for(int i = 0; i < tamanio; i++){
fread(&jugadores,i,sizeof(jugador),myFile);
fseek(myFile,1,SEEK_END);// lo manda al fin de archivo
tamanio = tamanio/sizeof(jugador);
rewind(myFile);
}
  
  fclose(myFile);
  buscar_esto(jugadores, size);
  return 0;
}
void imprimirJugadores(jugador *x){
printf("Estos son los jugadores: \n");
  for(int i=0;i<2;i++)
    {
	printf("%s\n\n",x[i].nombre);
	printf("%s\n", x[i].apellido);
	printf("grado: %i\n",x[i].grado);
	printf("registro: %i\n",x[i].registro);
	printf("correo: %s\n",x[i].correo);
    }
}
void imprimir_jugador(jugador j){
	printf("\n\n%s ",j.nombre);
	printf("%s\n", j.apellido);
	printf("grado: %i\n",j.grado);
	printf("registro: %i\n",j.registro);
	printf("correo: %s\n",j.correo);
}
jugador ingresarDatosJugador(void){
  jugador x;
  printf("\n\nnombre: ");
  scanf(" %s",x.nombre);
  printf("\napellido: ");
  scanf(" %s", x.apellido);
  printf("\ngrado ");
  scanf(" %i",&x.grado);
  printf("\nregistro: ");
  scanf(" %i",&x.registro);
  printf("\ncorreo: ");
  scanf(" %s",x.correo);
  return x;
}
int buscar_esto(jugador* jugadores, int size){
	int numero;
	char nombre1[100];
	char apellido2[100];
	int grado3;
	int registro4;
	char correo5[100];
	char dominio6[100];
	printf("\n\nComo quiere buscar al alumno?\n\nNombre - Digite 1\nApellido - Digite 2\nGrado - Digite 3\nNumero de Registro - Digite 4\nCorreo electronico - Digite 5\nDominio del correo electronico- Digite 6\n\n");
	scanf("%i", &numero);
	switch(numero){
		case 1: printf("Dime el nombre del alumno que quieres buscar ");
				scanf("%s", nombre1);
				printf("Buscar a %s\n\n", nombre1);
				buscar_nombre(jugadores, size, nombre1);
				break;
		case 2: printf("Dime el apellido del alumno que quieres buscar ");
				scanf("%s", apellido2);
				printf("Buscar a %s\n\n", apellido2);
				buscar_apellido(jugadores,  size, apellido2);
				break;
		case 3: printf("Dime el grado del alumno que quieres buscar ");
				scanf("%i", &grado3);
				printf("Buscar al alumnos del grado %i", grado3);
				comparar_grado(jugadores, size, grado3);
				break;
		case 4: printf("Dime el numero de registro del alumno que quieres buscar ");
				scanf("%i", &registro4);
				printf("Buscar al alumnos del grado %i", registro4);
				comparar_registro(jugadores,  size, registro4);
				break;
		case 5:	printf("Dime el correo del alumno que quieres buscar ");
				scanf("%s", correo5);
				printf("Buscar el correo %s", correo5);
				buscar_correo(jugadores, size, correo5);
				break;
		case 6: printf("Dime el dominio del correo electronico del alumno que quieres buscar ");
				scanf("%s", dominio6);
				printf("Buscar correos de alumnos con el dominio %s \n", dominio6);
				buscar_dominio(jugadores, size, dominio6);
				break;
				
		default: printf("No ha digitado un numero valido ");
	}
}
void buscar_nombre(jugador* jugadores,  int size, char nombre1[100]){
	int a=0;
	while(a<size){
		if(comparar_cadenas(jugadores[a].nombre, nombre1)==1){
		imprimir_jugador(jugadores[a]);
		}
	a++;
	}
}
int comparar_cadenas(char nombre[100], char nombre1[100]){
	int b=0;
		while(nombre[b]!=0||nombre1[b]!=0){
			if(nombre[b]!=nombre1[b]){
			return 0;
		}
		b++;
	}
	return 1;
}
void buscar_apellido(jugador* jugadores,  int size, char apellido2[100]){
	int a=0;
	while(a<size){
		if(comparar_cadenas(jugadores[a].apellido, apellido2)==1){
		imprimir_jugador(jugadores[a]);
		}
	a++;
	}
}
void comparar_grado(jugador* jugadores,  int size, int grado3){
	int a=0;
	while(a<size){
		if(jugadores[a].grado==grado3){
		imprimir_jugador(jugadores[a]);
		}
	a++;
	}
}
void comparar_registro(jugador* jugadores,  int size, int registro4){
	int a=0;
	while(a<size){
		if(jugadores[a].registro==registro4){
		imprimir_jugador(jugadores[a]);
		}
	a++;
	}
}
void buscar_correo(jugador* jugadores,  int size, char correo5[100]){
	int a=0;
	while(a<size){
		if(comparar_cadenas(jugadores[a].correo, correo5)==1){
		imprimir_jugador(jugadores[a]);
		}
	a++;
	}
}
void buscar_dominio(jugador* jugadores, int size, char dominio6[100]){
	int a=0;
	while(a<size){
		if(comparar_dominios(jugadores[a].correo, dominio6)==1){
		imprimir_jugador(jugadores[a]);
		}
	a++;
	}
}
int comparar_dominios(char correo[100], char dominio6[100]){
	int b=0;
	int c=0;
		while(correo[b]!='@'){
			if(correo[b]==0){
				printf("no encuentro el dominio");
				return 0;
			}
			b++;
		}
		b++;
		while(correo[b]!=0&&dominio6[c]!=0){
			if(correo[b]!=dominio6[c]){
			return 0;
			}
			b++;
			c++;
		}
	return 1;
}