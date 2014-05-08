/* Jonathan Piatos
** CMSI387: Operating Systems
** addressTranslation.c
*/

#include "addressTranslation.h"
#include <stdio.h>
#include <stdlib.h>

static pagetable *ptr = NULL; 

void setPageTable(pagetable *pt) {
    ptr = pt;
}

int getPhysical(int logical) {

	int leftBits = ((logical & PAGEMASK) >> PAGEBITS);
    // JD: Note how you don't need the "&" because you are shifting right.
	int rightBits = (logical & PAGESIZE);

    // JD: You can unhardcode the max check right here through
    //     proper usage of the #define's.
	if (logical < 0 || logical >= 256) {
        return ERR_OUT_OF_RANGE;
    }
   
	if (ptr[leftBits].valid == 0) {
		return ERR_INVALID;
    }

    return (((ptr[leftBits].frame) << PAGEBITS) + rightBits);

    // JD: So how is it that you have this nice, generally working version
    //     of the program side by side with a monolithic, broken version?
    //     If you eventually figured out multiple-file compilation, then
    //     you should have ditched the other program.
    //
    //     If you really had to go single-file, then you should have deleted
    //     all the other side files.
}