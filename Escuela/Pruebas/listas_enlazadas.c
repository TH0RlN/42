/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listas_enlazadas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 12:02:54 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/24 12:42:47 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct nodo
{
	char *nombre;
	struct nodo *sig;	
}libro;

libro	*listaLibro(libro *lista)
{
	lista = NULL;
	return (lista);
}

libro	*addLibro(libro *lista, char *nombre)
{
	libro *newLibro;
	libro *aux;
	newLibro = (libro *)malloc(sizeof(libro));
	newLibro -> nombre = nombre;
	newLibro -> sig = NULL;
	if (lista == NULL)
		lista = newLibro;
	else
	{
		aux = lista;
		while (aux -> sig != NULL)
			aux = aux -> sig;
		aux -> sig = newLibro;
	}
	return (lista);	
}

int main()
{
	libro *lista = listaLibro(lista);
	int i = 0;

	while (i < 11986)
	{
		lista = addLibro(lista, ft_itoa(i));
		i++;
	}
	while (lista != NULL)
	{
		printf("%s\n", lista -> nombre);
		lista = lista -> sig;
	}
	return (0);
}