#include "msort.h"
#include "student.h"
#include <stdio.h>

#ifndef OMIT_MSORT
void msort(Student * base, int nel, int (*compar)(const void *, const void *)) {
	
	//Base case: if the array has one or fewer elements, it's already sorted
	//so just return.
	if (nel <= 1)
		return;
	//FILL IN
	
	//Inductive case: split the array in two, sort the two pieces with msort,
	//merge the	sorted pieces
		
	//We're going to do this without explicitly creating the two separate arrays
	//We'll take advantage of the fact that to C, an array is just a pointer to
	//a region of memory. If we call msort on base, but pass in a smaller number
	//of elements, it will sort just that subarray. Similarly, if we call msort
	//but pass in the address of an element in the middle of the array, it will
	//sort the array *starting* from that element.
		
	//1. Find the midpoint of the array
	mid = (nel-1) / 2;
	
	//2a. Sort the first half of the array (remember to adjust the # elements)
	msort( base, mid, (*compar)(const void *, const void *) ); // how do i call with this function pointer
	
	//2b. Sort the second half of the array. Pass in the address of the 
	//beginning of the second half of the array (remember to use the right # of 
	//elements)
	msort( (base + mid + 1), nel-1, (*compar)(const void *, const void *) ); 
	
	//3a. Merge the two arrays (use merge)
	Student * perfectArray;
	perfectArray = merge( base1, nel1, base2, nel2, (*compar)(const void *, const void *) );
	
	//3b. Copy the merged array over top of the original array (use copy)
	//Don't forget to free the array you no longer need!
	copy(base, perfectArray, nel);
	free(mergedArray); // how do I free this ??
	free(perfectArray);		
	return;
}
#endif

#ifndef OMIT_MERGE
Student * merge(Student * base1, int nel1, Student * base2, int nel2, int (*compar)(const void *, const void *)) {
	
	//1. Allocate space for the returned merged array
	Student * mergedArray = malloc( sizeof(Student) * (nel1 + nel2) );
	
	//2. Create indices to keep track of where you are in the three arrays
	int i = 0; // position in Left array (base1)
	int j = 0; // position in Right array (base2)
	int k = 0; // position in mergedArray
	
	//3. Go through base1 and base2, and merge them into the returned array
	while ( i < nel1 && j < nel2)
	{
	  int value = 0;
	  value = compar( base1[i], base2[j] ) // is this how to use a function pointer
	  
	   if ( value < 0 )// if value < 0, that means: base1[i] < base2[j]
	   {
		mergedArray[k] = base1[i];
		i++;
	   }
	   else if ( value > 0 ) // if value > 0, that means: base1[i] <= base2[j]
	   {
		mergedArray[k] = base2[j];
		j++;
	   }
	   else // if value == 0, that means they're equal: base1[i] == base2[j], and we'll just add the left array(base1's) element
	   { 
                mergedArray[k] = base1[i];
                i++;
           }
	  k++; // incrementing mergedArray
	}
	
	// Adding the remaining elements from both arrays
	while ( i < nel1 ){
	 mergedArray[k] = base1[i];
	 i++;
	 k++;
	}
	while ( j < nel2 ){
	 mergedArray[k] = base2[j];
	 j++;
	 k++;
	}

	
	//4. Return the merged array
	return mergedArray;

}


void copy(Student * to, Student * from, int nel) {
	/*
	An efficient implementation of this would use memcpy:
	memcpy(to, from, nel * width);

	We will do an element-by-element copy so you can see how it is done
	*/
	
	//loop over the from array and copy it byte by byte to the to array.
	for (int i = 0; i < nel; i++) {
		to[i] = from[i];
	}
	
	return;
}
#endif
