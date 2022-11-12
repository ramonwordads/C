	#include<stdio.h>
	#include <stdlib.h>


	struct ELista
	{
		int elem;
		struct ELista *prox;
	};
	
	struct EMonitor
	{
		struct ELista*prim;
		struct ELista*fim;
		int qtde;
	};
//--------------------------
	void create();
	void add(int elem);
	int option();
	void imprimir_dados();
	struct ELista *buscardado(int chave);
	struct ELista *pesquisarAnterior(int chave,	struct ELista **ant);
	int deletardado(int elem);
	struct EMonitor monitor;
	
//--------------------------

	main()
	{
		create();
		while(option());
	}
//--------------------------
	void create()
	{
		monitor.prim=NULL;
		monitor.fim=NULL;
		monitor.qtde=0;	
	}
//--------------------------

	int option()
	{
		int opcao;
		system("cls");
		
		printf("\n SELECIONE");
		printf("\n   0. EXIT ");
		printf("\n   1. CREATE ");
		printf("\n   2. PRINT OUT ");
		printf("\n   3. SEARCH ");
		printf("\n   4. DELETE ");
		printf("\n");
			scanf("%d",&opcao);
		
//--------------------------
		switch(opcao)
		{
			case 0:return 0;
			
			case 1:
			{ int elem;
			  printf("\n Informe o Valor a ser ADICIONADO: ");
			  	scanf("%d",&elem);
			  	add(elem);
			  	return 1;
			}
			
			case 2:
			{ int elem;
			  imprimir_dados();
			  printf("\n DADOS IMPRIMIDOS COM SUCESSO!");		  
				  system("pause");
				  return 1;
			}		
			
			case 3:
			{ int elem;
			  struct ELista *p;
			  
			  printf("\n Informe o Valor para Pesquisar:  ");
				  scanf("%d",&elem);		
				  p=buscardado(elem);
				  if(p){
				  	printf("ELEMENTO NA LISTA!\n");
				  	
				  }else{
				  	printf("ELEMENTO NAO ESTA NA LISTA!\n");
				  }
				  
				  printf("\n Press X for Continue");	
				  	  
					  system("pause");
					  return 1;
				}					
			
			
			case 4:
			{ int elem;
			  printf("\n INFORME O VALOR A SER DELETADO:: ");
				  scanf("%d",&elem);
				  int f = deletardado(elem);
				  if(f==1){
				  	printf(" DELETADO COM SUCESSO!");
				  }else{
				  	printf("NAO FOI POSSIVEL DELETAR!");
				  }
				  return 1;
				}
					default:
						printf("\n INFORME UM VALOR VALIDO! ");
						return 1;
		}	
	}
//--------------------------

	void add(int elem)
{
	struct ELista *p;
		p=(struct ELista *)malloc(sizeof(struct ELista));
		p->elem=elem;
		p->prox=NULL;
		monitor.qtde++;	
	
	if(monitor.prim==NULL)
	{
		monitor.prim=monitor.fim=p;
		return;
	}
	
	if(p->elem<=monitor.prim->elem)
	{
		p->prox=monitor.prim;
		monitor.prim=p;
		return;
	}
	
	if(p->elem>=monitor.fim->elem)
	{
		monitor.fim->prox=p;
		monitor.fim=p;
		return;
	}
	
	struct ELista *aux;
		aux=monitor.prim;
		while((aux->prox->elem)<(p->elem))
			aux=aux->prox;
	    p->prox=aux->prox;
	    aux->prox=p;
}
//--------------------------

	void imprimir_dados()
	{
		  struct ELista *p;
		  p=monitor.prim;
		  while(p)
		  {
		  	printf("\np->elem=[%d]",p->elem);
		  	p=p->prox;
		  }
	}
//--------------------------

struct ELista *buscardado(int chave){
struct ELista *p;
	p=monitor.prim;
	while(p){
  	if(p->elem==chave){
  		return p;
	}	
  	p=p->prox;
  	}
  return NULL;	
}

//--------------------------

	struct ELista *pesquisarAnterior(int chave,	struct ELista **ant){
	  struct ELista *p;
	  p=monitor.prim;
	  *ant=NULL;
	  while(p)
	  {
	  	if(p->elem==chave){
	  		return p;
		}
		*ant=p;	
	  	p=p->prox;
	  }
	  return NULL;	
}
//--------------------------

	int deletardado(int elem){
	  struct ELista *p;
	  struct ELista *ant;
	  p=pesquisarAnterior(elem,&ant);
	  if(p==NULL){  	
	  	return 0;
	  }
	  monitor.qtde--;
 
/*POSIÇÕES DOS ELEMENTOS*/

  if((p==monitor.prim)&&(p==monitor.fim)){  	
  	monitor.prim=monitor.fim=NULL;
  	free(p);
  	return 1;
  }

  if(p==monitor.prim){  	
  	monitor.prim=monitor.prim->prox;
  	free(p);
  	return 1;
  }


  if(p==monitor.fim){  	
  	monitor.fim=ant;
  	monitor.fim->prox=NULL;
  	free(p);
  	return 1;
  }


  ant->prox=p->prox;
  free(p);
  return 1;
}
