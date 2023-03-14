#include <stdio.h> //bilbioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //bilblioteca que cuida das strings

//Função responsavel por registrar os nomes dos usuarios
int record() {
	
	//Criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser registrado: "); //Coletando as informações dos usuarios
	scanf("%s", cpf); //%s se refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria arquivo e "w" significa escrever
	fprintf(file, cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" altera o arquivo
	fprintf(file, ","); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo); 
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa a tela
	
}

//Função para consultar arquivos
int consult() {
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Início da definição de variaveis
	char cpf[40];
	char conteudo[200];
	//Fim da definição de variaveis
	
	printf("\n\tDigite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL) {
		
		printf("\n\tEsse arquivo não existe. \n\n");
		
		}
		
	while(fgets(conteudo, 200, file) != NULL) {
		
		printf("Essas são as informções que você solicitou:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	fclose(file);
	system("pause"); //Responsavel por pausar a tela
	
}

//Função para deletar arquivos
int delete() {
	
	char cpf[40];
	
	printf("Digite o cpf que você deseja deletar: ");
    scanf("%s", cpf);
	
    remove(cpf); //Deleta o arquivo cpf 
	
	system("cls"); //
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) {                                                
		
		printf("\n O usuario não existe no sistema.\n\n");
		
	}

	system("pause"); //Responsavel por pausar a tela 
	
}


int main() {
	
	//Início da definição de variaveis
	int opcao = 0; 
	int x = 1;
	//Fim da definição de variaveis
	
	for(x=1;x=1;) { 
	
	system("cls"); //Responsavw por limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf(" \n\t### Cartório da EBAC ###\n\n"); //Início do menu
	printf("Escolha a sua opção desejada: \n\n");    
	printf("\t1 - Resgitrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	
	printf("\n\n\t Opção:\t"); //Fim do menu
	
	scanf("%d", &opcao); //Armanzenando a escolha do usúario
	
	printf(" \n\n Esse Software é de uso livre para desenvolvedores iniciantes.\n\n");
	
	
	system("cls"); //Responsavel por limpar a tela
	
	//Início da seleção do menu
	switch(opcao) {
		
		case 1:
	       record(); //chamada de função
	       break; //Encerra a execução da instrução
	    
	    case 2:
	    	consult(); //Chamada de função
	    	break; //Encerra a execução da da instrução
	    	
	    case 3:
	    	delete(); //Chamada de função
	    	break; //Encerra a execução da função
	    	
	    	
	     default:
	     	printf("Essa opção não existe.\n\n"); 
	     	system("pause"); //Pausa a tela
	     	break; //Encerra a execução sa instrução 
	}
	//Fim da seleção do menu 
  }
}

