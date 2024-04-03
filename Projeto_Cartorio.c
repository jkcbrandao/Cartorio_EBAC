#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

// Função responsável pelo cadastro de users
int registro()
{
	// Definindo Idioma
		setlocale(LC_ALL, "Portuguese"); 
	
	printf("\nVocê escolheu a opção 1 - registro de nomes\n\n");
	system("pause");
	
	// Limpeza do CMD
	system("cls");
	
	// Início da criação de variáveis / string -->
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// <-- fim da criação de variáveis / string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando info do usuário
	scanf("%s",cpf); // %s guarda o valor na string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	
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
	
	printf("\nVocê escolheu a opção 2 - Consultar nomes\n\n");
	system("pause");
	
	// Limpeza do CMD
	system("cls");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // r lê o arquivo
	
	if(file == NULL)
	{
		printf("\nNão foi possível localizar no cadastro! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	// Definindo Idioma
	setlocale(LC_ALL, "Portuguese"); 
	
	printf("\nVocê escolheu a opção 3 - Deletar nomes\n\n");
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
		printf("\nO CPF não está cadastrado no sistema \n\n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nO usuário a seguir será deletado: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
	
	remove(cpf);
	
}

int main (){
	
	// Definindo vaiável inteira 
	int opcao=0; 
	int laco=1;
	
	// Abertura de loop for ->
	for(laco=1;laco=1;)
	{
	
		// Limpeza do CMD
		system("cls");
	
		// Definindo Idioma
		setlocale(LC_ALL, "Portuguese"); 
	
	
		// Início do menu ->
		printf("\t### CARTÓRIO DA EBAC ### \n\n"); 
		printf(" Escolha a opção desejada do menu \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Opção: ");
		// <- Fim do menu
		
	
		// Armazenamento da escolha do usuário
		scanf("%d", &opcao); 
		
	
		// Limpeza do CMD 
		system("cls"); 
		
		// Abertura do switch case ->
		switch(opcao)
		{
			case 1:
			registro(); // Chamada de funções
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
			printf("Esta opção não está disponível\n");
			system("pause");
			break;	
		}
		// <- Fechamento do switch case
	
	
	}
	// <- Fechamento do loop for
	
	printf("\nEste software é de propriedade de jkc.brandao\n");
	}
