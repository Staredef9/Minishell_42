#include "../executor/minishell.h"

// in questo modulo andiamo a gestire la creazione di nuove variabili ambientali 
// ogni volta che viene ricevuto dal parser un valore maiuscolo con un 
// uguale di seguito, l'éxecutor lo vede e deve invocare queste funzioni per 
// mettere nella tabella delle variabili ambientali questa nuova entry
//
// se invece la stessa variabile e' chiamata col dollaro davanti, 
// deve aprire il path relativo e mostrare il contenuto 
//
// questo deve accadere anche con le variabili ambientali gia esistenti nel sistema
// di fatto serve di fare un parsing delle envp in una struttura o lista, e aggiungere le nuove alla bisogna
// quando si vede il dollaro si fa un parsing che si deve recuperare
// quel valore dopo il dollaro e restituire il contenuto a schermo 
//
//
//

//Stampa la matrice di char che gli viene passata (env copiata)
void	ft_print_env(char	**matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_printf("%s\n", matrix[i]);
		i++;
	}
	//return (0);
}
//Crea una copia della matrice di char che gli viene passata (env)
char	**copy_char_matrix(char **src)
{
	char	**copy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	copy = (char **)malloc(sizeof(char) * i + 1);
	i = 0;
	while (src[i])
	{
		copy[i] = ft_strdup(src[i]);
		ft_printf("%s\n", copy[i]);
		i++;
	}
	src[i] = '\0';
	ft_printf("FINISH COPY\n");
	ft_printf("FINISH COPY\n");
	ft_printf("FINISH COPY\n");
	return (copy);
}

void 	free_matrix(char **src)
{
	int		i;

	while (src[i++])
	{
		free(src[i]);
	}
}
