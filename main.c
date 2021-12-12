
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct people{
  char cpf[15];
  char *nome;
  int idade;
  double peso, altura;
} Pessoa;

Pessoa criaPessoa(char *string){
  Pessoa aux;
  char* parte;

  parte = strtok(string, ";");

  aux.nome = malloc(sizeof(char) * strlen(parte) + 1);
  strcpy(aux.nome, parte);

  parte = strtok(NULL, ";");
  strcpy(aux.cpf, parte);

  parte = strtok(NULL, "\n");
  sscanf(parte, "%d;%lf;%lf", &aux.idade, &aux.altura, &aux.peso);

  return aux;
}

int main(){
  Pessoa ent, gigante = {0}, fortao={0}, experiente={0};
  int qtd;
  char linha[201];

  scanf("%d", &qtd);

  for(int i=0; i<qtd; i++){
    scanf(" %[^\n]", linha);

    ent = criaPessoa(linha);

    if(ent.idade > experiente.idade)
      experiente = ent;
    if(ent.peso > fortao.peso)
      fortao = ent;
    if(ent.altura > gigante.altura)
      gigante = ent;
  }

  printf("Resultado:\n");
  printf("Mais alto: %s (%s)\nMais pesado: %s (%s)\nMais velho: %s (%s)\n", gigante.nome, gigante.cpf, fortao.nome, fortao.cpf, experiente.nome, experiente.cpf);
}