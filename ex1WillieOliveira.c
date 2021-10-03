#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <stdbool.h>
#include <string.h>
typedef struct {
     int NumeroDaConta;
     char Nome[100];
     float Saldo;
}Clientes;
int Menu();
Clientes cadastrar(Clientes a[],int b[]);
Clientes depositar(Clientes a[],int b[]);
Clientes sacar(Clientes a[],int b[]);
Clientes ExcluirConta(Clientes a[],int b[]);
void consultar(Clientes a[],int b[]);
int main(){
setlocale(LC_ALL, "");

    int i;
    int j;
    int validar;
    int escolha;
    int cadastrados[1]={0};//só pra saber quantas pessoas cadastradas existem
    int retorno;
    

    Clientes clients[50];
    do{
    escolha=Menu();
    switch (escolha){
        case 1:
         	i=cadastrados[0];
         	clients[i]=cadastrar(clients,cadastrados);
         	 system("PAUSE");
             system("cls");
             break;
        case 2:
        	depositar(clients,cadastrados);
        	break;
        case 3:
        	sacar(clients,cadastrados);
        	break;
        case 4:
            consultar(clients,cadastrados);
         	break;
        case 5:
        	ExcluirConta(clients,cadastrados);
        	break;
       default:
       	printf("Valor invalido...\n");
       	system("PAUSE");
         system("cls");
    }
         

       }while(escolha!=6);
       return 0;
}
int Menu(){
    int opcao;
    printf("1-Cadastramento de conta\n");
    printf("2-Depósito\n");
    printf("3-Saque\n");
    printf("4-Consulta\n");
    printf("5-Ecluir conta\n");
    printf("6-Sair\n");
    printf("Digite a sua opção: \n");
    scanf("%d",&opcao);
    system("CLS");
    return(opcao);
}
Clientes cadastrar(Clientes a[],int b[]){
    Clientes registro;
    int i;
    int validar=0;

	printf("Digite o numero da conta: ");
	scanf("%d",&registro.NumeroDaConta);
	if(b[0]==0){
	getchar();
	printf("Digite o seu nome: ");
	gets(registro.Nome);
	printf("Digite o seu saldo: ");
	scanf("%f",&registro.Saldo);
	b[0]++;
	return(registro);
      }else{
    		for(i=0;i<b[0];i++){
    			if(registro.NumeroDaConta==a[i].NumeroDaConta){
    				validar=1;
				}
			}
    		 
		}
	if(validar==0){
		getchar();
		printf("Digite o seu nome: ");
	    gets(registro.Nome);
	    printf("Digite o seu saldo: ");
	    scanf("%f",&registro.Saldo);
	    b[0]++;
	    	return(registro);
	}if(validar==1){
		printf("Ja foi registrado com esse numero da conta...\n");
	}
	system("PAUSE");
	system("CLS");
}
void consultar(Clientes a[],int b[]){
	 int i;
	 int opcao;
	 int aux;
	 int aux3=1;
	 int guardar;
	 char aux2[255];
	 printf("1-Numero da conta\n");
	 printf("2-Nome do cliente\n");
	 printf("Qual opção vc quer: ");
	 scanf("%d",&opcao);
	 if(opcao==1){
	 	printf("Digite o numero da conta: ");
	 	scanf("%d",&aux);
	 	for(i=0;i<b[0];i++){
	 		if(a[i].NumeroDaConta==aux){
	 			printf("O numero da conta eh: %d\n",aux);
	 			printf("O saldo eh: %.2f\n",a[i].Saldo);
	 			printf("Nome do client: %s\n",a[i].Nome);
	 			aux3=0;
			 }
			 
		 }
		 if(aux3==1){
			 	printf("Não existe registro com esse numero de conta...\n");
			  }
	 }else if(opcao==2){
	 	getchar();
	 	printf("Digite o nome: ");
	 	gets(aux2);
	 	for(i=0;i<b[0];i++){
	 		guardar=strcmp(a[i].Nome,aux2);
	 		if(guardar==0){
	 			printf("O numero da conta eh: %d\n",a[i].NumeroDaConta);
	 			printf("O saldo eh: %.2f\n",a[i].Saldo);
	 			printf("Nome do client: %s\n",aux2);
	 			aux3=0;
			 }
		 }
		 if(aux3==1){
			 	printf("Não existe registro com esse nome... \n");
			 }
	 }
	system("PAUSE");
	system("CLS");
}
Clientes depositar(Clientes a[],int b[]){
	int numero;
	int i;
	int aux=0;
	int aux2=1;
	float deposito;
	
	printf("Digite o numero da conta: ");
	scanf("%d",&numero);
	for(i=0;i<b[0];i++){
		if(numero==a[i].NumeroDaConta){
			aux=i;
			aux2=0;
			printf("Digite o valor do deposito: ");
			scanf("%f",&deposito);
			printf("Deposito realizado com sucesso...\n");
			if(deposito<0){
				printf("Valor invalido...\n");
			}else{
				a[aux].Saldo=a[aux].Saldo+deposito;
			}
		}
	}if(aux2==1){
		printf("Nenhuma conta encontrada com esse numero de conta...\n");
	}
	system("PAUSE");
	system("CLS");
}
Clientes sacar(Clientes a[],int b[]){
	int i;
	int aux;
	int aux2=1;
	float saque;
	printf("Digite o numero da conta: ");
	scanf("%d",&aux);
	for(i=0;i<b[0];i++){
		if(aux==a[i].NumeroDaConta){
			printf("Digite o valor do saque: ");
			scanf("%f",&saque);
			aux2=0;
			if(a[i].Saldo<saque){
				printf("Você não possui esse dinheiro para sacar...\n");
			}else{
				a[i].Saldo=a[i].Saldo-saque;
				printf("Saque execultado...\n");
			}
			
		}
	}if(aux2==1){
		printf("Numero da conta não registrado...\n");
		
	}
	system("PAUSE");
	system("CLS");
}
Clientes ExcluirConta(Clientes a[],int b[]){
	int i;
	int exclusao;
	int j;
	int ultimo;
	ultimo=b[0];
	printf("Digite o numero da conta que deseja excluir: ");
	scanf("%d",&exclusao);
	for(i=0;i<ultimo;i++){
		if(a[i].NumeroDaConta==exclusao){
			for(j=i;j<ultimo;j++){
				a[j]=a[j+1];
				ultimo--;
			}
		}
		
	}
	if(ultimo!=b[0]){
		b[0]=ultimo;
	}

	printf("Conta deletada com sucesso\n");
	system("pause");
	system("cls");
}
