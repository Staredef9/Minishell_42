#include "minishell.h"


//mi aspetto che la parte del retrieving degli argomenti venga gestita dal parser e lexer, 
//per cui imposto le funzioni di modo che ricevano gli argomenti gia' sistemati dalle precedenti.






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
