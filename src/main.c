#include <stdio.h>
#include <stdlib.h>
#include "test.h"

typedef struct object_item
{
	int i;
	struct list_link link;
} ObjectItem;

/**
 * Test list.h functions
 */
int list_test(){
	lifo list;

	ObjectItem elem1;
	ObjectItem elem2;

	elem1.i = 0;
	elem2.i = 1;

	INIT_LIST_HEAD(&list);
	if(list.first != 0 || list.last != 0){
		fprintf(stderr, "%s", "[FAIL] List init\n"); 
		exit(-1);
	}else{
		fprintf(stdout, "%s", "[OK] List init\n"); 
	}
	lifo_add(&elem1,&list,ObjectItem,link);

	if(list.first != &(elem1.link) || list.last != &(elem1.link) || list.first->next != 0){
		fprintf(stderr, "%s", "[FAIL] Add item 1 on list\n"); 
		exit(-1);
	}else{
		fprintf(stdout, "%s", "[OK] Add item 1 on list\n"); 
	}

	lifo_add(&elem2,&list,ObjectItem,link);

	if(list.first != &(elem1.link) || list.first->next !=&(elem2.link) || list.last != &(elem2.link) || list.first->next->next != 0){
		fprintf(stderr, "%s", "[FAIL] Add item 2\n"); 
		exit(-1);
	}else{
		fprintf(stdout, "%s", "[OK] Add item 2 on list\n"); 
	}
	ObjectItem * cursor;
	int counter = 0;

	lifo_for_each(cursor,&list,ObjectItem,link){
		if(cursor->i != counter ++){
			fprintf(stderr, "%s", "[FAIL] foreach\n");
			exit(-1); 
		}
	}
	fprintf(stderr, "%s", "[OK] foreach\n");
	return 0;
}

	int test1(){
		return TEST_OK;
	}
	int test2(){
		return TEST_OK;
	}
	int test3(){
		return TEST_ERROR;
	}
	int test4(){
		return TEST_OK;
	}

	/**
	 * Test "test" tools
	 */
	int test_test(){
		TestList test;
		Test * failedTest; 
		INIT_LIST_TEST(&test);
			
		Test t1,t2,t3,t4;
		t1.func = test1;
		t2.func = test2;
		t3.func = test3;
		t4.func = test4;

		ADD_TEST(&t1,&test);
		failedTest = RUN_TEST(&test);
		
		if(failedTest != 0){
			fprintf(stderr, "%s", "[FAIL] All test OK 1\n");
		}else{
			fprintf(stdout, "%s", "[OK] All test OK 1\n"); 
		}
		
		ADD_TEST(&t2,&test);
		failedTest = RUN_TEST(&test);
		
		if(failedTest != 0){
			fprintf(stderr, "%s", "[FAIL] All test OK 2\n");
		}else{
			fprintf(stdout, "%s", "[OK] All test OK 2\n"); 
		}
		
		ADD_TEST(&t3,&test);
		
		failedTest = RUN_TEST(&test);
		
		if(failedTest != &t3){
			fprintf(stderr, "%s", "[FAIL] test failure\n");
		}else{
			fprintf(stdout, "%s", "[OK] test failure\n"); 
		}
		ADD_TEST(&t4,&test);

		failedTest = RUN_TEST(&test);
		
		if(failedTest != &t3){
			fprintf(stderr, "%s", "[FAIL] premature end\n");
		}else{
			fprintf(stdout, "%s", "[OK] premature end\n"); 
		}
		return 0;
	}

int main(){
	list_test();
	test_test();
}
