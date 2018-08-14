#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char login[15];
  char senha[15];
}Adm;

Adm administrador[1];

void removeQuebraLinha(char *string)  //pronta
void leString(char *string_destino, int quantidade_caracteres)  //pronta
void ativaAdmin() //pronta

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

//inicializa o login do adm
void ativaAdmin()
{
	Adm a;

	strcpy(a.login, "admin");
	strcpy(a.senha, "password");

	administrador[0] = a;
}








