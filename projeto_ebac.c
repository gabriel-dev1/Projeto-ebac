#include <stdio.h> //bilbioteca de comunica��o com o us�ario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //bilblioteca que cuida das strings

//Fun��o responsavel por registrar os nomes dos usuarios
int record() {
	
	//Cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser registrado: "); //Coletando as informa��es dos usuarios
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

//Fun��o para consultar arquivos
int consult() {
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//In�cio da defini��o de variaveis
	char cpf[40];
	char conteudo[200];
	//Fim da defini��o de variaveis
	
	printf("\n\tDigite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL) {
		
		printf("\n\tEsse arquivo n�o existe. \n\n");
		
		}
		
	while(fgets(conteudo, 200, file) != NULL) {
		
		printf("Essas s�o as inform��es que voc� solicitou:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	fclose(file);
	system("pause"); //Responsavel por pausar a tela
	
}

//Fun��o para deletar arquivos
int delete() {
	
	char cpf[40];
	
	printf("Digite o cpf que voc� deseja deletar: ");
    scanf("%s", cpf);
	
    remove(cpf); //Deleta o arquivo cpf 
	
	system("cls"); //
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) {                                                
		
		printf("\n O usuario n�o existe no sistema.\n\n");
		
	}

	system("pause"); //Responsavel por pausar a tela 
	
}


int main() {
	
	//In�cio da defini��o de variaveis
	int opcao = 0; 
	int x = 1;
	//Fim da defini��o de variaveis
	
	for(x=1;x=1;) { 
	
	system("cls"); //Responsavw por limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf(" \n\t### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	printf("Escolha a sua op��o desejada: \n\n");    
	printf("\t1 - Resgitrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	
	printf("\n\n\t Op��o:\t"); //Fim do menu
	
	scanf("%d", &opcao); //Armanzenando a escolha do us�ario
	
	printf(" \n\n Esse Software � de uso livre para desenvolvedores iniciantes.\n\n");
	
	
	system("cls"); //Responsavel por limpar a tela
	
	//In�cio da sele��o do menu
	switch(opcao) {
		
		case 1:
	       record(); //chamada de fun��o
	       break; //Encerra a execu��o da instru��o
	    
	    case 2:
	    	consult(); //Chamada de fun��o
	    	break; //Encerra a execu��o da da instru��o
	    	
	    case 3:
	    	delete(); //Chamada de fun��o
	    	break; //Encerra a execu��o da fun��o
	    	
	    	
	     default:
	     	printf("Essa op��o n�o existe.\n\n"); 
	     	system("pause"); //Pausa a tela
	     	break; //Encerra a execu��o sa instru��o 
	}
	//Fim da sele��o do menu 
  }
}

