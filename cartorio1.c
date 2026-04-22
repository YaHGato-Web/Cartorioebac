#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória 
#include <locale.h> // biblioteca de alocações de de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings


int registro()
{
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // copia o CPF para o nome do arquivo (responsavel pela copia dos valores da string)

    FILE *file; // cria o arquivo (ou sobrescreve se já existir)
    file = fopen(arquivo, "w"); // cria o arquivo
    fprintf(file,cpf); // salva o valor da variante
    fclose(file); // fecha o arquivo


    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    

}

int consulta()
{
	setlocale(LC_ALL,"portuguese"); // definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
		
	printf("digite o CPF a ser consultado:");
	scanf("%s",cpf);
			
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\n Essas são as informações do usuário: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
    system("pause");
					
	}


int deletar()
{
	printf ("você escolheu deletar nomes! \n");
	system("pause");
}

int main()

{
	
	int opcao=0; // definindo as variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	       system ("cls");
	       
	       setlocale(LC_ALL,	"portuguese"); // definindo a linguagem
    
           // inicio 
        	printf("### Cartorio da EBAC ### \n\n"); // 0 printf(" ") é o responsável por permitir colocar conteudos no programa na linguagem C
	
            printf("escolha a opção desejada do menu:\n\n"); // o \n é o caractere responsável por pular linhas no printf(" ")
    
            printf("\t1 - registrar nomes\n"); // o \t é o caractere responsável pelo espaçamento
     
            printf("\t2 - consultar nomes\n");
     
            printf("\t3 - deletar nomes\n\n");
    
            printf ("Opção:"); 
            // fim do menu
    
            scanf("%d", &opcao ); 
    
            system ("cls");
            
            
                switch(opcao) // inicio da seleção
            {
                case 1:
                registro();
			    break;
			    
			    case 2:
			    consulta();
			    break;
		        
		        case 3:
		        deletar();
		        break;
		        
		        default: 
		        printf("essa opção não existe! \n");
                system("pause");
                break;
                // fim da seleção
			}
		
    }
}
