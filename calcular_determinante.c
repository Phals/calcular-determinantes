#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int calcular(int *p_matriz, int ordem){
	
	// Algoritmo para receber a matriz
	
	int matriz[ordem][ordem];
	
	int i, j;
	
	int aux = 0;
	
	for(i=0; i<ordem; i++)		
		for(j=0; j<ordem; j++)
			matriz[i][j] = *(p_matriz + (aux++));
	
	// Determinante de ordem 1
	
	if(ordem == 1) return matriz[0][0];
		
	int linha, soma = 0;
	
	for(linha=0; linha<ordem; linha++){
		
		int temp_matriz[ordem-1][ordem-1];
		
		int m=0, n=0;
		
		int elemento = matriz[linha][0];
		int indice = linha + 2;
		
		for(i=0; i<ordem; i++){
			
			if(linha == i) continue;
			
			for(j=1; j<ordem; j++){
				
				temp_matriz[m][n++] = matriz[i][j];
			
			}
			
			m++;
			n=0;
			
		}
		
		// Exibe a matriz
		
		//printf("\nMenor de %d\n", elemento);
		
		//exibir_matriz(&temp_matriz, ordem-1);
		
		soma += ( elemento * pow(-1, indice) * calcular(&temp_matriz, ordem-1) );
		
	}
	
	return soma;
	
}

int exibir_matriz(int *p_matriz, int ordem){
	
	// Algoritmo para receber a matriz
	
	int matriz[ordem][ordem];
	
	int i, j;
	
	int aux = 0;
	
	for(i=0; i<ordem; i++)		
		for(j=0; j<ordem; j++)
			matriz[i][j] = *(p_matriz + (aux++));
	
	// Interação para exibir a matriz
	
	printf("\n");
	
	for(i=0; i<ordem; i++){
	
		printf("|");
	
		for(j=0; j<ordem; j++){
			
			printf(" %d ", matriz[i][j]);
	
		}
		
		printf("|\n");
	
	}
	
}

int main(){
	
	// Dimensão (Ordem) da matriz
	
	int ordem;
	
	printf("Digite a ordem da matriz: ");
	scanf("%d", &ordem);
	
	// Inicializa a matriz de dimensao (Ordem) definida
	
	int matriz[ordem][ordem];
	
	// Variavel auxiliar i j
	
	int i, j;
	
	// preencher matriz
	
	int opc = 0;
	
	printf("\nPreencher matriz automaticamente: [s = 1/n = 0] ");
	scanf("%d", &opc);
	
	if(!opc){
	
		// Recebe os elementos da matriz
		
		printf("\nEntre com os elementos da matriz\n\n");
		
		for(i=0; i<ordem; i++){
		
			for(j=0; j<ordem; j++){
				
				printf("Digite o elemento A[%d ; %d]: ", (i+1), (j+1));
				scanf("%d", &matriz[i][j]);
		
			}
		
		}
	
	}else{
		
		// Preencher matriz
		
		srand(time(NULL));
		
		printf("\nPreenchendo a matriz automaticamente\n\n");
		
		for(i=0; i<ordem; i++){
		
			for(j=0; j<ordem; j++){
				
				int elemento = rand() % 10;
				
				printf("Digite o elemento A[%d ; %d]: %d\n", (i+1), (j+1), elemento);
				
				matriz[i][j] = elemento;
		
			}
		
		}
		
	}
	
	// Exibe a matriz
	
	exibir_matriz(&matriz, ordem);
	
	printf("\nDeterminante: %d\n", calcular(&matriz, ordem));
	
	return 0;
	
}
