#include "tarefa.h"

Data *criarData(int dia, int mes, int ano) {
  if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 2024) {
    return NULL;
  }
  Data *data = (Data *) malloc(sizeof(Data));
  data->dia = dia;
  data->mes = mes;
  data->ano = ano;
  return data;
}

Data *getDataAtual() {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  Data *dataAtual = (Data *) malloc(sizeof(Data));
  dataAtual->dia = tm.tm_mday;
  dataAtual->mes = tm.tm_mon + 1;
  dataAtual->ano = tm.tm_year + 1900;

  return dataAtual;
}

Tarefa *criarTarefa(char nome[], char descricao[], Data *vencimento, int prioridade) {
  Data *dataAtual = getDataAtual();
  if (vencimento->ano < dataAtual->ano
  || (vencimento->ano == dataAtual->ano && vencimento->mes < dataAtual->mes)
  || (vencimento->ano == dataAtual->ano && vencimento->mes == dataAtual->mes && vencimento->dia < dataAtual->dia)
  ) {
    return NULL;
  }

  Tarefa *tarefa = (Tarefa *) malloc(sizeof(Tarefa));
  srand(time(NULL));
  tarefa->id = (rand() % 9000) + 1000;
  strcpy(tarefa->nome, nome);
  strcpy(tarefa->descricao, descricao);
  tarefa->criacao = *dataAtual;
  tarefa->vencimento = *vencimento;
  tarefa->prioridade = prioridade;
  return tarefa;
}

void editarTarefa(Tarefa *tarefa, char nome[], char descricao[], Data vencimento, int prioridade) {
  if (tarefa->criacao.ano < vencimento.ano
  || (tarefa->criacao.ano == vencimento.ano && tarefa->criacao.mes < vencimento.mes)
  || (tarefa->criacao.ano == vencimento.ano && tarefa->criacao.mes == vencimento.mes && tarefa->criacao.dia < vencimento.dia)
  ) {
    return;
  }

  strcpy(tarefa->nome, nome);
  strcpy(tarefa->descricao, descricao);
  tarefa->vencimento = vencimento;
  tarefa->prioridade = prioridade;
}

int getPrioridade(Tarefa *tarefa) {
  return tarefa->prioridade;
}