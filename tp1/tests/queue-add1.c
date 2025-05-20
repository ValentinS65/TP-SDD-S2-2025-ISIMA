#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char ** argv) {
	queue * q = queueCreate();
	queueAdd(q, 21);
	if (!queueIsEmpty(q)) {
		return 0;
	}
	else {
		return 1;
	}
}
