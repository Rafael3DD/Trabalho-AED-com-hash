#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <time.h>
#define TAM 9999
	//struct que possue os dados das pessoas que foram cadastradas.
	struct pessoa{
	    int inscricao;
	    char nome[TAM];
	    int dia;
	    int num;
	};
	
	//struct hash.
	struct hash{
	    int qtde;
	    int tamanho = TAM;
	    struct pessoa **itens;
	};
	typedef struct hash Hash;
		
	//declaração das funções usadas
	void remove();
	void mostra();
	void inseri(); 	
	void mostra2();
	Hash *criaHash(int tamanho);
		
	//defini o tamanho da tabela.
	Hash *ha = criaHash(977);
	
	//struct pessoa.
	pessoa pes;
	
	//variáveis usadas para gerar o número rândomico.
	int aleatorio,i,resul;
	
	//variável usada para verificar se as inscrições são iguais.
	int verifica;
		
	//Calcula a posição.
	int chaveDivisao(int chave, int tamanho);
		
	//guarda as pessoas cadastradas.	
	pessoa tabela[TAM];
	
	//incrementa as posições da tabela
	int indice,aux=0;
	
	int main(){
		setlocale(LC_ALL,"portuguese");
		int op;
		
	do{
		fflush(stdin);
		printf("\n\t\t****Menu****\n\n");
		printf("1 - Entrada\n");
		printf("2 - mostra os dados \n");
		printf("3 - remover \n");
		printf("4 - sair.\n");
		printf("Escolha uma opção:");
		scanf("%d",&op);
	
		switch(op){
			case 1:
				// limita o cadastro de pessoas para 9999.
				if(indice < TAM){
					inseri();
				}
				else{
				 	printf("Limite de pessoas cadastradas atingidas!\n");
				}
				break;
					
			case 2:
				mostra2();
				break;
			
			case 3:
				remove();
				break;
				
			case 4:
				
				break;
				
			default:
			printf("Opção inválida!\n\n");
				break;
		}
	}while(op !=4);
		
		system("pause");
		return 0;
	
	}
	
	//define o tamanho.
	Hash *criaHash(int tamanho){
	    Hash *ha = (Hash*)malloc(sizeof(Hash));
	    if(ha != NULL) {
	        int i;
	        ha->tamanho = tamanho;
	        ha->itens = (struct pessoa**)malloc(tamanho*sizeof(struct pessoa*));
			if(ha->itens == NULL) {
	            free(ha);
	            return NULL;
	        }
	        ha->qtde = 0;
	        for(i = 0; i < ha->tamanho; i++)
	            ha->itens[i] = NULL;
	    }
	    return ha;
	}
	
	//função insere pessoas.
	void inseri(){
		bool teste = true;
			system("cls");
			do{
				//cadastra o nome.
				printf("Digite seu nome:");
				scanf("%s",&pes.nome);
				fflush(stdin);	
				  	for(i=0;i<strlen(pes.nome);i++){
		   			if(! (pes.nome[i] >= char(65) && pes.nome[i] <= char(90)) &&
					   ! (pes.nome[i] >= char(97) && pes.nome[i] <= char(122)) &&
					   ! (pes.nome[i] == char(32))
					  ){
						 printf("O nome deve ser somente letras\n");
						 teste = true;
						 break;
					   } 
					    else teste = false;	
	      	  	}
			}while(teste);
				do{
					fflush(stdin);
					
					//A pessoa informa quantos dias ficará no evento.
					printf("Digite quantos dias você ficará no evento:");
					scanf("%d",&pes.dia);		
					if(pes.dia < 1 || pes.dia > 30 ){
						printf("Quantidade de dias inválida!\n");
					}	
				}while(pes.dia < 1 || pes.dia > 30 );
				
				
				do{	
				//se o dia for maior que 2 o programa cria um número de inscrição e informa para a pessoa.
					if(pes.dia < 2){
						printf("Você não pode ficar na área das barracas!\n");
						break;
					}
					else{
						srand(time(NULL));
						for(i=0;i < 1 ;i++){
						resul = rand () % TAM;
						}
						pes.inscricao = resul;
						printf("A sua incrição é: %d\n",resul);
					}
						
						pes.num = chaveDivisao(pes.inscricao,ha->tamanho);
						printf("A barraca que você deve ir é :%d\n",pes.num);
						printf("Pode entrar.\n\n\n");
			
				}while(pes.dia < 2);
				
				tabela[indice] = pes;
				indice++;
				aux++;
	}
		
	//função imprime as pessoas cadastradas na hora que execulta a opção 3.	
	void mostra(){	
		for(i=0; i < indice;i++){
			printf("Nome........: %s\n",tabela[i].nome);
			printf("A barraca.. : %d \n",tabela[i].num);
		}
	}
	
	//função que imprime as pessoas que foram cadastradas e quantas pessoas foram cadastradas;
	void mostra2(){
		printf("Número de pessoas cadastradas:%d\n",aux);
		if(aux== 0){
			printf("\nNão tem ninguém no sistema!\n");
		}
		else
		
		for(i=0; i < indice;i++){
			if(tabela[i].inscricao == 0){
				continue;
			}
			printf("Nome..... : %s\n",tabela[i].nome);	
			printf("A barraca : %d \n",tabela[i].num);
		}
		
	}
	
	//função remove as pessoas que foram cadastradas.
	void remove(){
		system("cls");
			mostra();
			printf("Digite a sua incricao para ser removido:");
			scanf("%d",&verifica);
			for(i=0; i < indice ;i++){
				char nomecopia[TAM] = {'0'};
				if(verifica == tabela[i].inscricao){
					tabela[i].inscricao = NULL;
					tabela[i].num = NULL;
					aux--;
					strcpy(tabela[i].nome, nomecopia);
					printf("Removido com sucesso!\n");
					break;
				}	 
			}
	}
	
	//função hash, método divisão.
	int chaveDivisao(int chave, int tamanho) {
	    return (chave & 0x7FFFFFFF) % tamanho;
	}
	
	
	
	
	

