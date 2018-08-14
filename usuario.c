#include<stdio.h>
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

/*Usuario atualizarCliente() {
	Usuario u, u2;
	int i;
	int op;
	int continuar = 0;

	printf ("Login: ");
	fgets (u.login, 20, stdin);
	for (i = 0; i < quantidade_usuarios; i++) 
  {
		if (strcmp(u.login, usuarios[i].login) == 0) 
    {
			printf ("Nome: %s", usuarios[i].nome);
			printf ("\n\nDeseja atualizar...\n\n1 - Nome\n2 - Senha\n3 - Cancelar\n\nOpção: ");
			scanf ("%d", &op);
			getchar();

			switch (op) 
      {
				case 1:
					printf ("Novo nome: ");
					fgets (c2.nome, 32, stdin);
					strcpy (usuarios[i].nome, "");
					strcpy (usuarios[i].nome, c2.nome);
					break;

				case 2:
					printf ("Nova senha: ");
					fgets (c2.senha, 10, stdin);
					strcpy (usuarios[i].senha, "");
					strcpy (usuarios[i].senha, c2.senha);
					break;

				case 3:
					continuar = 1;
					break;

				default:
					printf ("Digite uma opção válida.");
			}
		} 
    else 
    {
			printf ("Usuário não encontrado.");
		}
	}
}*/




Usuario usuarios[999];
int quantidade_usuarios;

void removeQuebraLinha(char *string); //pronta
void leString(char *string_destino, int quantidade_caracteres); //pronta
void imprimeVetorUsuarios(); //pronta
void confirmaSenhaUsuario(); //pronta
void insereNovoUsuario(); //pronta
void buscarUsuario();
void editarUsuario();


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

void editarUsuario()
{
  Usuario u, u2;
  int i;
  int op;
  int continuar = 0;

  printf("Login: ");
  leString(u.login, 15);

  for(i = 0; i < quantidade_usuarios; i++)
  {
    if(strcmp(u.login, usuarios[i].login) == 0)
    {
      printf("Nome: %s", usuarios[i].nome);

      printf("\nSelecione qual dado você deseja editar: ");
      printf("\n1 - Nome");
      printf("\n2 - Email");
      printf("\n3 - Login");
      printf("\n4 - Senha");
      printf("\n5 - Cancelar");
      printf("\n\nOpção: ");
      scanf("%d", &op);
      getchar();

      switch(op)
      {
        case 1:
        printf("Digite seu novo nome: ");
        leString(u2.nome, 30);
        strcpy (usuarios[i].nome, "");
				strcpy (usuarios[i].nome, u2.nome);
				break;

        case 2:
        printf("Digite seu novo E-mail: ");
        leString(u2.email, 30);
        strcpy (usuarios[i].email, "");
				strcpy (usuarios[i].email, u2.email);
				break;

        case 3:
        printf("Digite seu novo Login: ");
        leString(u2.login, 15);
        strcpy (usuarios[i].login, "");
				strcpy (usuarios[i].login, u2.login);
				break;

        case 4:
        printf("Digite sua nova senha: ");
        leString(u2.senha, 15);
        printf("Confirme sua nova senha: ");
        leString(u2.confirm_senha, 15);
        //parte de confirmação de senha
        if(strcmp(u2.senha, u2.confirm_senha) == 0)
        {
          printf("Senhas coincidem!\n");
        }
        else
        {
          do
          {
            printf("\nSenhas não coincidem!\n");
            printf("Confirme novamente: ");
            leString(u2.confirm_senha, 15);
          }while(strcmp(u2.senha, u2.confirm_senha) != 0);
          printf("\nSenha Confirmada!\n");
        }
        strcpy (usuarios[i].senha, "");
				strcpy (usuarios[i].senha, u2.senha);
				break;

        case 5:
        continuar = 1;
        break;

        default:
        printf("Digite uma opção válida!");
      }
    }
    else
    {
      printf("Usuário não encontrado!");
    }
  }
}

int main()
{
  insereNovoUsuario();

  editarUsuario();
}