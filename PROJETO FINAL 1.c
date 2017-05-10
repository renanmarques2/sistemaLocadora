#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>


//Renan Marques - Estudante Sistemas de Informação 5ª período
//Faculdade Dom Pedro II
//O SISTEMA É BRUTO


struct cliente {
    int id;
	char tel[9];
	char nome[50];
	char cpf[12];
	
}Cliente;
struct filme {	
	int id;
	char nome[20];
	char genero[20];
	char anolan[20];
}Filme;
struct rdg {
	char telcliente[9];
	int idfilme;
	char nomeCliente[50];
}rdg;
//Prototipos
void alterarCliente (struct cliente lista_cliente[100]);
void alterarFilme (struct filme lista_filme[100]);
void regradeneg(struct rdg listardg[100],struct filme lista_filme[100],struct cliente lista_cliente[100]);
void relatorio(struct rdg listardg[100],struct filme lista_filme[100]);
void login();

int qtd_cli,qtd_filme;

void login(){
	setlocale(LC_ALL,"");
	system ("color 1f");
	int i,logi=1,senha=1;
	char login1[100], password[100];
  
  
		for (i=0;i<=3;i++) {
			if (i<3) {
			printf("\t ---- SISTEMA DE LOCADORA ----\n\nFAÇA SEU LOGIN COMO ADMINISTRADOR PARA CONTINUAR.\n\n");
		printf("LOGIN: ");
		fflush (stdin);
		gets(login1);
	
			printf ("SENHA: ");
			fflush(stdin);
			gets(password);

					logi=strcmp(login1,"admin");
					senha=strcmp(password,"admin");
					if (logi==0 && senha==0)
			{
				system("cls");
				break;
			}
					 else {
					 	system ("cls");
						printf("*** USUÁRIO E/OU SENHA INCORRETOS, TENTE NOVAMENTE ***\n\n");
						
					}
			
		
	} else {
		system("cls");
		printf("\n\n\n\t\tSISTEMA BLOQUEADO");
		exit(0);
	}
		} 
		} 

menu_principal() {
	int opcao_principal;
	system("cls");
	printf("\t ---- BEM VINDO AO SISTEMA DE LOCADORA ----\n\n");
	printf("* Qual tarefa deseja executar?");
	printf("\n1- Cadastrar ");	
	printf("\n2- Consultar ");
	printf("\n3- Alterar ");
	printf("\n4- Sobre o sistema ");
	printf("\n5- Sair\n");
	scanf("%d", &opcao_principal);
	return opcao_principal;
}


cadastroFilme(struct filme lista_filme[100]) { //cadastro de filmes da locadora
	int i;
	char opcao;
	for (i=qtd_filme;i<=100;i++){
		system("cls");
	printf("\t ---- CADASTRO DE FILME ----\n\n");
	printf("Insira o nome do filme: ");
		fflush(stdin);
		gets(lista_filme[i].nome);
		printf("Insira o genêro do filme: ");
		fflush(stdin);
		gets(lista_filme[i].genero);
		printf("Insira o ano de lançamento: ");
		fflush(stdin);
		gets(lista_filme[i].anolan);
		lista_filme[i].id = i+1;
		qtd_filme++;
		system ("cls");
		printf("\t ---- CADASTRO DE FILMES ----\n\n");
		printf("ID: %i\nFilme: %s \nGenero: %s \nAno de lançamento: %s \n \nO filme foi cadastrado com sucesso em nosso sistema. \n\n",lista_filme[i].id,lista_filme[i].nome,lista_filme[i].genero,lista_filme[i].anolan);
		printf("\n\nDeseja cadastrar outro filme? s / n: ");
		fflush(stdin);
		scanf("%c",&opcao);
		if (opcao == 'n') 
			break;
	}
}

