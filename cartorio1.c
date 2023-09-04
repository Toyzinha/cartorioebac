#include <stdio.h> //biblioteca de cominica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o em espa�o de memoria
#include <locale.h> //biblioteca de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//Fun�a� responsavel por cadastrar os usuarios no sistema
{
	//inicio da cria��o de variaveis
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa�oes do usuario
	scanf("%s", cpf);//fun�ao responsavel por armazenar os dados fornecidos
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo "w" siginifica escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//fun��o responsavel por abrir o arquivo para consulta
	fprintf(file, ",");//fun��o responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	printf("Digite o nome a ser cadastrado:  ");//coletando informa��es do usuario
	scanf("%s",nome);//fun�ao responsavel por armazenar os dados fornecidos
	
	file = fopen(arquivo, "a");//fun��o responsavel por abrir o arquivo para consulta
	fprintf(file,nome);//fun��o responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	file = fopen(arquivo, "a");//fun��o responsavel por abrir o arquivo para consulta
	fprintf(file, ",");//fun��o responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:  ");//coletando informa��es do usuario
	scanf("%s",sobrenome);//fun�ao responsavel por armazenar os dados fornecidos
	
	file = fopen(arquivo, "a");//fun��o responsavel por abrir o arquivo para consulta
	fprintf(file,sobrenome);//fun��o responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	file = fopen(arquivo, "a");//fun��o responsavel por abrir o arquivo para consulta
	fprintf(file, ",");//fun��o responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado:  ");//coletando informa��es do usuario
	scanf("%s",cargo);//fun�ao responsavel por armazenar os dados fornecidos
	
	file = fopen(arquivo, "a");//fun��o responsavel por abrir o arquivo para consulta
	fprintf(file,cargo);//fun��o responsavel por exibir o arquivo para o usuario
	fclose(file);//responsavel por fechar o arquivo
	
	system("pause");//fun��o responsavel por pausar o sistema ate que o usuario precione alguma tecla
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[50];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:  ");//coletando informa��es do usuario
	scanf("%s",cpf);//fun�ao responsavel por armazenar os dados fornecidos
	
	FILE *file;//procura o arquivo na biblioteca
	file= fopen(cpf, "r");//fun��o responsavel por abrir o arquivo para consulta
	
	if(file == NULL)//executada caso o arquivo n�o seja encontrado
	{
		printf("Arquivo n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//executada caso o arquivo seja encontrado
	{
		printf("\nEssas s�o as informa��es dos usu�rios: ");
		printf("%s", conteudo);//fun��o responsavel por exibir o arquivo para o usuario
		printf("\n\n");
	}

	system("pause");//fun��o responsavel por pausar o sistema ate que o usuario precione alguma tecla
	fclose(file);//responsavel por fechar o arquivo
}

int deletar()
{
	char cpf[50];
	printf("Digite o CPF do usu�rio a ser deletado: ");//coletando informa��es do usuario
	scanf("%s",cpf);//fun�ao responsavel por armazenar os dados fornecidos

	
	FILE *file;//procura o arquivo na biblioteca
	file = fopen(cpf, "r");//fun��o responsavel por abrir o arquivo para consulta
	fclose(file);//responsavel por fechar o arquivo
	
	if(file == NULL)//executada caso o arquivo n�o seja encontrado
	{
		printf("Usu�rio n�o cadastrado no sistemas! \n");
		system("pause");
	}
	
	else //executada caso o arquivo seja encontrado
	{
		remove(cpf);
		printf("Usu�rio deletado com sucesso!");
		system("pause");//fun��o responsavel por pausar o sistema ate que o usuario precione alguma tecla
	}
}


int main()
{
	
	int opcao=0; //definindo variaveis
	int x=1; //vari�vel de la�o
	
	for(x=1;x=1;)
	{
	
	system("cls");//remove informa��es desnecessarias da tela
	  setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
	  printf("### cart�rio da EBAC ### \n\n");//inicio do menu
   	  printf("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - deletar nomes\n\n");
	  printf("Op��o: ");//fim do menu
	
	  scanf("%d" , &opcao);//armazenando a escolha do usu�rio
	
	  system("cls"); // responsavel por limpar a tela
	  
	  switch(opcao)//inicio da sele��o do menu
	  {
	  
	      case 1:
	   	  registro();//chamada de fun��es
	      break;
	      
	      case 2:
		 consulta();//chamada de fun��es
		  break;
	        
	      case 3:
		  deletar();//chamada de fun��es
		  break;
	    
	      default:
	  	  printf("Essa op�ao n�o est� disponivel!\n");
	  	  system("pause");//fun��o responsavel por pausar o sistema ate que o usuario precione alguma tecla
	  	  break;
	  	  
	  	   
	    }//fim da sele��o
	
	}
}
