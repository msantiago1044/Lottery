#define TAM 7
//definicion de estructuras

struct fnum { int numero; int serie;}; //estructura del vector premios
struct registro { struct fnum billete; char lugar[30];}registro;
struct cadenacar{ char cad[16];};


/*definicion de funciones */

void inicializa_generador_aleatorios(){
        /* Inicializa generador de n&#65533;meros aleatorios
        E: (ninguna) S: (ninguna)*/
        srand( time(NULL) );
        }

int azar_numero( int tope ){
        /* Funcion. Devuelve un entero al azar, menor que tope */
        /* E: tope, maximo valor devuelto Valor devuelto: num aleatorio
/ 1 <= valor devuelto <=tope */
        return 1+(int)((float)tope*rand()/(RAND_MAX+1.0));
        }

int azar_serie( int tope ){
        /* Funcion. Devuelve un entero al azar, menor que tope */
        /* E: tope, maximo valor devuelto Valor devuelto: num aleatorio / 1 <= valor devuelto <=tope */
        return 1+(int)((float)tope*rand()/(RAND_MAX+1.0));
        }


void buscar(struct fnum elegido[TAM], char *fichero1, char *fichero2, char *fichero3) { //para buscar los numeros en fichnumeros
        struct cadenacar categoria[TAM];
        char lugar[30];
        int i, x;
        int seguir;
        int numero[TAM], serie[TAM];
        struct registro registro;
        FILE *result; /* result apunta a "result.dat"*/
        FILE *fich;   // fich apunta a "fichnumerosCompletos.dat"
        FILE *premiotxt;  // premiostxt apunta a "premios.txt"

     /* Apertura en modo lectura-escritura. */
     fich = fopen("fichnumerosCompleto.dat", "r");
     result = fopen("result.dat", "wr");
     premiotxt = fopen("premios.txt", "w");

        if (result != NULL && fich !=NULL && premiotxt !=NULL);{ /*Comprobación*/

        seguir = 1;
        while (seguir == 1){
            do {
                fread(&registro, sizeof(struct registro), 1, fich);
                for(i =0; i<TAM; i++){
                if ((elegido[i].numero == registro.billete.numero) && (elegido[i].serie == registro.billete.serie)) {
                  //almacena lugar
                        fprintf(result, "%d\t %d\t %s\n",registro.billete.numero, registro.billete.serie,registro.lugar);
                        numero[i] = registro.billete.numero;
                        serie[i]  = registro.billete.serie;
                        lugar[i] = *registro.lugar;
                        seguir = 0;
                        }
                  }
                }while (!feof(fich));
        fclose(fich);
        fclose(result);
        }
                        for (i = 0; i < TAM; i++){
                                            if (i==0)
                                                strcpy(categoria[0].cad, "Primer premio:");
                                            if (i==0)
                                                strcpy(categoria[0].cad, "Primer premio:");
                                            if(i== 1)
                                                strcpy(categoria[1].cad, "Segundo premio:");
                                            if (i==2)
                                                strcpy(categoria[2].cad, "Tercer premio:");
                                            if ((i <= TAM/2)&&(i>2)){
                                                 strcpy(categoria[3+i].cad, "Cuarto premio:");
                                                 x=i;}
                                                else
                                                 strcpy(categoria[1+x].cad, "Reintegro:");
        }
        //los escribimos en premios.txt
        if ((numero[i] > 0 && numero[i] < 10000) && (serie[i] > 0 && serie[i] < 11))
             fprintf(premiotxt,"%s\t%d\t%d\t%s\n",categoria[i].cad, numero[i], serie[i], lugar[i]);
    }
    fclose(premiotxt);//Cerramo el fichero txt
}


void leerficherotxt(char *fichtxt){
        FILE *premiotxt;
        char lugar[91];
        //Abrir fichero para lectura de los numeros
     if ((premiotxt = fopen(fichtxt, "r")) == NULL){
        //Si no puede abrise o no existe.
        printf("El fichero '%s' no se puede leer", fichtxt);
        }
     else printf("\n    NUMEROS DE PREMIADOS:\n");
        fscanf (premiotxt, lugar , 91, fichtxt);
        //Muestra datos por pantalla
        while ( !feof(premiotxt)){                      //Mientras no ha llegado a la marca de fin de fichero lee linea a linea
          printf("%s", lugar);                  //Escribe una de las lineas en la pantalla.
          fscanf(premiotxt, lugar, 91, fichtxt);        //Lee siguiente linea hasta fin de linea o un maximo de 90 caracteres.
        }
     fclose (premiotxt);
        }
        }