cadastroCliente(struct cliente lista_cliente[100]) { //cadastro de cliente da locadora  
	int i;
	char opcao;
	for (i=qtd_cli;;i++){
		system("cls");
	printf("\t ---- CADASTRO DE CLIENTE ----\n\n");
	printf("Insira o nome completo do cliente: ");
	fflush(stdin);
	gets(lista_cliente[i].nome);
		printf("Insira seu CPF: ");
		fflush(stdin);
		gets(lista_cliente[i].cpf);
			printf("Insira telefone para contato: ");
			fflush(stdin);
			gets(lista_cliente[i].tel);
		lista_cliente[i].id = i+1;
		qtd_cli++;
		system ("cls");
		printf("\t ---- CADASTRO DE CLIENTE ----\n\n");
		printf("ID: %i\nNome: %s \nCPF: %s \nTelefone: %s\nO cliente foi cadastrado com sucesso em nosso sistema. \n\n",lista_cliente[i].id,lista_cliente[i].nome,lista_cliente[i].cpf,lista_cliente[i].tel);
		printf("\n\nDeseja cadastrar outro cliente? s / n: ");
		fflush(stdin);
		scanf("%c",&opcao);
		if (opcao == 'n') 
			break;
}
}

consultarCliente(struct cliente lista_cliente[100]) { //consulta de todos os clientes ja cadastrados da locadora 
int i;
system("cls");
for (i=0;i<qtd_cli;i++){
printf ("\nId:	%i",lista_cliente[i].id);
printf ("%\nNome: %s",lista_cliente[i].nome);
printf ("%\nCPF: %s",lista_cliente[i].cpf);
printf ("%\nTel: %s\n\n\n",lista_cliente[i].tel);
} 
if (qtd_filme<1) {
	printf("Não ha clientes cadastrados no sistema.\n\n");
}
printf("\nPressione ENTER para retornar ao menu Consulta\n");
getch();			
system("cls");
}

consultarFilme(struct filme lista_filme[100], struct cliente lista_cliente[100]) { //consulta de todos os filmes ja cadastrados para a locadora 
int i;
char filmelocado[20];
char filme[20];
char cpf[12];
system("cls");
for (i=0;i<qtd_filme;i++){
printf ("\nID:	%i",lista_filme[i].id);	
printf ("\nNome:	%s",lista_filme[i].nome);
printf ("%\nGênero: %s",lista_filme[i].genero);
printf ("%\nAno de lançamento: %s\n\n",lista_filme[i].anolan);
}
if (qtd_filme<1) {
	printf("Não ha filmes cadastrados no sistema.\n\n");
}
printf("Pressione ENTER para retornar ao menu Consulta\n");
getch();			
system("cls");
}

