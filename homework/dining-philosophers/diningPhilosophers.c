/* Jonathan Piatos
** CMSI387: Operating Systems
** Dining Philosophers
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define NUM 5
#define TRUEVALUE 1
#define HUNGRY 0
#define EATING 1
#define THINKING 2 

int philosopher_number[NUM];
int philosopher_state[NUM];
int chopstick_state[NUM];
pthread_mutex_t chopsticks[NUM];

void philosopherActions () {
	int i;

	for (i = 0; i < NUM; i++) {
		if (philosopher_state[i] == THINKING) {
			printf(" Philosopher is Thinking ");
			printf("\n");
		} else if (philosopher_state[i] == HUNGRY) {
			printf(" Philosopher is Hungry ");
			printf("\n");
		} else if (philosopher_state[i] == EATING) {
			printf(" Philosopher is Eating ");
			printf("\n");
		}
	}
}

/*
 * Used from Bazaar - utility.c
 * 
 */

int randomWait(int bound) {
    int wait = rand() % bound;
    sleep(wait);
    return wait;
}

void getChopstick (int chopstick) {
	pthread_mutex_lock(&chopsticks[chopstick]);
	chopstick_state[chopstick] += 1;
}

void releaseChopstick (int chopstick) {
	pthread_mutex_unlock(&chopsticks[chopstick]);
	chopstick_state[chopstick] -= 1;
}

void thinkTime (int philosopher) {
	randomWait(5);
	philosopher_state[philosopher] = HUNGRY;
}

void eating (int philosopher) {
	getChopstick(philosopher);
	getChopstick((philosopher + 1) % NUM);
	philosopher_state[philosopher] = EATING;
	randomWait(5);
}

void finishedEating (int philosopher) {
	releaseChopstick(philosopher);
	releaseChopstick((philosopher + 1) % NUM);
	philosopher_state[philosopher] = THINKING;
}


void* philosophize (void* philosopher) {
	int id = *(int*) philosopher;
	philosopherActions();
	while (TRUEVALUE) {
			philosopherActions();

		if (philosopher_state[id] == THINKING) {
			thinkTime(id);
		} else if (philosopher_state[id] == HUNGRY) {
			eating(id);
		} else if (philosopher_state[id] == EATING) {
			finishedEating(id);
		}
	}
}


/*
 *	Main method to create all of the threads and run them.
 */

int main () {

	int i;
	pthread_t philosphers[NUM];

	for (i = 0; i < NUM; i++) {
		philosopher_state[i] = THINKING;
		philosopher_number[i] = i;
		chopstick_state[i] = 0;
		pthread_mutex_init(&chopsticks[i], NULL);
		pthread_create(&philosphers[i], NULL, philosophize, &philosopher_number[i]);
	}

	for (i = 0; i < NUM; i++) {
		pthread_join(philosphers[i], NULL);
	}

	return 0;

}
