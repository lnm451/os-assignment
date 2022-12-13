#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	if(q->size < MAX_QUEUE_SIZE){
		q->proc[q->size] = proc;
		q->size += 1;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	struct pcb_t* proc = NULL;
	if(!empty(q)){
		uint32_t max_prio = 0;
		int pos = 0;
		for(int i = 0; i<q->size; i++){
			if(q->proc[i]->priority > max_prio){
				max_prio = q->proc[i]->priority;
				pos = i;
			}
		}
		proc = q->proc[pos];
		q->size -= 1;
		for(int i = pos; i < q->size; i++){
			q->proc[i] = q->proc[i+1];
		}
		q->proc[q->size] = NULL;
	}
	return proc;
}
