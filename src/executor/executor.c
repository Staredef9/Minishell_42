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



void	execute_builtin(char *builtin)
{

	//if else statement che decidono cosa eseguire di questo arg passato	
	//se builtin == echo 
	//	allora esegui echo()
	//	ecc ecc
}

void	execute_command(char *commandi, char *arg, char **PATH)
{


}

//processo unico 
//
//
//processo multiplo in ordine 
//
//














