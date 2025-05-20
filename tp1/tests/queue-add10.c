#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char ** argv) {
	int i;
	queue * q = queueCreate();
	for (i=0; i<10; i++) {
		queueAdd(q, i+1);
	}
	return 0;
}
