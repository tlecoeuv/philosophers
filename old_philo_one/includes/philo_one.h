#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdint.h>

typedef struct	s_philo
{
	int					id;
	int					nb_meal;
	struct timeval		last_meal;
	pthread_t			th;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}				t_philo;

typedef struct	s_simulation
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_must_eat;
	struct timeval		start_time;
	t_philo				**philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		waiter;
	pthread_mutex_t		mutex_print;
	int					running;
}				t_simulation;

//utils:

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isnumber(char *str);
void		ms_sleep(uint64_t t_ms);
uint64_t	get_ms_since(struct timeval time);

//simulation:

void		create_simulation(void);
void		run_simulation(void);
void		delete_simulation(void);

//philos:

void		*run_philo(void *philo_ptr);
void		print_action(t_philo *philo, char *action);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_eat(t_philo *philo);


extern		t_simulation	g_simu;

#endif
