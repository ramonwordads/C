#include <stdio.h>
#include <stdlib.h>
#define N 10
void entrada(int a[]);
float somapar(int b, int a[]);
int maior(int vetor[N]);
/*
	APS 1 – Programação Estruturada
		Professor: Sérgio Assunção Monteiro
		Disciplina: Programação Estruturada
		Código da Turma: 953
		Nome e Matricula do Aluno: Ramon do Nascimento da Silva Olivera -- 2022100841
 */

int main(){
	int vetor01[N],vetor02[N],vetor03[N],vetor04[N],vetor05[N];		
	int maiorn,maiorn2,maiorn3,maiorn4,maiorn5;
	
	printf("Primeiro vetor:\n");
		entrada(vetor01);
		printf("\nSoma dos Pares: [%.2f].\n",somapar(N-1,vetor01));
		maiorn = maior(vetor01);
		printf("Maior Numero: %d\n\n",maiorn);
	
	printf("Segundo Vetor:\n");
		entrada(vetor02);
		printf("Soma dos Pares: %.2f \n", somapar(N-1,vetor02));
		maiorn2 = maior(vetor02);
		printf("Maior Numero: %d\n\n", maiorn2);
	
	printf("Terceiro Vetor:\n\n");
		entrada(vetor03);
		printf("Soma dos Pares: %.2f\n", somapar(N-1,vetor03));
		maiorn3 = maior(vetor03);
		printf("Maior Numero: %d\n\n",maiorn3);
		
	printf("Quarto Vetor:\n");
		entrada(vetor04);
		printf("Soma dos Pares: %.2f \n",somapar(N-1,vetor04));
		maiorn4 = maior(vetor04);
		printf("Maior Numero: %d\n\n", maiorn4);
		
	printf("Quinto Vetor: \n");
		entrada(vetor05);
		printf("Soma dos Pares: %.2f \n", somapar(N-1,vetor05));
		maiorn5 = maior(vetor05);
		printf("Maior Numero: %d\n",maiorn5);

	}



	void entrada(int a[]){
		int i;
		for(i=0;i<N;i++){
		a[i] = rand()%100 ;
		printf("vetor %d: %d\n",i, a[i]);
		}
	
	}
	
	float somapar(int b, int a[]){
		if(b==0){
		return b;
		}
	
		int r=0;
		if(a[b]%2==0){
		r=a[b];
		}
		return r+somapar(b-1,a);
	}

	int maior(int vetor[N]){
		int i;
		int maior = vetor[N];

		for(i=0;i<10;i++){
			if(vetor[i]>maior){

			maior = vetor[i];
			}
		}
			return maior;
	}


