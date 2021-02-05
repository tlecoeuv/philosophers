#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdint.h>
# include <semaphore.h>

typedef struct			s_philo
{
	int					id;
	pthread_t			th;
	struct timeval		last_meal;
	int					nb_meal;
}						t_philo;

typedef struct			s_data
{
	int					nb_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_must_eat;
	struct timeval		start_time;
	pthread_mutex_t		waiter;
	pthread_mutex_t		mutex_print;
	sem_t				forks;
	int					running;
}						t_data;

//utils:

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isnumber(char *str);
void		ms_sleep(uint64_t t_ms);
uint64_t	get_ms_since(struct timeval time);



//philos:

int			init_forks(t_philo **philos);
t_philo		*init_philo(int id);
t_philo		**init_philos(void);

void		run_philos(t_philo **philos);

void		print_action(t_philo *philo, char *action);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_eat(t_philo *philo);

extern	t_data		g_data;

#endif
