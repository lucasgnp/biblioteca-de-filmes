#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//LISTANDO ESTRUTURAS

//Estrutura de usuário
typedef struct
{
  char nome[30];
  int idade;
  char email[30];
  char login[15];
  char senha[15];
  char confirm_senha[15];
}Usuario;

Usuario usuarios[999];
int quantidade_usuarios;

//listando funções
void removeQuebraLinha(char *string); //pronta
void leString(char *string_destino, int quantidade_caracteres); //pronta
void imprimeVetorUsuarios(); //pronta
void confirmaSenhaUsuario(); //pronta
void insereNovoUsuario(); //pronta
void buscarUsuario();
void editarUsuario();

//Estrutura de Administrador
typedef struct
{
  char login[15];
  char senha[15];
}Adm;

Adm administrador[1];

//listando funções
void ativaAdmin() //pronta

//Estrutura de filmes
typedef struct 
{
  char titulo[30];
  char sinopse[250];
  char genero[20];
  int ano_lancamento;
  int classificacao_indicativa;
  char direcao[30];
  int duracao;
}Filme;

Filme filmes[999];
int quantidade_filmes;
int media_avaliacao = 0;

void adicionaFilme(); //pronta
void exibirFilmes(); //pronta
void adicionaFilmeALista();

//----------USUÁRIO----------

//função do professor para remover quebra de linha
void removeQuebraLinha(char *string)
{
    if(string != NULL && strlen(string) > 0)
    {
        short tamanho = strlen(string);
        if(string[tamanho-1] == '\n'){
            string[tamanho-1] = '\0';
        }
    }
}

//função do professor para ler uma string sem a quebra de linha
void leString(char *string_destino, int quantidade_caracteres)
{
    fgets(string_destino, quantidade_caracteres, stdin);
    
    removeQuebraLinha(string_destino);
}

//imprime os usuários já cadastrados
void imprimeVetorUsuarios(){
    int c;
    printf("\nListando %d usuarios cadastrados\n", quantidade_usuarios);
    for(c=0; c < quantidade_usuarios; c++){
        printf("-----------------------------------\n");
        printf("(%d)\n", c+1);
        printf("Nome: %s\n", usuarios[c].nome);
        printf("Idade: %d\n", usuarios[c].idade);
        printf("E-mail: %s\n", usuarios[c].email);
        printf("Login: %s\n", usuarios[c].login);
    }
}

//função usada no cadastro do usuário para a igualidade entre a confirmação de senha
void confirmaSenhaUsuario()
{
  Usuario u;
  int i, cont;

  printf("Senha: ");
  leString(u.senha, 15);

  printf("Confirme sua senha: ");
  leString(u.confirm_senha, 15);

  if(strcmp(u.senha, u.confirm_senha) == 0)
  {
    printf("Senhas coincidem!\n");
  }
  else
  {
    do
    {
      printf("\nSenhas não coincidem!\n");
      printf("Confirme novamente: ");
      leString(u.confirm_senha, 15);

    }while(strcmp(u.senha, u.confirm_senha) != 0);
    printf("\nSenha Confirmada!\n");
  }
}

//cadastra um usuário novo
void insereNovoUsuario()
{
  Usuario u;

  printf("\nNome: ");
  fgets(u.email, 30, stdin);

  printf("E-mail: ");
  leString(u.email, 30);

  printf("Login: ");
  leString(u.login, 15);

  confirmaSenhaUsuario();

  printf("Idade: ");
  scanf("%d", &u.idade);

  usuarios[quantidade_usuarios] = u;

  quantidade_usuarios++;
}

//----------ADMINISTRADOR----------

//inicializa o login do adm
void ativaAdmin()
{
	Adm a;

	strcpy(a.login, "admin");
	strcpy(a.senha, "password");

	administrador[0] = a;
}

//----------FILMES----------

//adiciona um novo filme à Biblioteca
void adicionaFilme()
{
  Filme f;
  int i;

  printf("----------Adicionar Filme----------\n");

  printf("\nTitulo: ");
  leString(f.titulo, 30);

  printf("\nSinopse: ");
  leString(f.sinopse, 250);

  printf("\nGênero: ");
  leString(f.genero, 20);

  printf("\nDireção: ");
  leString(f.direcao, 30);

  printf("\nDuração (em minutos): ");
  scanf("%d", &f.duracao);

  do{
  printf("\nAno de Lançamento: ");
  scanf("%d", &f.ano_lancamento);
  }while(f.ano_lancamento > 2018);

  printf("\nClassificação indicativa: ");
  scanf("%d", &f.classificacao_indicativa);

  printf("\n-----------------------------------\n");

  filmes[quantidade_filmes] = f;

  quantidade_filmes++;
}

//exibe os filmes existentes na Biblioteca
void exibirFilmes()
{
  int i;

  if(quantidade_filmes != 0)
  {
    printf("\nListando %d Filmes na Biblioteca\n", quantidade_filmes);

    for(i = 0; i < quantidade_filmes; i++)
    {
      printf("-----------------------------------\n");
      printf("(%d)\n", i+1);
      printf("Titulo: %s\n", filmes[i].titulo);
      printf("Sinopse: %s\n", filmes[i].sinopse);
      printf("Gênero: %s\n", filmes[i].genero);
      printf("Ano de Lançamento: %d\n", filmes[i].ano_lancamento);
      printf("Classificação indicativa: %d\n", filmes[i].classificacao_indicativa);
      printf("Duração: %d\n", filmes[i].duracao);
      printf("Direção: %s\n", filmes[i].direcao);
    }
  }
  else
  {
    printf("Não há nenhum filme cadastrado!");
  }
}




//MAIN

int main()
{

  return 0;
}