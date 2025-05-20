#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(int argc, char ** argv) {
	hashtable * h = hashtableCreate(10);
	hashtableAdd(h, "Alice", "Dupont");
	return 0;
}
