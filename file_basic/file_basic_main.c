#include "file_open.h"
#include "file_seek.h"
#include "open.h"

int file_basic(void)
{
    int err;
    err = open_main();
    return err;
}