void ponersinvender(char *fichtxt){
        FILE *premiosinvend;
        char lugar[91];

        if ((premiosinvend = fopen(fichtxt, "r")) == NULL){
          //Si no puede abrise o no existe.
           printf("El fichero '%s' no se puede leer", fichtxt);}
        else {printf("\nPremios que no se han vendido:\n");
                fscanf(premiosinvend, lugar , 91, fichtxt);
             //Muestra datos por pantalla
              while ( !feof(premiosinvend)){                      //Mientras no ha llegado a la marca de fin de fichero lee linea a l$
                if (strstr (lugar, "Sin vender")){     //Si la cadena de b&#65533;squeda esta incluida en dato
                  printf("%s", lugar);}
                 fscanf(premiosinvend, lugar , 91, fichtxt);       //Lee la siguiente l&#65533;nea del fichero.
                }
        fclose(premiosinvend);
   }}


main(){
   int intervnum, intervserie; /* longitud del intervalo */
   int i;
   struct fnum premios[TAM]; //matriz premios
   struct registro resultado[TAM];
   char f1[] = {"/home/alumnos/GI33_16/fichnumerosCompleto.dat"};
   char f2[] = {"/home/alumnos/GI33_16/resul.dat"};
   char f3[] = {"/home/alumnos/GI33_16/premios.txt.dat"};
  FILE *result;
  FILE *fich;
  FILE *premiotxt;

inicializa_generador_aleatorios();
inicializa_generador_aleatorios();
   printf ("Produce un numero aleatorio de loteria: \n");

      /* Genera N aleatorios entre min y max */
   intervnum = 9999 + 1;
   intervserie = 9 + 1;
  for (i=0; i< TAM; i++){
     premios[i].numero = azar_numero(intervnum)%9999 +1;
     premios[i].serie = azar_serie(intervserie);
        printf ("\n Premio %d\t", i+1);
        printf ("%d\t %d\n", premios[i].numero, premios[i].serie);}


    //procedimiento para crear los ficheros y operar con ellos
    buscar(premios, f1, f2, f3);
result = fopen("result.dat", "r");
    fread (&resultado[i], sizeof(struct registro), 1, result);
        printf("\n%d \t%d \t%s", resultado[i].billete.numero, resultado[i].billete.serie, resultado[i].lugar);
        fclose (result);

         leerficherotxt(f3);

         ponersinvender(f3);
         void leerymostrarficherotxt(char *fichtxt){
                FILE *premiotxt;
                char lugar[91];
                //Abrir fichero para lectura de los numeros
             if ((premiotxt = fopen(fichtxt, "r")) == NULL){
                //Si no puede abrise o no existe.
                printf("El fichero '%s' no se puede leer", fichtxt);
                }
             else printf("\n    NUMEROS DE PREMIADOS:\n");
                 fscanf (premiotxt,"%s", lugar);
                //Muestra datos por pantalla
                while ( !feof(premiotxt)){                      //Mientras no ha llegado a la marca de fin de fichero lee linea a linea
                  printf("%s\t", lugar);                  //Escribe una de las lineas en la pantalla.
                  fscanf(premiotxt, "%s", lugar);      //Lee siguiente linea hasta fin de linea o un maximo de 90 caracteres.
                              }
             fclose (premiotxt);
                }



        void ponersinvender(char *fichtxt){
                FILE *premiosinvend;
                char lugar[91];

                if ((premiosinvend = fopen(fichtxt, "r")) == NULL){
                  //Si no puede abrise o no existe.
                   printf("El fichero '%s' no se puede leer", fichtxt);}
                else {printf("\nPremios que no se han vendido:\n");
                        fscanf(premiosinvend, "%s", lugar);

                  //Muestra datos por pantalla
                      while ( !feof(premiosinvend)){                      //Mientras no ha llegado a la marca de fin de fichero lee linea a l$
                        if (strstr (lugar, "Sin vender")){     //Si la cadena de busqueda esta incluida en dato
                          printf("%s", lugar);}
                         fscanf(premiosinvend, "%s", lugar);       //Lee la siguiente linea del fichero.
                        }
                fclose(premiosinvend);
           }}
} //main
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>