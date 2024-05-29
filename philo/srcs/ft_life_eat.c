/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:47:44 by agiraud           #+#    #+#             */
/*   Updated: 2022/03/30 12:38:27 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//free les mallocs 

void	ft_free_data(t_data *data)
{
	free(data->death);
	free(data->forks);
	free(data->print);
}

//Met le parametre stop a 1 a tous les philosophes suivant 
//Celui qui est mort ou qui a fini de manger

static void	ft_stop(t_philo *p, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		p[i].stop = 1;
		i++;
	}
}

//Check si il a atteint le nombre max de fois ou il devait manger

int	ft_check_num_eat(t_philo *philo, int num_of_philo, int num_eat)
{
	int	i;

	i = 0;
	while (num_eat > 0 && philo[i].num_eat >= num_eat)
	{
		if (i == num_of_philo - 1)
		{
			ft_stop(philo, num_of_philo);
			return (1);
		}
		i++;
	}
	return (0);
}

//Check si le philosophe est en vie

int	ft_check_is_life(t_philo *p, int num_of_philo, int time_to_die)
{
	int		i;

	i = 0;
	while (i < num_of_philo)
	{
		pthread_mutex_lock(p->death);
		if (ft_time() - p[i].last_eat >= time_to_die)
		{
			ft_stop(p, num_of_philo);
			printf("%ld %d died\n", ft_time() - p[i].start, p[i].pos);
			pthread_mutex_unlock(p->death);
			return (1);
		}
		pthread_mutex_unlock(p->death);
		i++;
		usleep(1);
	}
	return (0);
}

//Verifie si le philosophe est en vie et le nombre de fois qu'il a mangé

void	ft_life_eat(t_philo *philo, t_data *data)
{
	while (1)
	{
		if (ft_check_is_life(philo, data->num_of_philo, data->time_to_die))
			return ;
		if (ft_check_num_eat(philo, data->num_of_philo, data->num_eat))
			return ;
		usleep(1);
	}
}
