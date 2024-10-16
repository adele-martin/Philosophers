/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:27:16 by ademarti          #+#    #+#             */
/*   Updated: 2024/10/16 11:41:45 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int is_dead(t_philo *p)
{
	if (get_time() - p->last_meal > p->data->time_die)
	{
		message("has died", p);
		// return (1);
		exit(EXIT_FAILURE);
	}
	return 0;
}

//Look at who is grabbing the fork
int is_eating(t_philo *p)
{
	int i = 0;
	if (p->id % 2 == 0)
	{
    	pthread_mutex_lock(p->l_f);
		message("has taken the left fork", p);
    	pthread_mutex_lock(p->r_f);
		message("has taken the right fork", p);
	} else
	{
		pthread_mutex_lock(p->r_f);
		message("has taken the right fork", p);
		pthread_mutex_lock(p->l_f);
		message("has taken the left fork", p);
	}
	message("is eating", p);
	pthread_mutex_lock(&p->data->meal_lock);
	p->last_meal = get_time();
	pthread_mutex_unlock(&p->data->meal_lock);
	ft_usleep(p->data->time_eat);
	pthread_mutex_unlock(p->r_f);
	pthread_mutex_unlock(p->l_f);
	return 0;
}

int is_sleeping(t_philo *p)
{
	message("is sleeping", p);
	ft_usleep(p->data->time_sleep);
	return (0);
}

int is_thinking(t_philo *p)
{
	message("is thinking", p);
	return (0);
}