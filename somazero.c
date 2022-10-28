#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// pega um vetor e o inico,meio e fim dele
//faz uma copia do vetor
//compara as posicoes e aloca no vetor auxiliar de forma ordenada
//trasfere para o vetor principal
 void intercala1 (int inicio, int meio, int fim, int v[]) 
{
   int *w;                                
   w = malloc ((fim-inicio) * sizeof (int)); 
  
   int i = inicio, j = meio;                       
   int k = 0;                              

  
   while (i < meio && j < fim) {  
      if (v[i] <= v[j])  w[k++] = v[i++]; 
      else  w[k++] = v[j++];            
   }   
  
   while (i < meio)  w[k++] = v[i++];         
   while (j < fim)  w[k++] = v[j++];     
   for (i = inicio; i < fim; ++i)  v[i] = w[i-inicio]; 
   free (w);                               

}

// recebe um vetor e o incio e o fim dele
//verifica se o incio é maior que o final
//cria a variavel meio para varrer o vetor em duas metades
//e se chama recursivamente e acada interacao chama o intercala
 void mergesort (int inicio, int fim, int v[])
{
   if (inicio < fim-1) {                 
      int meio = (inicio + fim)/2;          
      mergesort (inicio, meio, v);      
      mergesort (meio, fim, v);        
      intercala1 (inicio, meio, fim, v);     
   }
}



int main (void) {
  int verificar=0;
  
  //lendo o arquivo de entrada
  
   FILE *entrada;
   entrada = fopen ("somazero.in", "r");

  //verificando se o arquivo existe!
     if (entrada == NULL) {
        printf ("\narquivo não encontrado!\n");
         getchar();
        exit (0);
       }

  //criando oarquivo de saida
  FILE *saida;
  saida=fopen("somazero.out","w");
  //verificando se o ponteiro não esta vazio
    if (saida == NULL) {
        printf ("\narquivo não encontrado!\n");
        getchar();
        exit (0);
     }


  // lendo a primeira linha do arquivo para alocar no tamanho do vetor
   int n=0;
   int k = fscanf (entrada, "%i", &n);
   int comparar[n];

  //preenchendo o vetor com os valores da entrada do arquivo
  int cont=0;
  while (true) {
      int x;
     //lendo todas as linhas do arquivo;
      int k = fscanf (entrada, "%i", &x);
      if (k != 1){ 
        break;
        }
    comparar[cont]=x;
    cont++;
    }
 
  // chamada da funcao para ordenar o vetor
  mergesort(0, n,comparar);
  
 
// variaveis auxiliares para a busca binaria
  int x=0;int inicio = 0, fim = n;
  

  //realizando uma busca binaria para cada elento do vetor
  for(int j=0;j<10;j++){ 
    x=comparar[j];
     while (inicio <= fim && verificar==0) {  
        int m = (inicio + fim)/2;
       
       // se o valor do meio for o oposto de x a soma deles da 0
       // e verificar e incrementado
        if (comparar[m] == -x) verificar++; 

       
       //se o valor do meio for maior que o oposto de x 
       //o fim se torna a metade do vetor
        if(comparar[m]>-x) fim=m-1;

          
          // se o meio for menor que o oposto de x
          //o inicio se torna o meio do vetor
        else inicio=m+1;
     }
  } 
    
  //dando a saida esperada do arquivo 
  if(verificar==0) fprintf(saida,"NÃO");
  else fprintf(saida,"SIM");

  // fechando os arquivos
   fclose (entrada);
   fclose(saida);
   
  
   return EXIT_SUCCESS;
}
  
