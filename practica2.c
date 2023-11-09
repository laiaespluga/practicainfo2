// Oriol Vilà i Laia Espluga
#include <stdlib.h> //Biblioteques incloses per poder fer la pràctica
#include <stdio.h>
#include <math.h>

#define N 512 

float V1[N], V2[N], V3[N], V4[N]; // Variables definides
float Mat[N][N], MatDD[N][N];

//Programa comú
void InitData(){   // Tots iniciem el programa amb el mateix codi per comprobar que els resultats són correctes
int i,j;
srand(4422543);   // La funció srand genera números pseudo-aleatoris que seguiran la mateixa seqüència durant tot el programa 
for( i = 0; i < N; i++ )
  for( j = 0; j < N; j++ ){
  Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));    // La funció rand genera números aleatoris
    if ( (abs(i - j) <= 3) && (i != j))
      MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
    else if ( i == j )
      MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
    else MatDD[i][j] = 0.0;
 }

for( i = 0; i < N; i++ ){
  V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
  V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
  V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
} // final del programa comú
} 

// EXERCICI 1: Imprimim un cert nombre d'elements d'un vector
void PrintVect(float vect[N], int from, int numel) { //Treballem amb 3 arguments: el vector i dos números enters que indiquen el primer i l'últim element que volem imprimir

  if (from < 0 || from >= N || numel < 0) { // Comprovar que els paràmetres son vàlids abans de procedir a imprimir-los
       printf("Paràmetres no vàlids\n"); //Si la condició no es compleix imprimeix l'error
        return;
    } 

    for (int i = from; i < numel; i++) { //Utilitza un bulce for per imprimir tots els elements de vector a partir de la posició indicada
        printf("%f ", vect[i]);
    }
    printf("\n");
}


// EXERCICI 2: Imprimim un cert nombre d'elements d'una fila d'una matriu
void PrintRow(float mat[N][N], int row, int from, int numel) { //Treballem amb 4 arguments: la matriu, la fila a imprimir i dos números enters que indiquen el primer i últim element que volem imprimir

  if (row < 0 || row >= N || from < 0 || from >= N || numel < 0 ) { // Comprobar que los parámetros son válidos
        printf("Paràmetres no vàlids\n"); //Si la condició no es compleix imprimeix l'error
        return;
    }
    for (int i = from; i < numel; i++) {
        printf("%f ", mat[row][i]);
    } //Utilitza un bulce for per imprimir tots els elements de la matriu a partir de la posició indicada
    printf("\n"); 
}


// EXERCICI 3: Multiplicació d'un escalar per un vector
void MultEscalar(float vect[N], float vectres [N], float alfa) { //Treballem amb 3 arguments: el vector, el vector resultant i el valor alfa (l'escalar)

  for (int i = 0; i < N; i++) { //Utilitza el bucle for per abarcar tots els elements del vector
    vectres[i] = alfa * vect[i]; //Multiplica el vector (vect) per l'escalar (alfa) i guarda el resultat en el vector resultant (vectres)
  }
}

// EXERCICI 4: Calcula el producte escalar entre dos vectors
float Scalar(float vect1[N], float vect2[N]) { //Definim la funció Scalar a partir dels paràmatres vect1 i vect2
    float result = 0.0; //Declarem la variable result a 0.0 que ens servirà pel resultat del producte escalar
  for (int i = 0; i < N; i++) { //Utilitza el bucle for per abarcar tots els elements del vector
    result += vect1[i] * vect2[i]; //Calculem el producte escalar
  }
  return result; //La funció retorna el resultat
}

// EXERCICI 5: Calcula la magnitud d'un vector (arrel quadrada de la suma del quadrat dels seus components)
float Magnitude(float vect1[N]) { //Declarem la funció Magnitude a partir del paràmetre vect1
  float magnitude = 0.0; //Declarem la variable magnitude a 0.0 que ens servirà pel resultat de la magnitud 
  for (int i = 0; i < N; i++) { //Utilitza el bucle for per abarcar tots els elements del vector
    magnitude += pow(vect1[i], 2); //Calculem la suma dels quadrats dels components del vector i els guardem en la variable magnitude
  }
  magnitude = sqrt(magnitude); //Fem l'arrel quadrada de la variable magnitud 
  return magnitude; //La funció retorna el resultat
}

// EXERCICI 6: Determina si dos vectors són ortogonals (l'angle entre ells és recte, és a dir, el seu producte escalar és 0)
int Ortogonal(float vect1[N], float vect2[N]) { //Declarem la funció Ortogonal a partir de dos vectors (vect1 i vect2) 
  if (Scalar(vect1, vect2) == 0.0) { //Fem una crida a la funció Scalar amb vect1 i vect2 com arguments. Calcula el producte escalar
    return 1; //Si el resutlat és 0, els vectors són ortogonals i es retorna 1 (veritat)
  }
  else {
    return 0; //Si el resultat no és 0, els vectors no són ortogonals i es retorna 0 (fals)
  }
}

