#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void removeQuebraLinha(char *string); //pronta
void leString(char *string_destino, int quantidade_caracteres); //pronta
void adicionaFilme(); //pronta
void imprimeVetorFilmes(); //pronta

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

void adicionaFilme()
{
  Filme f;
  int i;

  printf("----------Adicionar Filme----------\n");

  printf("\nTitulo: ");
  leString(f.titulo, 30);

  for(i = 0; i < quantidade_filmes; i++)
  {
    strcmp(f.titulo, filmes[i])
  }

  printf("\nSinopse: ");
  leString(f.sinopse, 250);

  printf("\nGênero: ");
  leString(f.genero, 20);

  printf("\nDireção: ");
  leString(f.direcao, 30);

  printf("\nDuração (em minutos): ");
  scanf("%d", &f.duracao);

  printf("\nAno de Lançamento: ");
  scanf("%d", &f.ano_lancamento);

  printf("\nClassificação indicativa: ");
  scanf("%d", &f.classificacao_indicativa);

  printf("\n-----------------------------------\n");

  filmes[quantidade_filmes] = f;

  quantidade_filmes++;
}

void imprimeVetorFilmes()
{
    int c;
    printf("\nListando %d Filmes na Biblioteca\n", quantidade_filmes);
    for(c=0; c < quantidade_filmes; c++){
        printf("-----------------------------------\n");
        printf("(%d)\n", c+1);
        printf("Titulo: %s\n", filmes[c].titulo);
        printf("Sinopse: %s\n", filmes[c].sinopse);
        printf("Gênero: %s\n", filmes[c].genero);
        printf("Ano de Lançamento: %d\n", filmes[c].ano_lancamento);
        printf("Classificação indicativa: %d\n", filmes[c].classificacao_indicativa);
        printf("Duração: %d\n", filmes[c].duracao);
        printf("Direção: %s\n", filmes[c].direcao);
    }
}



