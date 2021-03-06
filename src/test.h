#ifndef LIBTEST
#define LIBTEST
        #define TEST_OK 0
        #define TEST_ERROR -1
        typedef struct{
            struct list_link *last;
            struct list_link *first;
        } lifo;

        typedef struct list_link {
            struct list_link *next;
        } link;

        /**
         * Init List
         **/
        #define INIT_LIST_HEAD(ptr) do { lifo *__l = (ptr); __l->last = 0; __l->first = 0;} while (0)

        /**
         * Add item on specified list
         */
        #define lifo_add(ptr_elem, head, type, listfield)\
            do {\
                lifo *__cur_list=head;\
                type *__elem = (ptr_elem);\
                link *__elem_link=&((__elem)->listfield);\
                __elem_link->next = 0;\
                if(__cur_list->last == 0){\
                    __cur_list->last = __elem_link;\
                    __cur_list->first = __elem_link;\
                }else{\
                    __cur_list->last->next = __elem_link;\
                    __cur_list->last = __elem_link;\
                }\
            } while (0)

        #define lifo_entry(ptr, type, listfield) \
            ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->listfield)))

        #define lifo_for_each(ptr, head, type, listfield)\
            for(ptr = lifo_entry((head)->first,type,listfield);\
                    &ptr->listfield != 0;                                 \
                    ptr = lifo_entry(ptr->listfield.next,type,listfield))

        typedef struct{
            int (*func)();
            link link;
        } Test;
        
        typedef struct{
            lifo list;
        } TestGroup;

        typedef enum{
            GROUP,
            TEST
        } TestGroupUnionType;

        typedef union __test_group_union
        {
            TestGroupUnionType type;
            TestGroup group;
            Test test;
        } TestGroupUnion;
        
        typedef lifo TestList;

        /**
         * Init test list
         */
        #define INIT_GROUP(ptr) INIT_LIST_HEAD(&ptr.list)
        
        /**
         * Add test on specified test list
         */
        #define ADD_TEST(ptr_test,group) lifo_add(ptr_test, &group.list, Test, link)

        /**
         * Run all tests in list
         */
        #define RUN_TEST(group) __run_test(&group.list)

        /**
         * Internal function used by previous macro
         */
        static __inline__ Test *__run_test(TestList *list)
        {
            Test * cursor;
        	lifo_for_each(cursor,list,Test,link){
                if(cursor->func() < 0){
                    return cursor;
                }
            }
            return 0;
        }
#endif