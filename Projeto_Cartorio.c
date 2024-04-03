#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

// Fun��o respons�vel pelo cadastro de users
int registro()
{
	// Definindo Idioma
		setlocale(LC_ALL, "Portuguese"); 
	
	printf("\nVoc� escolheu a op��o 1 - registro de nomes\n\n");
	system("pause");
	
	// Limpeza do CMD
	system("cls");
	
	// In�cio da cria��o de vari�veis / string -->
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// <-- fim da cria��o de vari�veis / string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando info do usu�rio
	scanf("%s",cpf); // %s guarda o valor na string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // a atualiza o arquivo
	fprintf(file, ", "); // insere o texto
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);	
	
	// Limpeza do CMD
	system("cls");
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	// Definindo Idioma
	setlocale(LC_ALL, "Portuguese"); 
	
	printf("\nVoc� escolheu a op��o 2 - Consultar nomes\n\n");
	system("pause");
	
	// Limpeza do CMD
	system("cls");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // r l� o arquivo
	
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel localizar no cadastro! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	// Definindo Idioma
	setlocale(LC_ALL, "Portuguese"); 
	
	printf("\nVoc� escolheu a op��o 3 - Deletar nomes\n\n");
	system("pause");
	
	// Limpeza do CMD
	system("cls");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nO CPF n�o est� cadastrado no sistema \n\n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nO usu�rio a seguir ser� deletado: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
	
	remove(cpf);
	
}

int main (){
	
	// Definindo vai�vel inteira 
	int opcao=0; 
	int laco=1;
	
	// Abertura de loop for ->
	for(laco=1;laco=1;)
	{
	
		// Limpeza do CMD
		system("cls");
	
		// Definindo Idioma
		setlocale(LC_ALL, "Portuguese"); 
	
	
		// In�cio do menu ->
		printf("\t### CART�RIO DA EBAC ### \n\n"); 
		printf(" Escolha a op��o desejada do menu \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Op��o: ");
		// <- Fim do menu
		
	
		// Armazenamento da escolha do usu�rio
		scanf("%d", &opcao); 
		
	
		// Limpeza do CMD 
		system("cls"); 
		
		// Abertura do switch case ->
		switch(opcao)
		{
			case 1:
			registro(); // Chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel\n");
			system("pause");
			break;	
		}
		// <- Fechamento do switch case
	
	
	}
	// <- Fechamento do loop for
	
	printf("\nEste software � de propriedade de jkc.brandao\n");
	}
