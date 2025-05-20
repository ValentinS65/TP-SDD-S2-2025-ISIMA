#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

int main(int argc, char ** argv) {
	hashtable * h = hashtableCreate();
	hashtableAdd(h, "Alice", "Dupont");
	hashtableAdd(h, "Bob", "Dupond");
	hashtableAdd(h, "Charles", "Dupon");
	hashtableAdd(h, "David", "Duppont");
	if (strcmp(hashtableSearch(h, "Alice"), "Dupont")==0) {
		return 0;
	}
	else {
		return 1;
	}
}
