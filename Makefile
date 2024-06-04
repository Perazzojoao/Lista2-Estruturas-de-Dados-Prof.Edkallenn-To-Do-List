CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = tarefa/tarefa.h concluidas/concluidas.h listaTarefas/listaTarefas.h
OBJ = output/ED-lista2-questao04.o output/tarefa/tarefa.o output/concluidas/concluidas.o output/listaTarefas/listaTarefas.o
EXECUTABLE = output/ED-lista2-questao04

output/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

compilar: 
		if not exist output\tarefa (mkdir output\tarefa)
		if not exist output\concluidas (mkdir output\concluidas)
		if not exist output\listaTarefas (mkdir output\listaTarefas)
		$(MAKE) $(EXECUTABLE)

exec: compilar
		./$(EXECUTABLE)