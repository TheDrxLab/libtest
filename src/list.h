#ifndef LIBTEST_LIST
#define LIBTEST_LIST

typedef struct{
	struct list_link *last;
	struct list_link *first;
} list;

typedef struct list_link {
	struct list_link *next;
} link;

/**
 * Init list
 **/
#define INIT_LIST_HEAD(ptr) do { list *__l = (ptr); __l->last = 0; __l->first = 0;} while (0)

/**
 * Add item on specified list
 */
#define list_add(ptr_elem, head, type, listfield)\
	do {\
		list *__cur_list=head;\
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

#endif