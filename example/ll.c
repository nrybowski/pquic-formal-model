#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

#ifdef CHECK
#include "seahorn/seahorn.h"
extern unsigned int nd();
#endif

typedef struct st_my_struct {
        struct st_my_struct *next;
        uint8_t value;
} my_struct;

my_struct* init(uint8_t value) {
        my_struct* s = (my_struct*) malloc(sizeof(my_struct));
        if (s != NULL) {
                s->next = NULL;
                s->value = value;
        }
        return s;
}

void free_all(my_struct *head) {
        my_struct *runner = head, *tmp;
        while (runner != NULL) {
                printf("value %u\n", runner->value);
                tmp = runner;
                runner = runner->next;
                free(tmp);
        }
        printf("\n");
}

my_struct *init_list(unsigned int size) {
        unsigned int i = 0;

        my_struct *runner = init(i++), *head;
        if (runner == NULL)
                return NULL;
        head = runner;
        
        while(i<size) {
                runner->next = init(i++);
                if (runner->next == NULL) {
                        free_all(head);
                        return NULL;
                }
                runner = runner->next;
        }

        return head;
}

my_struct *duplicate(my_struct *s) {
        my_struct *head, *tmp, *prev;
        for (my_struct *runner = s; runner != NULL; runner=runner->next) {
                tmp = init(runner->value);
                if (runner == s) {
                        head = tmp;
                        prev = head;
                } else {
                        prev->next = tmp;
                        prev = prev->next;
                }
                if (tmp == NULL){
                        free_all(head);
                        return NULL;
                }
        }

        return head;
}

void compare(my_struct *s1, my_struct *s2) {
        my_struct *runner1 = s1, *runner2 = s2;
        unsigned int cond = 1;

        while(runner1 != NULL && runner2 != NULL) {
                cond &= runner1->value == runner2->value;
                runner1 = runner1->next;
                runner2 = runner2->next;
        }

        // not same size
        if (runner2 != NULL || runner1 != NULL)
                cond = 0;

#ifdef CHECK
        sassert(cond);
#else
        printf("cond %u\n", cond);
#endif
}

/*
 * This test should unsat since we compare a ll to its exact copy
 */
void test1(my_struct *original, unsigned int size) {
        my_struct *head = duplicate(original), 
                  *copy = duplicate(head);

        compare(head, copy);

        free_all(head);
        free_all(copy);
}

/*
 * This test should sat since the original ll is modified
 */
void test2(my_struct *original, unsigned int size) {
        unsigned int id, i = 0;
#ifdef CHECK
        id = nd();
        assume(id < size);
#else
        id = 6;
#endif

        my_struct *head = duplicate(original), 
                  *runner = head, 
                  *copy = duplicate(head);

        compare(head, copy);

        while(i++<id)
                runner = runner->next;
        runner->value++;
        
        compare(head, copy);

        free_all(head);
        free_all(copy);
}

int main(void) {
        unsigned int size;
#ifdef CHECK
        size = nd();
#else
        size = 10;
#endif
        my_struct *head = init_list(size);

#if TEST == 1
        test1(head, size);
#elif TEST == 2
        test2(head, size);
#endif

        free_all(head);

        return 0;
}
