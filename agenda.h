
struct agenda
   {
     char nome[100],telefone[10],celular[10];          
     int tam;     
   } ; 

   
void cadastro(struct agenda pt[]); // Fun��o para cadastro de contatos na agenda.
void statusagenda( struct agenda pt[]); // Fun��o que mostra o Estado da Agenda.
void pesquisarcontatos(struct agenda pt[]); // Fun��o para pesquisar um contato na agenda.
void alterarcontatos(struct agenda pt[]);
void excluircontatos(struct agenda pt[]); // Fun��o para excluir contatos da agenda.
void exibircontatos (struct agenda pt[]); // Fun��o que mostra todos os contatos cadastrados.
