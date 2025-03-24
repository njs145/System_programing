#ifndef __FILE_OPEN__H__
#define __FILE_OPEN__H__

#include "/usr/aarch64-linux-gnu/include/stdio.h"
#include <string.h>

typedef struct person_info
{
    char name[128];
    __uint8_t age;
}user_info_t;

extern int file_open_main(void);
#endif  //!__FILE_OPEN__H__