#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
   // inicio cria��o da vri�vel/string 
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   // Final cria��o da vri�vel/string 
   
   printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio.
   scanf("%s", cpf); //%s refere-se a string 
   
   strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
   
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
   	printf("N�o foi poss�vel abrir o arquivo, n�o localizado! .\n");
   	}
   	
   	while(fgets(conteudo, 200, file)!= NULL);
   	{
   	printf("\nEssas s�o a informa��es do usu�rio: ");
   	printf("%s", conteudo);
   	printf("\n\n");
	   }
	
	fclose(file);   
	system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s",cpf); //coleta informa��o do usu�rio
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
   
    if(file == NULL) //verifica se o cpf existe no banco de dados. caso n�o exista exibe mensagem de erro.
    {
    	printf("O usu�rio n�o se encontra no sistema!.\n");
    	system("pause");
    	
	}
	fclose(file); 
}
int main()
    {
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) 
	{
	

        system("cls"); // respons�vel por limpar a tela.
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	    printf("### cart�rio da ebac ###\n\n"); //Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
	    printf("opcao:");//Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    	system("cls");
    	
    	switch(opcao) //inicio da sele��o do menu
      	{   case 1:
        	registro(); // chamada de fun��es
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
    	    printf("Essa op��o n�o est� dispon�vel ");
    	    system("pause");
    	    break;
	   	} //fim da sele��o
        }
	
	}
