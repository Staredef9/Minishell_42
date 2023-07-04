#include "../executor/minishell.h"

//qui dobbiamo gestire con grande attenzione il parsing delle stringhe 
//che vengono passate da riga di comando 

//DEVO GESTIRE IL CONTROLLO DEI PIPE PRIMA DI CHIAMARE IL PARSER 
int	is_piped(char *arg_line)
{
	int counter;

	counter = 0;
	while(*arg_line)
	{
		if (*arg_line == '|')
			counter++;
		*arg_line++;
	}
	return (counter);
}


int	input_init(t_input *input, int counter)
{
	
}


//PER GIUNTA dobbiamo anche tenere ordine di esecuzione come 
//PRIMO NODO --> ULTIMO comando
//secondo nodo --> comando PRECEDENTE
//....ecc
//ultimo nodo --> PRIMO comando
//
//esecuzione a ritroso

int	parser(char *arg_line, t_input *input)
{

	int		i;
	int		counter;
	char	**tokens 

	counter = 0;


	/*
	if ((counter = (is_piped(arg_line))) != 0)
	{
		//fai infrastruttura per avere piu nodi 
		// uno per ogni pipe
	}*/

	tokens = ft_tokenize(arg_line);
	i = 0;
	while (tokens[i])
	{
		if //e' un comando 
			input->cmd_opt[i] = tokens[i]
		else if //(e' una redirection di input od output)
			input->IO[i] = tokens[i]
		else if 

		else 
			free(tokens);
			return(1);
	}
	free(tokens);
	return(0);

}

//crea una matrice di stringhe ben divise in base ai segni trovati 
//nella stringa passata
/*
char **tokenize(char *arg_line)
{
	char **tokenizer;
	int counter;
	int i;
	int j;
	int pipe;

	i = 0;
	j = 0;
	counter = 0;
	pipe = 0;
	if ((pipe = is_piped(arg_line)) != 0)
	{
	//se sono qua significa che so quante diverse righe creare 
	//se PIPE == 3 devo contare lo strlen di 3 stringhe diverse 
		while (counter < pipe)
			while(arg_line[i] != '|')
			{
				counter++;
				i++;
			}
	}

	//conteggio di quanto deve essere grande la matrice da rimandare indietro
	while(arg_line[i])
	{
		if (arg_line[i] == ' ' || arg_line[i] == ';') //altri da includere
			counter++;
		i++;
	}
	tokenizer = malloc(counter * sizeof(char *));
	i = 0;
	

	//allocare ogni riga in base a quanti caratteri prima di ogni segno flag + 1
	while(i < counter)
	{
		
	}
	return tokenizer;
}
*/






//
//
//
//
//
//   '|'
//   '>'
//   '<'
//
//   i comandi :: 
//   ls, cat ecc, che sono nella var $PATH
//
//   da gestire anche i file, come si possono riconoscere in quanto tali?
//   Gestire la logica di apertura e creazione dei file dove??
//   in che punto del codice e dell'architettura?
//
//
