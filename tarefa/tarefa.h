#ifndef TAERFA_H
#define TAERFA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Data{
  int dia;
  int mes;
  int ano;
} Data;

typedef struct Tarefa{
  int id;
  char nome[50];
  char descricao[100];
  Data criacao;
  Data vencimento;
  int prioridade;
} Tarefa;

Data *criarData(int dia, int mes, int ano);
Data *getDataAtual();
Tarefa *criarTarefa(char nome[], char descricao[], Data *vencimento, int prioridade);
void editarTarefa(Tarefa *tarefa, char nome[], char descricao[], Data vencimento, int prioridade);
int getPrioridade(Tarefa *tarefa);

#endif