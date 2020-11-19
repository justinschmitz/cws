#include <stdio.h>


/*
  Find the missing number in an array from 1 to 10
*/

typedef unsigned int index_t;

int main (void) {


    int source_index_array[10] = { 3, 0, 1, 7, 9, 2, 4, 6, 5, 10 };    
    int target_index_array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0,  0 };

    // loop through the source_index_array and use value at index as
    // lookup key for the target_index_array
    // if the value at index in the source_index_array is equal to zero
    // then continue
    // if the value at index in the target_index_array is equal to zero
    // then set the value at index to 1 to indicate it has been found


    for (index_t idx = 0; idx < 10; idx++)
    {
	valatidx = source_index_array[idx];
	
	if (valatidx <= 0)
	    continue;
	
	if (valatidx > 10)
	    break;
	
	if (target_index_array[valatidx-1] == 0)
	    target_index_array[valatidx-1]  = 1;
    }

    for (index_t idx = 0; idx < 10; idx++)
	if (target_index_array[idx] == 0) {
	    printf("missing %d\n", idx+1);
	    break;
	}

    return 0;
}
