#include <stdio.h>
#include<stdlib.h>
#include<string.h>

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

void removeQuebraLinha(char *string); //pronta
void leString(char *string_destino, int quantidade_caracteres); //pronta
void imprimeVetorUsuarios(); //pronta
void confirmaSenhaUsuario(); //pronta
void insereNovoUsuario(); //pronta
void buscarUsuario();
void editarUsuario();


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

void leString(char *string_destino, int quantidade_caracteres)
{
    fgets(string_destino, quantidade_caracteres, stdin);
    
    removeQuebraLinha(string_destino);
}

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

int buscarUsuario

/*void editarUsuario()
{
  Usuario u;
  //pesquisar usuario
  //se okay dar opcoes de edicao
  //se nao imprimir mensagem de erro e solicitar nova pesquisa

  //menu edicao
  printf("-----------------------------------\n");
  printf("Qual dado você deseja editar: \n\n");
  printf("1 - Nome\n");
  printf("2 - Idade\n");
  printf("3 - E-mail\n");
  printf("4 - Login\n");
  printf("5 - Senha\n");

}*/

int main()
{
  insereNovoUsuario();
}