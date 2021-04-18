#include "seahorn/seahorn.h"
#include "uthash.h"

/*size_t strlen(const char *s) {
    size_t ret = 0;

    while(*(s+ret) != '\0')
        ret++;

    return ret;
}*/

typedef struct {
        int id;
        char name[10];
        UT_hash_handle hh;
} my_struct;

my_struct *users = NULL;    /* important! initialize to NULL */

my_struct *add_user(int user_id, char *name) {
    my_struct *s;

    s = malloc(sizeof(my_struct));
    s->id = user_id;
    strcpy(s->name, name);
    HASH_ADD_STR(users, name, s);  /* id: name of key field */
    return s;
}

extern unsigned int dummy__unsigned_int();
extern char dummy_char();

int main(void) {
        sassert(users == NULL);
        sassert(HASH_COUNT(users) == 0);

        char name[5] = "test";

        my_struct *in = add_user(10, name);
        sassert(users != NULL);

        //sassert(HASH_COUNT(users) == 1);

        my_struct *out;

#ifdef FAIL
	sassert(0);
#endif

        HASH_FIND_STR(users, name, out);
        sassert(out != NULL);
        sassert(in == out);

#ifdef FAIL
	sassert(0);
#endif


        return 0;
}
