#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct object_item
{
	int i;
	struct list_link list;
} ObjectItem;

/**
 * Test list.h functions
 */
int list_test(){
	list test;

	ObjectItem elem1;
	ObjectItem elem2;

	elem1.i = 0;
	elem2.i = 1;

	INIT_LIST_HEAD(&test);
	if(test.first != 0 || test.last != 0){
		fprintf(stderr, "%s", "[FAIL] List init\n"); 
		exit(-1);
	}else{
		fprintf(stdout, "%s", "[OK] List init\n"); 
	}
	list_add(&elem1,&test,ObjectItem,list);

	if(test.first != &(elem1.list) || test.last != &(elem1.list) || test.first->next != 0){
		fprintf(stderr, "%s", "[FAIL] Add item 1 on list\n"); 
		exit(-1);
	}else{
		fprintf(stdout, "%s", "[OK] Add item 1 on list\n"); 
	}

	list_add(&elem2,&test,ObjectItem,list);

	if(test.first != &(elem1.list) || test.first->next !=&(elem2.list) || test.last != &(elem2.list) || test.first->next->next != 0){
		fprintf(stderr, "%s", "[FAIL] Add item 2\n"); 
		exit(-1);
	}else{
		fprintf(stdout, "%s", "[OK] Add item 2 on list\n"); 
	}

	return 0;
}

int main(){
	list_test();
	return 0;
}
