#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
   // inicio criação da vriável/string 
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   // Final criação da vriável/string 
   
   printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário.
   scanf("%s", cpf); //%s refere-se a string 
   
   strcpy(arquivo, cpf); //responsável por copiar os valores das strings
   
   FILE *file; //cria o arquivo 
   file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
   fprintf(file,cpf);// salva o valor da variavel
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado: ");
   scanf("%s", nome);
   
   file = fopen(arquivo, "a");
   fprintf(file,nome); 
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado: ");
   scanf("%s", sobrenome);
   
   file = fopen(arquivo,"a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado: ");
   scanf("%s", cargo);
   
   file = fopen(arquivo,"a");
   fprintf(file,cargo);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   system("pause");
   
}

int consulta()
{
   setlocale(LC_ALL,"Portuguese");
   
   char cpf[40];
   char conteudo[200];
 
   printf("Digite o CPF a ser consultado: ");
   scanf("%s",cpf);

   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	printf("Não foi possível abrir o arquivo, não localizado! .\n");
   	}
   	
   	while(fgets(conteudo, 200, file)!= NULL);
   	{
   	printf("\nEssas são a informações do usuário: ");
   	printf("%s", conteudo);
   	printf("\n\n");
	   }
	
	fclose(file);   
	system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s",cpf); //coleta informação do usuário
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
   
    if(file == NULL) //verifica se o cpf existe no banco de dados. caso não exista exibe mensagem de erro.
    {
    	printf("O usuário não se encontra no sistema!.\n");
    	system("pause");
    	
	}
	fclose(file); 
}
int main()
    {
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;) 
	{
	

        system("cls"); // responsável por limpar a tela.
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	    printf("### cartório da ebac ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("opcao:");//Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
    	system("cls");
    	
    	switch(opcao) //inicio da seleção do menu
      	{   case 1:
        	registro(); // chamada de funções
			break;	
		    
		    case 2:
		    consulta();
	        break;
	        	
	        case 3:
	        deletar();
    	    break;
    	    	
    	    default:
    	    printf("Essa opção não está disponível ");
    	    system("pause");
    	    break;
	   	} //fim da seleção
        }
	
	}