// EXERCICI 7: Calcula el vector projecció d'un vector sobre l'altre 
void Projection(float vect1[N], float vect2[N], float vectres[N]) { //Definim la funció Projection a partir de tres vectors (vect1, vect2 i vectres (vector resultant))
  float scalar = Scalar(vect1, vect2) / Magnitude(vect2); //Obtenim el resultat fent una crida a la funció Scalar(calcula el producte escalar entre vect1 i vect2). Ho dividim fent una crida a la funció Magnitude (Calcula la magnitud de vect2) == Dividir el producte escalar entre la magnitud de vect2
  MultEscalar(vect2, vectres, scalar); //Cridem la funció MultEscalar per multiplicar el vect2 per l'escalar i emmagatxemar-ho en el vector resultant (vectres), aquesta operació forma part de la formula per calcular la projecció d'un vector sobre l'altre. 
}

// EXERCICI 8: Calcular la infini-norma (el màxim de les sumes dels valors absoluts dels elements de cada fila) d'una matriu 
float infininorm(float Mat[N][N]) { //Declarem al funció a partir de la matriu
    float norm = 0; // Creem la variable norm inicialitzada a zero, que emmagatzemarà la norma infinita
    for (int i = 0; i < N; i++) { //El bucle for recorre les files de la matriu
        float sum = 0; //Fem servir una variable sum per acumular els valors absoluts de cada fila. Aquesta es reinicia a 0 per cada fila 
        for (int j = 0; j < N; j++) { //Un bucle intern for itera a través de les columnes de cada fila. 
            sum += fabs(Mat[i][j]); //S'afegeix el valor absolut de cada element a la variable sum
        }
        if (sum > norm) { //Es compara la suma actual amb la norma actual. Si la suma és més gran que la norma, s’actualitza la norma amb aquest valor.

            norm = sum; 
        }
    }
    return norm; //Retorna la norma infinita calculada
}
  
//EXERICI 9: Calcular la norma-ú (el màxim de les sumes dels valors absoluts dels elements de cada columna) d'una matriu
float Onenorm(float Mat[N][N]) { //Declarem al funció a partir de la matriu
    float norm = 0; // Creem la variable norm = 0, aquesta emmagatzemarà el valor final de la norma-1 de la matriu
    for (int j = 0; j < N; j++) { //Iterem sobre totes les columnes de la matriu mitjançant el bucle for
        float sum = 0; //Fem servir una variable sum per acumular els valors absoluts de cada columna. Aquesta es reinicia a 0 per cada columna
        for (int i = 0; i < N; i++) { //Per a cada columna, iterem sobre les files de la matriu mitjançant el bucle for
            sum += fabs(Mat[i][j]); //Afegim el valor absolut de cada element de la columna actual a la variable sum
        }
        if (sum > norm) { //Es compara la suma actual amb la norma actual. Si la suma és més gran que la norma, s’actualitza la norma amb aquest valor.
            norm = sum;
        }
    }
    return norm; //Retorna el valor de “norm”, la norma-1 de la matriu
}

//EXERCICI 10: Calcular la norma de Frobenius (l’arrel quadrada de la suma dels quadrats del coeficients de la matriu)
float NormFrobenius(float Mat[N][N]) { //Declarem al funció a partir de la matriu
    float norm = 0.0; //Creem la variable “norm” inicialitzada a 0 per emmagatzemar la suma dels quadrats dels coeficients.
    for (int i = 0; i < N; i++) { //Mitjançant dos bucles for, la funció recorre tots els elements de la matriu (files i columnes)
        for (int j = 0; j < N; j++) {
            norm += pow(Mat[i][j], 2); //Per cada element de la matriu, s'afegeix el quadrat del seu valor a la variable “norm”
        }
    }
    norm = sqrt(norm); //Es calcula l'arrel quadrada de la suma mitjançant la funció “sqrt”
    return norm; //Retorna el valor final de “norm”
}

//EXERCICI 11: Determinar si una matriu és o no Diagonal Dominant (Una matriu és diagonal dominant si el valor absolut de l’element de la diagonal és més gran o igual que la suma dels valors absoluts dels altres elements de la fila, per a totes les files de la matriu)
int DiagonalDom(float Mat[N][N]) { //Declarem al funció a partir de la matriu. 
    for (int i = 0; i < N; i++) {
        float diagonal = fabs(Mat[i][i]);
        float sum = 0;
        for (int j = 0; j < N; j++) {
            if (j != i) {
                sum += fabs(Mat[i][j]);
            }
        }
        if (diagonal < sum) {
            return 0;
        }
    }
    return 1;
}

