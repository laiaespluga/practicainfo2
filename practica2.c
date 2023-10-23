// Oriol Vilà i Laia Espluga
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 512

float V1[N], V2[N], V3[N], V4[N];
float Mat[N][N], MatDD[N][N];


void InitData(){   // Tots iniciem el programa amb el mateix codi per comprobar que els resultats són correctes
int i,j;
srand(8824553);   // La funció srand genera números pseudo-aleatoris que seguiran la mateix seqüència durant tot el programa 
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
}
}

void PrintVect(float vect[N], int from, int numel) {
    // Comprovar que els paràmetres son vàlids
    if (from < 0 || from >= N || numel < 0 || from + numel > N) {
        printf("Paràmetres no vàlids\n");
        return;
    }

    // Imprimir los elementos del vector
    printf("Elements del vector a partir de la pocisió %d:\n", from);
    for (int i = from; i < from + numel; i++) {
        printf("%f ", vect[i]);
    }
    printf("\n");
}

int main() {
    InitData();
  
    float vector[N];  // Definir el vector
    int numel, from;

    // Omplir el vector
    for (int i = 0; i < N; i++) {
        vector[i] = (float)i;
    }

    // Demanar a l'usuari la posició inicial i el nombre d'elements a mostrar
    printf("Introdueix la posició inicial (from): ");
    scanf("%d", &from);
    printf("Introdueix el nombre d'elements a mostrar (numel): ");
    scanf("%d", &numel);

    // Crida la funció per impirimir els elements del vector
    PrintVect(vector, from, numel);

    return 0;
}



void PrintRow(float mat[N][N], int row, int from, int numel) {
    // Comprobar que los parámetros son válidos
    if (row < 0 || row >= N || from < 0 || from >= N || numel < 0 || from + numel > N) {
        printf("Parámetros no válidos\n");
        return;
    }

    // Imprimir los elementos de la fila de la matriz
    printf("Elementos de la fila %d a partir de la posición %d:\n", row, from);
    for (int i = from; i < from + numel; i++) {
        printf("%f ", mat[row][i]);
    }
    printf("\n");
}

int main() {
    InitData();

    float Mat[N][N];  // Definir la matriz
    int row, numel, from;

    // Inicializar la matriz con datos, por ejemplo, llena con valores consecutivos para demostración
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Mat[i][j] = (float)(i * N + j);
        }
    }

    // Solicitar al usuario la fila, la posición inicial y el número de elementos a imprimir
    printf("Introduce el número de fila: ");
    scanf("%d", &row);
    printf("Introduce la posición inicial (from): ");
    scanf("%d", &from);
    printf("Introduce el número de elementos a imprimir (numel): ");
    scanf("%d", &numel);

    // Llamar a la función para imprimir los elementos de la fila de la matriz
    PrintRow(Mat, row, from, numel);

    return 0;
}

