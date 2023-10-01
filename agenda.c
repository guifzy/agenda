#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "agenda.h" 
 
 
 void statusagenda(struct agenda pt[]) // Função que mostra o Estado da Agenda.
 {
 // Será mostrado na tela a capacidade máxima da agenda , e quantos contatos foram cadastrados.
    printf("\n");
    printf("||--------------------------------------------------------------|| \n");
    printf("||--------------------- Status da Agenda -----------------------|| \n");
    printf("||--------------------------------------------------------------|| \n\n");    
 
    printf(" Quantidade maxima de contatos : 100 \n"); 
    printf(" Contatos Cadastrados : %i",pt[0].tam);
    printf("\n\n");
    system("PAUSE");    
           
 }    
 void pesquisarcontatos(struct agenda pt[]) // Função para pesquisar um contato na agenda.
 {
    char verific[100], o='s';
    int i,k;
    
    printf("\n");
    printf("||--------------------------------------------------------------|| \n");
    printf("||--------------------- Pesquisar Contatos ---------------------|| \n");
    printf("||--------------------------------------------------------------|| \n\n");
    
    while((o=='s')||(o=='S'))
    {
    printf(" Informe o nome do usuario : " );         
    
    fflush(stdin); // Limpa o buffer do teclado.
    fgets(verific,99,stdin);
    
    for(i=0;i<strlen(verific);i++)
      {
         if((verific[i]>='a') && (verific[i]<='z')) // Passa todos os caracteres minúsculos para maiusculos.
         {
            verific[i]-=32;
         }      
      }
    
    for(i=0;i<pt[0].tam;i++) // pt[0].tam corresponde à quantidade de contatos cadastrados.
    {
       k=strcmp(verific,pt[i].nome); // Verifica se o nome digitado existe na agenda.
       if(k==0) // Caso exista , os dados do contato são mostrados na tela.
       {
           printf("\n");
           printf(" Contato  : %s ",pt[i].nome);
           printf("Telefone : %s ",pt[i].telefone);
           printf("Celular  : %s ",pt[i].celular);
           printf("\n"); 
           //k=0;
           break;       
       }     
    }
    if(k!=0)
    {
           printf("\n"); // Caso não exista , uma mensagem de erro é mostrada na tela.
           printf(" Contato nao existe.\n\n");      
    }  
      
   printf(" Deseja pesquisar outro contato ? S/N \n");
   scanf("%c",&o);
 }
}
 void alterarcontatos(struct agenda pt[])
 {
    char verific[100];
    int i,k;
    
    printf("\n");
    printf("||--------------------------------------------------------------|| \n");
    printf("||------------------- Alteracao de Contatos --------------------|| \n");
    printf("||--------------------------------------------------------------|| \n\n");
    printf(" Informe o nome do usuario : " );         
    
    fflush(stdin);
    fgets(verific,99,stdin);
    
    for(i=0;i<strlen(verific);i++)
      {
         if((verific[i]>='a') && (verific[i]<='z')) // Passa todos os caracteres minúsculos para maiusculos.
         {
            verific[i]-=32;
         }      
      }
    
    for(i=0;i<pt[0].tam;i++)
    {
       k=strcmp(verific,pt[i].nome); // Verifica se o nome digitado existe na agenda.
       if(k==0) // Caso exista , o usuário poderá modificar apenas o núméro de telefone e o de celular.
       {
           printf("\n");
           printf(" Contato  :%s ",pt[i].nome);
           printf("Telefone :%s ",pt[i].telefone);
           printf("Celular  :%s ",pt[i].celular);
           printf("\n");
           printf("Informe o novo numero de telefone : ");
           fflush(stdin); // Limpa o Buffer do teclado.
           fgets(pt[i].telefone,9,stdin);
           printf("Informe o novo numero do celular : ");
           fflush(stdin);
           fgets(pt[i].celular,9,stdin);
           k=0;
           break;  
       }                       
    }
    if(k!=0)
       {
         printf("\n");
         printf(" Contato nao cadastrado. \n"); // Caso não exista , uma mensagem de erro é mostrada na tela.
       }
   printf("\n\n");
   system("PAUSE");
 
 }

 void excluircontatos(struct agenda pt[]) // Função para excluir contatos da agenda.
 {
      char verific[100];
      int k,i,j;
      char b;
      printf("\n");
      printf("||--------------------------------------------------------------|| \n");
      printf("||------------------- Exclusao de Contatos ---------------------|| \n");
      printf("||--------------------------------------------------------------|| \n\n");
      printf("Informe o nome do usuario :" );
 
      fflush(stdin);
      fgets(verific,99,stdin);
      
      for(i=0;i<strlen(verific);i++)
      {
         if((verific[i]>='a') && (verific[i]<='z')) // Passa todos os caracteres minúsculos para maiusculos.
         {
            verific[i]-=32;
         }      
      }
      
      for(i=0;i<=pt[0].tam;i++)
      {
        k=strcmp(verific,pt[i].nome); // Verifica se o nome digitado existe na agenda.
          if(k==0) // Caso exista , os dados do contato são mostrados na tela
          {
             printf("\n");
             printf("Contato  :%s ",pt[i].nome);
             printf("Telefone :%s ",pt[i].telefone);
             printf("Celular  :%s ",pt[i].celular);                   
             break;            
          }
      }
      if(k==0)
      {
       printf("\n");
       printf(" Deseja realmente excluir o contato ? S/N "); // O usuário deve confirmar a exclusão do contato.
       scanf("%c",&b);
      
       if((b=='s') || (b=='S'))
       {
         for(j=i;j<pt[0].tam;j++) // Caso o usuário confirme a exclusão, todos os outros registros serão movidos
         // para que o espaço liberado na estrutura seja preenchido.
         {
               strcpy(pt[j].nome,pt[j+1].nome);
               strcpy(pt[j].telefone,pt[j+1].telefone);
               strcpy(pt[j].celular,pt[j+1].celular) ;                   
         }
           pt[0].tam-=1;    
           printf("\n");     
           printf(" Usuario deletado com sucesso. \n\n"); // Após o termino do processo , uma mensagem confirma
           // que o usuário foi deletado com sucesso.
       } 
      } 
      else
      {
          printf(" Usuario nao cadastrado. \n"); // Caso o nome do contato não seja encontrado, uma mensagem de 
          // erro será mostrada na tela. 
      }     
       system("PAUSE"); 
 }
 
 void exibircontatos (struct agenda pt[]) // Função que mostra todos os contatos cadastrados.
 {
     int i;
     
     printf("\n"); 
     printf("||--------------------------------------------------------------||\n");
     printf("||------------------- Lista de Contatos ------------------------||\n");
     printf("||--------------------------------------------------------------||\n\n");
    
     for(i=0;i<pt[0].tam;i++)
     {
           
     printf(" Contato  : %s ",pt[i].nome);
     printf("Telefone : %s ",pt[i].telefone);
     printf("Celular  : %s ",pt[i].celular);
     printf("\n\n");  
     }  
     system("PAUSE");
 }
 void cadastro(struct agenda *pt) // Função para cadastro de contatos na agenda.
 {
   char x='s',verific[100];
   int i,y=-1,j;
   
   printf("\n"); 
   printf("||--------------------------------------------------------------|| \n");
   printf("||------------------- Cadastro de Contatos ---------------------|| \n");
   printf("||--------------------------------------------------------------|| \n\n");  
   
   while((x=='S') || (x=='s'))
   {
      printf(" Digite o nome do contato : "); 
      fflush(stdin);
      fgets(verific,99,stdin);
    // Aqui iremos passar todas as letras digitadas para maiúscula
      for(i=0;i<strlen(verific);i++)
      {
         if((verific[i]>='a') && (verific[i]<='z')) // Passa todos os caracteres minúsculos para maiusculos.
         {
            verific[i]-=32;
         }      
      }
    // Antes de inserir, precisamos verificar se o nome digitado já existe na agenda
      for(i=0;i<pt[0].tam;i++)
      {
           y=strcmp(verific,pt[i].nome); // Verifica se o nome digitado já existe na agenda.
           if(y==0)// Caso já exista um contato com mesmo nome , uma mensagem de erro será mostrada na tela.
           {
             printf( " Usuario ja cadastrado ! \n\n"); 
             break;
           }          
      }  
      if(y!=0) // Caso o nome do contato não exista na agenda , o processo para cadastrar o usuário em ordem
      // alfabetica é iniciado.
      {
         for(i=0;i<pt[0].tam;i++) // Loop até a quantidade de contatos cadastrados.
         {
           if(verific[0]<pt[i].nome[0]){
           	  break;
		   }
           // Verifica a ordem em que o contato será cadastrado , comparando 
           // a primeira letra do nome . Caso o nome informado tenha a primeira letra menor ( a < b )
           // que a de um dos contatos cadastrados, o Loop é interrompido na posição que o novo contato será 
           //cadastrado. Caso a primeira letra seja igual, o novo contato será cadastrado após o último contato
           //  que seja iniciado pela mesma letra. E por fim , caso a primeira letra seja maior que as cadastradas
           // na agenda, o novo contato será cadastrado na última posição.
             
         }
         for(j=pt[0].tam;j>=i;j--) // Esse Loop vai modificar a posição dos contatos já cadastrados,para criar o
         // espaço necessário para que o novo contato seja casdastrado.
         {
            
            strcpy(pt[j].nome,pt[j-1].nome); // A última posição recebe o conteúdo da posição anterior a ela, até
            strcpy(pt[j].telefone,pt[j-1].telefone); // a posição do novo cadastrado estar livre para receber o conteúdo.
            strcpy(pt[j].celular,pt[j-1].celular);
         }
          
      strcpy(pt[i].nome,verific); 
      printf(" Digite o telefone residencial do contato : "); 
      fflush(stdin);
      fgets((pt[i]).telefone,9,stdin); 
      printf(" Digite o celular do contato : "); 
      fflush(stdin);
      fgets((pt[i]).celular,9,stdin); 
      printf("\n");
      pt[0].tam++;
      printf(" Cadastro Efetuado com Sucesso. \n\n"); // Uma mensagem é mostrada na tela, indicando que o cadastro foi efetuado com sucesso.
      }
      
      printf(" Deseja cadastrar um novo contato ? S/N ");
      scanf("%c",&x);
      printf("\n");
      y=-1;
     
  }
 }          
