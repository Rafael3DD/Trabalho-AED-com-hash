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
		
	//declara��o das fun��es usadas
	void remove();
	void mostra();
	void inseri(); 	
	void mostra2();
	Hash *criaHash(int tamanho);
		
	//defini o tamanho da tabela.
	Hash *ha = criaHash(977);
	
	//struct pessoa.
	pessoa pes;
	
	//vari�veis usadas para gerar o n�mero r�ndomico.
	int aleatorio,i,resul;
	
	//vari�vel usada para verificar se as inscri��es s�o iguais.
	int verifica;
		
	//Calcula a posi��o.
	int chaveDivisao(int chave, int tamanho);
		
	//guarda as pessoas cadastradas.	
	pessoa tabela[TAM];
	
	//incrementa as posi��es da tabela
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
		printf("Escolha uma op��o:");
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
			printf("Op��o inv�lida!\n\n");
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
	
	//fun��o insere pessoas.
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
					
					//A pessoa informa quantos dias ficar� no evento.
					printf("Digite quantos dias voc� ficar� no evento:");
					scanf("%d",&pes.dia);		
					if(pes.dia < 1 || pes.dia > 30 ){
						printf("Quantidade de dias inv�lida!\n");
					}	
				}while(pes.dia < 1 || pes.dia > 30 );
				
				
				do{	
				//se o dia for maior que 2 o programa cria um n�mero de inscri��o e informa para a pessoa.
					if(pes.dia < 2){
						printf("Voc� n�o pode ficar na �rea das barracas!\n");
						break;
					}
					else{
						srand(time(NULL));
						for(i=0;i < 1 ;i++){
						resul = rand () % TAM;
						}
						pes.inscricao = resul;
						printf("A sua incri��o �: %d\n",resul);
					}
						
						pes.num = chaveDivisao(pes.inscricao,ha->tamanho);
						printf("A barraca que voc� deve ir � :%d\n",pes.num);
						printf("Pode entrar.\n\n\n");
			
				}while(pes.dia < 2);
				
				tabela[indice] = pes;
				indice++;
				aux++;
	}
		
	//fun��o imprime as pessoas cadastradas na hora que execulta a op��o 3.	
	void mostra(){	
		for(i=0; i < indice;i++){
			printf("Nome........: %s\n",tabela[i].nome);
			printf("A barraca.. : %d \n",tabela[i].num);
		}
	}
	
	//fun��o que imprime as pessoas que foram cadastradas e quantas pessoas foram cadastradas;
	void mostra2(){
		printf("N�mero de pessoas cadastradas:%d\n",aux);
		if(aux== 0){
			printf("\nN�o tem ningu�m no sistema!\n");
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
	
	//fun��o remove as pessoas que foram cadastradas.
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
	
	//fun��o hash, m�todo divis�o.
	int chaveDivisao(int chave, int tamanho) {
	    return (chave & 0x7FFFFFFF) % tamanho;
	}
	
	
	
	
	