consultaClientePesquisa (struct cliente lista_cliente[100],int id_pesquisa) { //consulta de clientes por id
	int i;
	for(i=0; i<qtd_cli; i++){
		if(lista_cliente[i].id==id_pesquisa){
			printf("Nome: %s \n", lista_cliente[i].nome);	
			printf("Telefone: %s \n", lista_cliente[i].tel);
			printf("CPF: %s \n", lista_cliente[i].cpf);
			printf("\n\n\n--Para fazer nova consulta pressione ENTER para retornar ao menu--\n\n\n");
			getch();		
		}
}
	 if(id_pesquisa>qtd_cli ){// condição caso nao tenha nenhum id cadastrado
       printf("\n **** Cliente nao encontrado! **** \n");
       printf("\n\n\n--Para fazer nova consulta pressione ENTER para retornar ao menu--\n\n\n");
		getch();
  } 
	
system("cls");
}
consultafilmePesquisa (struct filme lista_filme[100],int id_pesquisa1) { //consulta de filmes por id
	int i;
	system ("cls");
	printf("\t ---- CONSULTA DE FILME POR PESQUISA ----\n");
	fflush(stdin);
	for(i=0; i<qtd_filme; i++){
  	  	  if(lista_filme[i].id==id_pesquisa1){
  	  	  	printf ("\nId:      %i",lista_filme[i].id);
			printf ("\nNome:	%s",lista_filme[i].nome);
			printf ("%\nGênero: %s",lista_filme[i].genero);
			printf ("%\nAno de lançamento: %s\n\n",lista_filme[i].anolan);	
			printf("\n\n\n--Para fazer nova consulta por ID pressione ENTER para retornar ao menu--\n\n\n");
			getch ();
			} 
	}
	if(id_pesquisa1>qtd_filme ){// condição caso nao tenha cadastrado nenhum id
		system("cls");
       printf("\n **** Filme nao encontrado! **** \n");
       printf("\n\n\n--Para fazer nova consulta por ID pressione ENTER para retornar ao menu--\n\n\n");
	   getch();
  } 
  
system("cls");
}
void alterarCliente (struct cliente lista_cliente[100]) { //função no qual altera os dados do cliente ja cadastrados

   int i;
   int id;
  char aux;
   system("cls");
printf("\t ---- ALTERAR CLIENTE ----\n\n");
fflush(stdin);
   printf("\nInforme o id do cliente:\n");
   scanf ("%i",&id);
	   for(i=0; i < qtd_cli; i++){
	  if(id==lista_cliente[i].id) {
	     printf ("%\nNome: %s",lista_cliente[i].nome);
	     printf ("%\nCPF: %s",lista_cliente[i].cpf);
	     printf ("%\nTel: %s\n\n\n",lista_cliente[i].tel);
	     printf("\nDeseja Alterar esse cliente? s / n\n\n");
	     printf("Opcao Escolhida:");
	     fflush(stdin);
	     scanf("%c", &aux);
	     if (aux == 'n') {
		 break;
		}else {
	
	     
	      if(id==lista_cliente[i].id);
	        {
	           printf("\n\n");
	           fflush(stdin);
	           printf("\n1.Novo nome cliente:\n");
	           gets(lista_cliente[i].nome);
	
	           printf("\n2.Novo CPF cliente:\n");
	           gets(lista_cliente[i].cpf);
	
	           printf("\n3.Novo telefone cliente:\n");
	           gets(lista_cliente[i].tel);
	
	           
	           printf("O cliente foi alterado com sucesso!");
	         
	       }
	    }
	   printf("\n\n---------------------------------------\n");
	   printf("\nPressione alguma tecla para voltar.....\n");
	   getch();
	  }
	}
	 if(id>qtd_cli ){// condição caso nao tenha nenhum id cadastrado
		system ("cls");
	       printf("\n **** Cliente nao encontrado! **** \n");
	       printf("\n\n\n--Para fazer nova consulta pressione ENTER para retornar ao menu--\n\n\n");
			getch();
  } 
	
	}


void alterarFilme (struct filme lista_filme[100]) { //função no qual altera as informaçoes dos filmes ja cadastrados

   int i;
   int id;
   int aux;
   system("cls");
printf("\t ---- ALTERAR FILME ----\n\n");
   fflush(stdin);
   printf("\nInforme o Id do filme:\n");
   scanf ("%i",&id);
   for(i=0; i < qtd_filme; i++) {
  if(id==lista_filme[i].id) {
     printf ("%\nNome: %s",lista_filme[i].nome);
     printf ("%\nGenero: %s",lista_filme[i].genero);
     printf ("%\nAno lançamento: %s\n\n\n",lista_filme[i].anolan);
     printf("\nDeseja Alterar esse filme? s/n  \n\n");
     printf("Opcao Escolhida:");
     fflush(stdin);
     scanf("%c", &aux);
     if (aux=='n') {
	 break;
} else {
	
      if(id==lista_filme[i].id);
        {
           printf("\n\n");
           fflush(stdin);
           printf("\n1.Novo nome do filme:\n");
           gets(lista_filme[i].nome);

           printf("\n2.Novo genero:\n");
           gets(lista_filme[i].genero);

           printf("\n3.Novo ano de lançamento: \n");
           gets(lista_filme[i].anolan);

           
           printf("O filme foi alterado com sucesso!");
         }
       
    }  
printf("\n\n---------------------------------------\n"); 
printf("\nPressione alguma tecla para voltar.....\n");
   getch();
}
}
if(id>qtd_cli ){// condição caso nao tenha nenhum id cadastrado
		system ("cls");
	       printf("\n **** Filme nao encontrado! **** \n");
	       printf("\n\n\n--Para fazer nova consulta pressione ENTER para retornar ao menu--\n\n\n");
			getch();
  } 
}

 regradeneg(struct rdg listardg[100],struct filme lista_filme[100],struct cliente lista_cliente[100], int id_pesquisa) { // Chamado no programa de cadastro de "filme por cliente"
	int i;
	char aux;
	int idfilme;
	system("cls");
printf("\t ---- Regra de Negocio ----\n\n");
   fflush(stdin);
   
		printf("\nInforme o Id do filme :\n");
	   scanf ("%i",&idfilme);
	   if(idfilme>qtd_filme){// condição caso nao tenha nenhum filme cadastrado
		system ("cls");
	       printf("\n **** Filme nao encontrado! **** \n");
	       printf("\n\n\n--Para fazer nova consulta pressione ENTER para retornar ao menu--\n\n\n");
			getch();
  }
	   for(i=0;i<qtd_filme;i++){
	   if(idfilme==lista_filme[i].id){
			printf ("\nNome:	%s",lista_filme[i].nome);
			printf ("%\nGênero: %s",lista_filme[i].genero);
  	  	  	  

	   printf("\n\nConfirma os dados do Filme (s/n)? "); 
	     fflush(stdin);
	     scanf("%c", &aux);
	     if (aux=='n'){
	     	break;
		 }
		 printf ("Nome do Cliente:\n");
	fflush(stdin);
	gets(listardg[i].nomeCliente);
	fflush(stdin);
	printf ("Telefone:");
	fflush(stdin);
	scanf ("%s",&listardg[i].telcliente);

	printf("O Cadastro foi feito com sucesso!");
	printf("\n\n---------------------------------------\n"); 
	printf("\nPressione alguma tecla para voltar.....\n");
	getch ();
	} 
} 
}	






