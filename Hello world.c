#include<stdio.h>// biblioteca de comunicacao com usuario
#include<stdlib.h>// biblioteca de alocacao de espaco em memoria
#include<locale.h>// biblioteca de alocacao de texto por regiao
#include<string.h>//biblioteca por cuidar ads string


int registro()
{
	char arquivo[40];
    char cpf[40];
	char nome[40];	
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);// responsavel por copiar os valores das strings
	
	FILE *file; // criar arquivo no banco de dados
	file = fopen(arquivo,"w");//cria o arquivo
	fprintf(file,cpf);// salva o valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");


}
int consulta()
{
	setlocale(LC_ALL, "Portuguese");//definicao de idioma
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite cpf a ser consultado");
    scanf("%s"", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file== NULL)
    {
    	printf("nao foi possivel abrir o arquivo, nao llocalizado!.\n");	
	}
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\n essas sao informacoes do usuario");
		printf("%s",conteudo);
		printf("\n\n");
	}
system("pause");	
	
}
int deletar()
{
	printf("voce escolheu deletar de nomes\n");
	system("pause");
}
int main()
{
	int opcao=0;// definicao de variaveis
	int laco=1;
	
	for(laco==1;laco=1;)
{
    system("cls");
    
	setlocale(LC_ALL, "Portuguese");//definicao de idioma


    printf("### Cartorio da Ebac ###\n\n");// inicio do menu
    printf("Escolher opcao desejada do menu:\n\n");
    printf("\t1-Registrar Nomes\n");
    printf("\t2-Consultar nomes\n");
    printf("\t3-Deletar nomes\n");
    printf("Opcao:");// fim do menu

    scanf("%d", &opcao);//armazenando a escolha do usuario

    system("cls");
    
    switch(opcao)
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
	printf("essa opcao nao esta disponivel/n");
	system("pause");
	break;	  	
	}// fim da selecao
}
}

