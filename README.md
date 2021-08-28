# Libtest

A simple unitary test lib.

## Installation

```
make deploy
```

## Run libtest tests

```
make run
```

## Usage 

Usage on your program :

```
#include <libtest.h>
```

## Example

```
    #include "test.h"

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

    int main(){
        TestGroup group;
		Test * failedTest; 
		INIT_GROUP(group);
			
		Test t1,t2,t3,t4;
		t1.func = test1;
		t2.func = test2;
		t3.func = test3;
		t4.func = test4;

		ADD_TEST(&t1,group);
		ADD_TEST(&t2,group);
		ADD_TEST(&t3,group);
		ADD_TEST(&t4,group);

		failedTest = RUN_TEST(group);

        if(failedTest == 0){
            return -1;
        }else{
            return 0;
        }
    }
```
