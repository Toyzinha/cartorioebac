#include <stdio.h> //biblioteca de cominicação com o usuario
#include <stdlib.h> //biblioteca de alocação em espaço de memoria
#include <locale.h> //biblioteca de texto por regiao
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()//Funçaõ responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação de variaveis
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informaçoes do usuario
	scanf("%s", cpf);//funçao responsavel por armazenar os dados fornecidos
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo "w" siginifica escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//função responsavel por abrir o arquivo para consulta
	fprintf(file, ",");//função responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	printf("Digite o nome a ser cadastrado:  ");//coletando informações do usuario
	scanf("%s",nome);//funçao responsavel por armazenar os dados fornecidos
	
	file = fopen(arquivo, "a");//função responsavel por abrir o arquivo para consulta
	fprintf(file,nome);//função responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	file = fopen(arquivo, "a");//função responsavel por abrir o arquivo para consulta
	fprintf(file, ",");//função responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:  ");//coletando informações do usuario
	scanf("%s",sobrenome);//funçao responsavel por armazenar os dados fornecidos
	
	file = fopen(arquivo, "a");//função responsavel por abrir o arquivo para consulta
	fprintf(file,sobrenome);//função responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	file = fopen(arquivo, "a");//função responsavel por abrir o arquivo para consulta
	fprintf(file, ",");//função responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado:  ");//coletando informações do usuario
	scanf("%s",cargo);//funçao responsavel por armazenar os dados fornecidos
	
	file = fopen(arquivo, "a");//função responsavel por abrir o arquivo para consulta
	fprintf(file,cargo);//função responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	system("pause");//função responsavel por pausar o sistema ate que o usuario precione alguma tecla
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[50];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:  ");//coletando informações do usuario
	scanf("%s",cpf);//funçao responsavel por armazenar os dados fornecidos
	
	FILE *file;//procura o arquivo na biblioteca
	file= fopen(cpf, "r");//função responsavel por abrir o arquivo para consulta
	
	if(file == NULL)//executada caso o arquivo não seja encontrado
	{
		printf("Arquivo não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//executada caso o arquivo seja encontrado
	{
		printf("\nEssas são as informações dos usuários: ");
		printf("%s", conteudo);//função responsavel por exibir o arquivo para o usuario
		printf("\n\n");
	}

	system("pause");//função responsavel por pausar o sistema ate que o usuario precione alguma tecla
	fclose(file);//responsavel por fechar o arquivo
}

int deletar()
{
	char cpf[50];
	printf("Digite o CPF do usuário a ser deletado: ");//coletando informações do usuario
	scanf("%s",cpf);//funçao responsavel por armazenar os dados fornecidos

	
	FILE *file;//procura o arquivo na biblioteca
	file = fopen(cpf, "r");//função responsavel por abrir o arquivo para consulta
	fclose(file);//responsavel por fechar o arquivo
	
	if(file == NULL)//executada caso o arquivo não seja encontrado
	{
		printf("Usuário não cadastrado no sistemas! \n");
		system("pause");
	}
	
	else //executada caso o arquivo seja encontrado
	{
		remove(cpf);
		printf("Usuário deletado com sucesso!");
		system("pause");//função responsavel por pausar o sistema ate que o usuario precione alguma tecla
	}
}


int main()
{
	
	int opcao=0; //definindo variaveis
	int x=1; //variável de laço
	
	for(x=1;x=1;)
	{
	
	system("cls");//remove informações desnecessarias da tela
	  setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
	  printf("### cartório da EBAC ### \n\n");//inicio do menu
   	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - deletar nomes\n\n");
	  printf("Opção: ");//fim do menu
	
	  scanf("%d" , &opcao);//armazenando a escolha do usuário
	
	  system("cls"); // responsavel por limpar a tela
	  
	  switch(opcao)//inicio da seleção do menu
	  {
	  
	      case 1:
	   	  registro();//chamada de funções
	      break;
	      
	      case 2:
		 consulta();//chamada de funções
		  break;
	        
	      case 3:
		  deletar();//chamada de funções
		  break;
	    
	      default:
	  	  printf("Essa opçao não está disponivel!\n");
	  	  system("pause");//função responsavel por pausar o sistema ate que o usuario precione alguma tecla
	  	  break;
	  	  
	  	   
	    }//fim da seleção
	
	}
}
