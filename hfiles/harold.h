#ifndef HAROLD_H
#define HAROLD_H

#include "items.h"

void harold_clear_inventory(void);

void harold_load_inventory(void);

void harold_save_inventory(void);

void harold_add_inventory(struct Item new_item);

// debug

void harold_print_inventory(void);

#endif // !HAROLD_H
