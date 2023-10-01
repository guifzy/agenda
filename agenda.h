
struct agenda
   {
     char nome[100],telefone[10],celular[10];          
     int tam;     
   } ; 

   
void cadastro(struct agenda pt[]); // Função para cadastro de contatos na agenda.
void statusagenda( struct agenda pt[]); // Função que mostra o Estado da Agenda.
void pesquisarcontatos(struct agenda pt[]); // Função para pesquisar um contato na agenda.
void alterarcontatos(struct agenda pt[]);
void excluircontatos(struct agenda pt[]); // Função para excluir contatos da agenda.
void exibircontatos (struct agenda pt[]); // Função que mostra todos os contatos cadastrados.
