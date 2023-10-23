# Oriol Vilà i Laia Espluga
void InitData(){   # Tots iniciem el programa amb el mateix codi per comprobar que els resultats són correctes
int i,j;
srand(8824553);   # La funció srand genera números pseudo-aleatoris que seguiran la mateix seqüència durant tot el programa 
for( i = 0; i < N; i++ )
  for( j = 0; j < N; j++ ){
  Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));    # La funció rand genera números aleatoris
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
