// Oriol Vilà i Laia Espluga

#include <stdio.h>
#define N 100

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
