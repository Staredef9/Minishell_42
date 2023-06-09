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

//TODO:implementare ricerca valore in variabili
//gestire sia ricerca di env senza che con $ sign.

//Restituisce 1 se la variabile esiste, 0 se non esiste
int	ft_env_search(char *arg, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], arg, ft_strlen(arg)) == 0)
			return (1);
		i++;
	}
	return (0);
}
//Stampa la matrice di char che gli viene passata (env copiata)
void	ft_print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_printf("%s\n", matrix[i]);
		i++;
	}
}
//Crea una copia della matrice di char che gli viene passata (env)
char	**copy_char_matrix(char **src)
{
	char	**copy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (src[i])
	{
		copy[i] = ft_strdup(src[i]);
		i++;
	}
	copy[i] = 0;
	return (copy);
}
//Prende il vecchio envp e la stringa con nome_variabile=valore
//Restituisce il nuovo envp con la nuova variabile
char	**add_var_to_env(t_data *data, char *var)
{
	int		i;
	char	**new_env;

	i = 0;
	while (data->envp[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (data->envp[i])
	{
		new_env[i] = ft_strdup(data->envp[i]);
		i++;
	}
	free_matrix(data->envp);
	new_env[i] = ft_strdup(var);
	i++;
	new_env[i] = 0;
	return (new_env);
}

void	change_var_env(t_data *data, char *var, char *full_var)
{
	int	i;
	int	line;

	i = 0;
	line = var_line(var, data->envp);
	while (data->envp[i])
	{
		if (i == line)
		{
			free(data->envp[i]);
			data->envp[i] = ft_strdup(full_var);
		}
		i++;
	}
}
