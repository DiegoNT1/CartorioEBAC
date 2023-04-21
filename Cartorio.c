#include <stdio.h> //Biblioteca de comunicacao com o usuario
#include <stdlib.h> //Biblioteca de alocacao de espaco
#include <locale.h> //Biblioteca de alocacao de texto por regiao
#include <string.h> //Biblioteca responsavel por cuiodar das strings

int registrar() //funcao responsavel por cadastrar os usuarios no sistema
{
	//inicio da criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informacao do usiario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo. "w" significa escrever 
	fprintf(file,"CPF:");
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo "a" significa que vai atualizar o arquivo
	fprintf(file,"\tNome:");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abre o arquivo "a" significa que vai atualizar o arquivo
	fprintf(file,nome); //salvo o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a"); //abre o arquivo "a" significa que vai atualizar o arquivo
	fprintf(file,"\tSobrenome:");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo "a" significa que vai atualizar o arquivo
	fprintf(file,sobrenome); //salvo o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a"); //abre o arquivo "a" significa que vai atualizar o arquivo
	fprintf(file,"\tCargo:"); //salvo o valor da variavel
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //abre o arquivo "a" significa que vai atualizar o arquivo
	fprintf(file,cargo); //salvo o valor da variavel
	fclose(file);
	
	system("pause");
}

int consultar() //funcao responsavel por consultar os usuarios no sistema
{
	setlocale(LC_ALL,"Portuguese");
	
	//inicio da criacao de variaveis/string
	char cpf[40];
	char conteudo[200];
	//final da criacao de variaveis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo "r" significa que vai ler o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //while = enquanto/  fgets = chama a variavel/  conteudo = variavel que esta sendo salvo o conteudo/  200 = MaxCount "tamanho maximo do conteudo"/  file = arquivo do qual sera retirado as informacoe/  "!=NULL" = quando ele deve parar de rodar o arquivo  
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	fclose(file);
	
	system("pause");
	
	
}

int deletar() //funcao responsavel por deletar os usuarios no sistema
{
	//inicio da criacao de variaveis/string
	char cpf[40];
	//final da criacao de variaveis/string
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario nao existe no sistema!\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; //definindo variaveis
	int x=1;
	
	for(x=1;x=1;) //Repeticao (voltar para o menu)
	{
		
	   system("cls"); //apagar informacoes na tela
       
	   setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
    
	   printf("### Cartório da EBAC ###\n\n\n"); //inicio do menu
	   printf("Escolha a opção desejada no menu:\n\n");
	   printf("\t1- Registrar nomes\n");
	   printf("\t2- Consultar nomes\n");
	   printf("\t3- Deletar nomes\n"); //final do menu
	   printf("\t4- Sair do sistema\n\n\n\n");
	   printf("opcao: ");
	
	
	   scanf("%d", &opcao); // armazenando a escolha do usuario
	
	   system("cls"); //apagar informacoes na tela
	   
	   switch(opcao) //inicio selecao menu
	   {
	   	  case 1:
	   	  registrar(); //chamada de funcoes
		  break;
		
		  case 2:
		  consultar(); //chamada de funcoes
		  break;
		
		  case 3:
		  deletar(); //chamada de funcoes
		  break;
		  
		  case 4:
		  printf("Obrigado por utilizar o sistema\n");
		  return 0;
		  break;
		
		  default:
		  printf("Essa opção não existe!\n");
		  system("pause");
		  break;
	  } //fim da selecao
	 } 	
}
	
