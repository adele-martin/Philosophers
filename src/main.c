/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:43:44 by ademarti          #+#    #+#             */
/*   Updated: 2024/10/21 12:37:42 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void monitor_philos(t_data *data)
{
	pthread_t	monitor;
	pthread_create(&monitor, NULL, monitoring, &data);
	pthread_join(monitor, NULL);
}

// TODO : create a mutex for the start time
int threading_philos(t_data *data)
{
	int i = 0;
	data->start_time = get_time();
	//Set time also for philosophers
	while (i < data->total_philo)
	{
	if (pthread_create(&data->p[i].thread, NULL, routine, &data->p[i]))
	{
		return exit_error("Thread creation failed\n");
	}
	i++;
	}
	i = 0;
 	while (i < data->total_philo)
 	{
		pthread_join(data->p[i].thread, NULL);
		i++;
	}
	return (1);
}

int parse_args(t_data *data, int argc, char **argv)
{
	// if (argc == 4)
	// {
	data->total_philo = 5;
	data->time_die = 800;
	data->time_eat = 200;
	data->time_sleep = 200;
	data->stop_simulation = 0;
	// data->total_philo = 2;
	// data->time_die = 800;
	// data->time_eat = 200;
	// data->time_sleep = 200;
	// data->stop_simulation = 0;
	// 4 410 200 200
	return (0);
	// }
	// else
	// 	return (1);
}

void free_all(t_data *data)
{
	int i;

	i = 0;
	while (i < data->total_philo)
	{
		free(data->p);
		i++;
	}
	free(data);
}

int main(int argc, char **argv)
{
	//make a monitor in a thread
	t_data *data;
	int i = 0;
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return exit_error("Error allocating memory for data\n");
	if (parse_args(data, argc, argv))
		return exit_error("Error. Invalid arguments\n");
	data_init(data, argv);
	threading_philos(data);
	monitor_philos(data);
	destroy_mutex(data);
	free_all(data);
}