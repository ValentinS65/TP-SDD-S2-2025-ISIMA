#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char ** argv) {
	stack * s = stackCreate();
	if (stackIsEmpty(s)) {
		return 0;
	}
	else {
		return 1;
	}
}
