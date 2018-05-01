#include <string>
using namespace std;

struct str_t;
struct set_of_str_t;
struct iterator_t;
set_of_str_t * create_set_of_str();
set_of_str_t * union_(set_of_str_t*, set_of_str_t*);
set_of_str_t * intersection(set_of_str_t *, set_of_str_t *);
void print_list(set_of_str_t*);
bool is_empty(set_of_str_t*);
bool contains_item(set_of_str_t *, string);
void add_item(set_of_str_t * &name, string);
void del_item(set_of_str_t * &name, string);
void destroy_set_of_str(set_of_str_t* &name);
iterator_t * create_iterator(set_of_str_t *);
str_t * getFirst();
str_t * getNext();
str_t * hasMore();