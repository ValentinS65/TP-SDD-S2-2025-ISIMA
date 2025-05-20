#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char ** argv) {
	stack * s = stackCreate();
	s = stackAdd(s, 23);
	if (stackTop(s)==23) {
		return 0;
	}
	else {
		return 1;
	}
}
