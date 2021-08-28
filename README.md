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
		return 0;
	}
	int test2(){
		return 0;
	}
	int test3(){
		return -1;
	}
	int test4(){
		return 0;
	}

    int main(){
        TestList test;
		Test * failedTest; 
		INIT_LIST_TEST(&test);
			
		Test t1,t2,t3,t4;
		t1.func = test1;
		t2.func = test2;
		t3.func = test3;
		t4.func = test4;

		ADD_TEST(&t1,&test);
		ADD_TEST(&t2,&test);
		ADD_TEST(&t3,&test);
		ADD_TEST(&t4,&test);

		failedTest = RUN_TEST(&test);

        if(failedTest == 0){
            return -1;
        }else{
            return 0;
        }
    }
```

To compile in test mode add **CFLAG** **-DTEST_MODE**.
