/**
 * Implementation of the software paging unit.
 */
#include "addressTranslation.h"
#include <stdio.h>
#include <stdlib.h>

static pagetable *ptr = NULL; // ptr = "page table register"

void setPageTable(pagetable *pt) {
    ptr = pt;
}

int getPhysical(int logical) {

	int leftBits = ((logical & PAGEMASK) >> PAGEBITS);
	int rightBits = (logical & PAGESIZE);

    return (((ptr[leftBits].frame) << PAGEBITS) + rightBits);

}