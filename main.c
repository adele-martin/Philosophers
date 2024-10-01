/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:43:44 by ademarti          #+#    #+#             */
/*   Updated: 2024/10/01 13:38:24 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int arc, char **argv)
{
	int i = 0;
	t_arg args;
	t_philo philo;
	data_init(&args, &philo, argv);
	//pthread_create(&philo, NULL, init_philos, NULL);
	//sleep(6);
}