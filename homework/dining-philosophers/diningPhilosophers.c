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


/**
 *	Main method to create all of the threads and run them.
 */

int main () {

	/* Reusable i and our threads. */
	int i;
	pthread_t philosphers[NUM];

	/* Let us initialize the mutexes. */
	for (i = 0; i < NUM; i++) {
		philosopher_state[i] = THINKING;
		philosopher_number[i] = i;
		chopstick_state[i] = 0;
		pthread_mutex_init(&chopsticks[i], NULL);
		pthread_create(&philosphers[i], NULL, philosophize, &philosopher_number[i]);
	}

	/* Let us join the threads, even though we never get here. */
	for (i = 0; i < NUM; i++) {
		pthread_join(philosphers[i], NULL);
	}

	/* We shouldn't ever get here, but let us make the compiler happy. */
	return 0;

}
