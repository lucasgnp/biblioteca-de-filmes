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
}Usuario;

Usuario usuarios[999];
int quantidade_usuarios;

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

/*void escondeSenha()
{
  do{
      c=getch();
      if(isprint(c))  //Analisa se o valor da variável c é imprimivel
      {       
      cadastro_senha[a]=c;  //Se for, armazena o caractere 
      a++;
      printf("*");          //imprime o * Anterisco
      }
           else if(c==8&&a){     //8 é o caractere BackSpace na tabela ASCII, && a analisa se a é diferente de 0
           cadastro_senha[a]='\0';
           a--;
           printf("\b \b");       //Apagando o caractere digitado
           } 
       }while(c!=13);             //13 é o valor de ENTER na tabela ASCII
}*/

void insereNovoUsuario()
{
  Usuario u;

  printf("\nNome: ");
  fgets(u.email, 30, stdin);

  printf("E-mail: ");
  leString(u.email, 30);

  printf("Login: ");
  leString(u.login, 15);

  printf("Senha: ");
  leString(u.senha, 15);

  printf("Idade: ");
  scanf("%d", &u.idade);

  usuarios[quantidade_usuarios] = u;

  quantidade_usuarios++;
}

int main()
{
  insereNovoUsuario();

  imprimeVetorUsuarios();
}