/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:47:34 by agiraud           #+#    #+#             */
/*   Updated: 2022/03/26 21:47:36 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Affiche l'etat de chaque philosophe a l'instant t
//Protege par une mutex pour eviter les superpositions de messages

void	ft_print(char *str, t_philo *p)
{
	pthread_mutex_lock(p->print);
	if (p->stop)
	{
		pthread_mutex_unlock(p->print);
		return ;
	}
	printf("%lu %d %s\n", ft_time() - p->start, p->pos, str);
	pthread_mutex_unlock(p->print);
}
