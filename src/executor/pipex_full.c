#include "minishell.h"


//mi aspetto che la parte del retrieving degli argomenti venga gestita dal parser e lexer, 
//per cui imposto le funzioni di modo che ricevano gli argomenti gia' sistemati dalle precedenti.


//controlla se l'eventuale file che viene passato in entrata esiste o meno. 
int ft_file_check(int file, char *file_arg)
{
    if (file == -1)
    {
        ft_printf("No such file or directory: %s\n", file_arg);
        return (-1);
    }
    return (1);
}

//funzione a cui e' delegata esecuzione di processo pipeato. 
//da usare sia in caso di pipe multiple, sia in caso di singola richiesta da terminale, poiche
//essa va trattata come un istanziare un singolo processo che esegue il comando e rimanda
//su una singola pipe il risultato della singola istruzione al "MAIN" della shell 
void    exec(char *cmd, char **env)
{


}



int ft_redir(char *cmd, char **env, int fd_in)
{
    int pid;
    int pipefd[2];

    pipe(pipefd);
    pid = fork();
    if (pid)
    {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN);
        waitpid(pid, NULL, 0);
    }
    else
    {
       close(pipefd[0]);
       dup2(pipefd[1], STDOUT);
       if (fdin == STDIN)
            exit(1);
        else
            exec(cmd, env); 
    }
}




// qua va implementata PIPEX con i bonus 
//
// come va gestita pipex qui?
// i comandi hanno un ordine invertito, nel senso che non arrivano piu come input diretto 
// dall argv
// ARRIVANO invece come input dal parser che li mette ordinati nella struttura o lista 
// della COMMAND TABLE, e dobbiamo tenerne traccia con un ordine/id ed eseguirli poi 
// con l'éxecutor di conseguenza. 
//
// Se l'executor vede che e'necessario attivare una pipe, chiama le funzioni di pipex completo, 
// executor gestisce la chiamata a pipe appena ne vede una sola, e poi pipex gestisce anche se ci sono 
// pipe multiple, oppure la logica delle pipe multiple va gestita da executor??
//
// Le variabili ambientali, invece che farne il parsing dentro pipex, vediamo di averle
// in una struttura fin da quando viene attivato il programma, di modo da averle comode sempre come riferimento 
//