void relatorio(struct rdg listardg[100],struct filme lista_filme[100]){ // Chamado no Programa de "consulta de filmes por clientes"
  int i;
  system ("cls");
  for(i=0; i<qtd_filme; i++){
	printf ("\nNome do Cliente: %s",listardg[i].nomeCliente);
	printf ("\nFilme:	%s",lista_filme[i].nome);
	printf ("\nGênero: %s",lista_filme[i].genero);
	printf ("\nTelefone: %s\n\n",listardg[i].telcliente); 
  }
printf("\n\n---------------------------------------\n"); 
printf("\nPressione alguma tecla para voltar.....\n");
   getch();  
}

menu_cadastrar() {
	int operacao;
	system("cls");
	printf("\t ---- TELA DE CADASTRO ----\n\n");
	printf("1-Cadastrar Cliente \n");
	printf("2-Cadastrar Filme \n");
	printf("3-Cadastro de cliente com locação de filme \n"); //Regra de Negocio 
	printf("4-Voltar ao menu principal\n");
	scanf("%d",&operacao);
	return operacao;
	
}

menu_consultar() {
	int operacao;
	system ("cls");
	printf("\t ---- TELA DE CONSULTA ----\n\n");
	printf("1-Consultar todos clientes \n");
	printf("2-Consultar cliente por pesquisa \n");
	printf("3-Consultar filmes \n");
	printf("4-Consultar filme por pesquisa \n");
	printf("5-Relatório de filmes locados \n"); //Relatorio 
	printf("6-Voltar ao menu principal\n");
	scanf("%d",&operacao);
	return operacao;
	
}

menu_alterar() {
	int operacao;
	system("cls");
	printf("\t ---- TELA DE ALTERAÇÃO ----\n\n");
	printf("1-Alterar Clientes \n");
	printf("2-Alterar Filmes \n");
	printf("3-Voltar ao menu principal\n");
	scanf("%d",&operacao);
	return operacao;
	
}



sobre_sistema() {//  fala exemplificadamente sobre o  que o sistema  faz e que foram seus desenvolvedores
	
system("cls");

printf("\t ---- SOBRE O SISTEMA ----\n\n");
	printf("O sistema da LockFilms foi desenvolvida com o objetivo de concluir uma atividade acadêmica e\ntambém projetar uma melhora e eficiência para organizações que possuem um negócio de locadora.\n\n");
	printf("Com ele, seu ambiente organizacional terá um software que preza pela rapidez e integridade de seus dados.\nSeu sistema fluído e interface agradável são um diferencial dentre os outros do mercado.\n\n\n\n");
	printf("\t ---- DESENVOLVEDORES ----\nRenan Marques - CEO da empresa LockFilms\nAllan Lucas - Programador e analista\n");

printf("\n\n\nPressione ENTER para retornar ao menu principal.\n");
getch();			
system("cls");

}


