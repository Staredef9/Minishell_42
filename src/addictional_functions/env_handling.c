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

/*
void	ft_env_search(char *arg, t_data *data)
{
//TODO:implementare ricerca valore in variabili
//gestire sia ricerca di env senza che con $ sign.


}
*/






//Mette il caps lock ad una stringa
// static char	*ft_str_toup_case(char *str)
// {
// 	int		i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] >= 'a' && str[i] <= 'z')
// 		{
// 			str[i] = (str[i] - 'a') + 'A';
// 		}
// 		i++;
// 	}
// 	return (str);
// }
//Restituisce la stringa da aggiungere all'envp
char	*set_str_var(char *var_name, int value)
{
	char	*s_value;

	s_value = ft_itoa(value);
	var_name = ft_strjoin(var_name, "=");
	var_name = ft_strjoin(var_name, s_value);
	return (var_name);
}
//Stampa la matrice di char che gli viene passata (env copiata)
void	ft_print_env(char **matrix)
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
char	**add_var_to_env(char **envp, char *var)
{
	int		i;
	char	**new_env;

	i = 0;
	while (envp[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * i + 2);
	i = 0;
	while (envp[i])
	{
		new_env[i] = envp[i];
		i++;
	}
	new_env[i] = var;
	i++;
	new_env[i] = 0;
	return (new_env);
}
//Libera la matrice di char
void 	free_matrix(char **src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}
