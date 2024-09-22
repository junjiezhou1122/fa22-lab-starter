#include <stdbool.h>
#include "ll_cycle.h"
#include <stdio.h>
bool ll_has_cycle(node *head) {
    if (head == NULL) {
        return false;
    }

    node *slow_ptr = head;
    node *fast_ptr = head;

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr) {
            return true;
        }
    }

    return false;
}
