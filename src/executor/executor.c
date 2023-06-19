#include "minishell.h"
//da usare solo con un singolo comando senza le pipes. Gestione dell'esecuzione del programma
//con comando gia pulito. si crea singolo processo fisso, si fa eseguire e si riprende un risultato...
//ma allora vale lo stesso con pipex...
//quindi non ha senso duplicarl

//executor prende la Command Table generata dal parser e per ogni SimpleCommand nella struttura 
//crea un nuovo processo figlio che esegue il SimpleCommand
//Se i processi sono > 1, executor esegue i relativi gestendo la logica della pipe o redirect.

//command table fake 
typedef struct Ctable{
    char *command;
    struct Ctable *next;
} fakeCtable;



//qui e' da considerare che il comando viene gia retrievato in fase di parsing. 
// quindi tutto quello che in pipex veniva gestito dentro a figlio e padre, lato check,
// non viene gestito qua, ma viene gestito dal parser. 
int only_child(char *command, char **envp)
{
    if (execve(command, NULL, envp) == -1)
    {
        ft_printf("Could not execute\n");
        //libera la struct 
        return (2);
    }
}


//questo esegue solo se non vede |, >, < 
void    exec_single(char *cmd, char **env)
{
    //qui si crea un solo processo figlio che esegue, il padre aspetta. 
    //il figlio deve mandare al padre 
    int id;

    id = fork();
    if(id == -1)
    {
        ft_printf("Error forking");
        exit(-1);   
    }
    if (id == 0)
    {
        only_child(cmd, env);
    }
    else
    {
        waitpid(id, NULL, 0);
    }

}


int main(int argc, char **argv, char **envp)
{

    fakeCtable command_1;
    command_1.command = argv[1];
    command_1.next = NULL;

    exec_single(command_1.command, envp);
    ft_printf("Correctly returned to main after forking child\n");

}