int cont;
int opcao_principal;
int id_pesquisa,id_pesquisa1;
main() {
setlocale(LC_ALL, "Portuguese");
int opcao_cadastro;
struct cliente lista_cliente[100];
struct filme lista_filme[100];
struct rdg listardg[100];

login();
do {

opcao_principal = menu_principal();
switch(opcao_principal) {
	case 1: 
	system("cls");
	do {
		
		
		
		opcao_cadastro=menu_cadastrar();
		
		switch(opcao_cadastro) {
			
			case 1:
				
			cadastroCliente(lista_cliente);
			
			break;
			
				case 2:
					cadastroFilme(lista_filme);
					break;
							case 3: 
							regradeneg(listardg,lista_filme,lista_cliente);
							break;
						case 4 :
						break;							
						default:
							system ("cls"); 	
							printf("\t*** OPÇÃO INVÁLIDA! ***\nDigite a opção desejada disponível no menu.\nPressione ENTER para tentar novamente.\n");
							getch();
							system("cls");
		}
	} while(opcao_cadastro!=4);
	break;
	
	case 2:
		system("cls");
		do {
		
		
		opcao_cadastro=menu_consultar();
		switch(opcao_cadastro) {
			case 1:
			consultarCliente(lista_cliente);
			break;
			
		          	case 2:
		          		system ("cls");
		          		printf("\t ---- CONSULTA DE CLIENTE POR PESQUISA ----\n");
						fflush(stdin);
		          		printf ("\nDigite o id de Pesquisa: ");
		          		scanf ("%d",&id_pesquisa);
		          		consultaClientePesquisa(lista_cliente,id_pesquisa);
				break;
				
			             	case 3: 
			             	consultarFilme(lista_filme,lista_cliente);
				             break;
			case 4:
			system ("cls");
      		printf("\t ---- CONSULTA DE FILME POR PESQUISA ----\n");
			fflush(stdin);
      		printf ("\nDigite o id de Pesquisa: ");
      		scanf ("%d",&id_pesquisa1);
			  consultafilmePesquisa (lista_filme,id_pesquisa1);
				
				break;
			case 5:
				relatorio(listardg,lista_filme);
				break;
		 case 6:
		break;
			default: 
			system ("cls");
			printf("\t*** OPÇÃO INVÁLIDA! ***\nDigite a opção desejada disponível no menu.\nPressione ENTER para tentar novamente.\n");
			getch();
			system("cls");
						
		}
	} while(opcao_cadastro!=6);
	break;
		
		case 3:
			system("cls");
			do {
		
		
		
		opcao_cadastro=menu_alterar();
		switch(opcao_cadastro) {
			case 1:
			alterarCliente (lista_cliente);
			break;
			
		          	case 2:
		          	 alterarFilme (lista_filme);
				break;
				
			             	case 3: 
				             break;
				default: 
				system ("cls");
				printf("\t*** OPÇÃO INVÁLIDA! ***\nDigite a opção desejada disponível no menu.\nPressione ENTER para tentar novamente.\n");
				getch();
							system("cls");
		}
	} while(opcao_cadastro!=3);
	break;

	case 4:
		system("cls");
		
		opcao_cadastro=sobre_sistema();
		switch(opcao_cadastro) {
			case 1:
			sobre_sistema();
				default: 
					break;
				
		}
		break;
	case 5:
					system("cls");
				printf("\t Saindo do sistema... \n OBRIGADO!");
				getch();
				return 1;
				default:
				system ("cls");
				printf("\t*** OPÇÃO INVÁLIDA! ***\nDigite a opção disponível no menu.\nPressione ENTER para tentar novamente.\n");
				getch();
							system("cls");
				break;
			}
			}while(opcao_principal!=5);
		} 
