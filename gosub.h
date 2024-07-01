#include <stdint.h>

void *(__gosub_stack[256]);
size_t __gosub_ptr = 0;

#define __gosub__create__label(label, linenum) label ## linenum
#define __gosub__create__label_2(label, linenum) __gosub__create__label(ret_label, linenum)

#define GOSUB(label) { __gosub_stack[__gosub_ptr++] = &&__gosub__create__label_2(ret_label, __LINE__); goto label; __gosub__create__label_2(ret_label, __LINE__): }
#define RETURN { void *ptr = (void*)__gosub_stack[--__gosub_ptr]; goto *ptr; }