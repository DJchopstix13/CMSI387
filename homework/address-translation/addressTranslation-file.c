/**
 * Implementation of the software paging unit.
 */
#include <stdio.h>
#include <stdlib.h>
 
#include <assert.h>

/**
 * Interface for working with the software paging unit.
 */
#ifndef __ADDRESS_TRANSLATION__
#define __ADDRESS_TRANSLATION__

/**
 * The size of a page or frame, represented as a bit field.
 */
#define PAGESIZE 0xf

/**
 * The number of bits occupied by the displacement; this should be the
 * same as the number of set bits in PAGESIZE.
 */
#define PAGEBITS 4

/**
 * The total number of available pages --- this corresponds to a process's
 * overall address space.
 */
#define PAGECOUNT 16

/**
 * Bit mask that separates the page from the displacement.
 */
#define PAGEMASK 0xf0

/**
 * Definition of an individual page table entry.
 */
typedef struct {
    int frame;
    int valid; // In practice, just a single bit!
} pagetable;

/**
 * Error constant for an out-of-range address.
 */
#define ERR_OUT_OF_RANGE -1

/**
 * Error constant for an invalid address.
 */
#define ERR_INVALID -2

/**
 * Sets a pointer to the current page table.
 */
void setPageTable(pagetable *pt);

/**
 * Translates the given logical address to the corresponding physical address.
 * Returns < 0 if there was a problem with the address.
 */
int getPhysical(int logical);

#endif

static pagetable *ptr = NULL; // ptr = "page table register"

void setPageTable(pagetable *pt) {
    ptr = pt;
}

int getPhysical(int logical) {

	int leftBits = ((logical & PAGEMASK) >> PAGEBITS);
	int rightBits = (logical & PAGESIZE);

    return (((ptr[leftBits].frame) << PAGEBITS) + rightBits);

}


int main(int argc, char *argv[]) {
    // Sample page table.
    pagetable pt[] = {
        {  4, 1 }, // { frame, valid }
        {  2, 1 },
        {  9, 1 },
        { 10, 1 },
        {  0, 1 },
        { 14, 1 },
        { 12, 0 },
        {  6, 1 },
        {  1, 1 },
        {  3, 0 },
        { 13, 1 },
        {  8, 1 },
        {  7, 1 },
        { 11, 1 },
        { 15, 1 },
        {  5, 0 } // Should be PAGECOUNT members.
    };
    setPageTable(pt);

    // Tests...feel free to add more!
    assert(getPhysical(-1) == ERR_OUT_OF_RANGE);
    assert(getPhysical(5) == 69);
    assert(getPhysical(13) == 77);
    assert(getPhysical(24) == 40);
    assert(getPhysical(31) == 47);
    assert(getPhysical(52) == 164);
    assert(getPhysical(72) == 8);
    assert(getPhysical(90) == 234);
    assert(getPhysical(98) == ERR_INVALID);
    assert(getPhysical(104) == ERR_INVALID);
    assert(getPhysical(128) == 16);
    assert(getPhysical(150) == ERR_INVALID);
    assert(getPhysical(179) == 131);
    assert(getPhysical(181) == 133);
    assert(getPhysical(199) == 119);
    assert(getPhysical(218) == 186);
    assert(getPhysical(239) == 255);
    assert(getPhysical(240) == ERR_INVALID);
    assert(getPhysical(249) == ERR_INVALID);
    assert(getPhysical(256) == ERR_OUT_OF_RANGE);
}