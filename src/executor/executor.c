#include "minishell.h"



//creare sovrastruttura di esecizone che 
//
//SE il processo e' solo uno chiama il relativo comando 
//o builtin e crea UN solo FIGLIO e gli fa eseguire il processo e ne prende
//output dirigendolo su stdout  
//
//SE i processi sono concatenati, 
//crea piu figli e ne gesitsce l'iordine di concat in base a 
//come gli vengono passati dal parser
//GESTIONE DELL ORDINE DI ESECUZIONE
//

int		executor_handler(char **arguments) //o char ***arguments??
{
		if (strcmp(arguments[1], "cd") == 1)
			execute_builtin(arguments);
		else if (strcmp(arguments[1], "echo") == 1)
			execute_builtin(arguments);
		else if (strcmp(arguments[1], "pwd") == 1)
			execute_builtin(arguments);
		else if (strcmp(arguments[1], "unset") == 1)
			execute_builtin(arguments);
		else if (strcmp(arguments[1], "export") == 1)
			execute_builtin(arguments);
		else if (strcmp(arguments[1], "history") == 1)
			execute_builtin(arguments);
		else 
		{
			execute_command(arguments);
		}

}

void	execute_builtin(char **builtin)
{
		if (strcmp(arguments[1], "cd") == 1)
			cd(arguments);
		else if (strcmp(arguments[1], "echo") == 1)
			echo(arguments);
		else if (strcmp(arguments[1], "pwd") == 1)
			pwd(arguments);
		else if (strcmp(arguments[1], "unset") == 1)
			unset(arguments);
		else if (strcmp(arguments[1], "export") == 1)
			export(arguments);
		else if (strcmp(arguments[1], "history") == 1)
			history(arguments);
	//if else statement che decidono cosa eseguire di questo arg passato	
	//se builtin == echo 
	//	allora esegui echo()
	//	ecc ecc
}

void	execute_command(char *command, char *arg, char **PATH)
{


}

//processo unico 
//
//
//processo multiplo in ordine 
//
//