//EXERCICI 12: Resoldre sistemes d'equacions lineals a partir del mètode Jacobi 
int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned int iter ){
    if (!DiagonalDom(M)) {
    printf("La matriu M no és diagonal dominant, no es pot aplicar Jacobi\n");
    return 0;
            }
    float temp[N];
    unsigned int k;
    for (k=0; k< iter;k++){
      for (int i = 0; i < N; i++) {
        temp[i]=vect[i];

        for (int j=0; j<N; j++){
              if (j!=i){
            temp[i]-=M[i][j]*vectres[j];
              }
    
        }
        temp[i] /=M[i][i];
      }
      for (int i=0; i<N; i++){
        vectres[i]=temp[i];
      }
    }
    return 1;
}

    


int main() {
  InitData(); //Inicialitzar la matriu amb el que treballarem
  //Exercici A
  printf("V1 del 0 al 9 i del 256 al 265:\n");
  PrintVect(V1, 0, 10);
  PrintVect(V1, 256, 266);
  printf("\n");
  printf("V2 del 0 al 9 i del 256 al 265:\n");
  PrintVect(V2, 0, 10);
  PrintVect(V2, 256, 266);
  printf("\n");
  printf("V3 del 0 al 9 i del 256 al 265:\n");
  PrintVect(V3, 0, 10);
  PrintVect(V3, 256, 266);
  printf("\n");
  
  //Exercici B
  printf("Mat fila 0 i fila 100 del 0 al 9:\n");
  PrintRow(Mat,0,0,10);
  PrintRow(Mat,100,0,10);
  printf("\n");

  //Exercici C
  printf("MatDD fila 0 del 0 al 9 i fila 100 del 95 al 104:\n");
  PrintRow(MatDD,0,0,10);
  PrintRow(MatDD,100,95,105);
  printf("\n");

  //Exercici D
  printf("Infininorma de Mat = %f\n", infininorm(Mat));
  printf("Norma ú de Mat = %f\n", Onenorm(Mat));
  printf("Norma de Frobenius de Mat = %f\n", NormFrobenius(Mat));
  if (DiagonalDom(MatDD) == 1) {
    printf("La matriu Mat no és diagonal dominant\n");
  } else {
    printf("La matriu Mat és diagonal dominant\n");
  }
  printf("\n");
  printf("Infininorma de MatDD = %f\n", infininorm(MatDD));
  printf("Norma ú de MatDD = %f\n", Onenorm(MatDD));
  printf("Norma de Frobenius de MatDD = %f\n", NormFrobenius(MatDD));
  if (DiagonalDom(MatDD) == 1) {
    printf("La matriu MatDD és diagonal dominant\n");
  } else {
    printf("La matriu MatDD no és diagonal dominant\n");
    }
  printf("\n");
  
  //Exercici E
  float r1 = Scalar(V1,V2);
  float r2 = Scalar(V1,V3);
  float r3 = Scalar(V2,V3);
  printf("Escalar <V1,V2> = %f", r1);
  printf(" Escalar <V1,V3> = %f", r2);
  printf(" Escalar <V2,V3> = %f", r3);
  
  printf("\n");
  printf("\n");
    
  //Exercici F
  float res1 = Magnitude(V1);
  float res2 = Magnitude(V2);
  float res3 = Magnitude(V3);
  printf("Magnitud V1,V2 i V3 = %f %f %f\n", res1, res2, res3);
  printf("\n");

  // Exercici G
  if (Ortogonal(V1, V2)) {
    printf("V1 i V2 són ortogonals\n");
    }
  if (Ortogonal(V1,V3)) {
    printf("V1 i V3 són ortogonals\n");
  }
  if (Ortogonal(V2,V3)) {
    printf("V2 i V3 són ortogonals\n");
  }
  printf("\n");
  //Exercici H
  printf("Els elements 0 al 9 i 256 al 265 del resultat de multiplicar V3x2.0 són: \n");
  float vect[N];
  MultEscalar(V3, vect, 2.0);
  PrintVect(vect, 0, 10);
  PrintVect(vect, 256, 266);
  printf("\n");

  //Exercici I
  printf("Els elements 0 a 9 del resultat de la projecció de V2 sobre V3 són:\n");
  float sol1[N];
  Projection(V2, V3, sol1);
  PrintVect(sol1, 0, 10);
  printf("Els elements 0 a 9 del resultat de la projecció de V1 sobre V2 són:\n");
  float sol2[N];
  Projection(V1, V2, sol2);
  PrintVect(sol2, 0, 10);
  printf("\n");
    
  //Exercici J
  float Mat[N][N], Vect[N], Result[N];
  float solJac1[N];
  float solJac2[N];
  Jacobi(MatDD, V3, solJac1, 1);
  Jacobi(MatDD, V3, solJac2, 1000);
  printf("Els elements 0 a 9 de la solució (1 iter) del sistema d'equacions són:\n");
  PrintVect(solJac1, 0, 10);
  printf("Els elements 0 a 9 de la solució (1000 iters) del sistema d'equacions són:\n");
  PrintVect(solJac2, 0, 10);
  if (DiagonalDom(Mat) == 0) {
      printf("La matriu M no és diagonal dominant, no es pot aplicar Jacobi\n");
  } else {
      printf("La matriu M és diagonal dominant\n");
  }

}
