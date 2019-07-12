// You must modify this file
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"
#include "msort.h"

// --------------------------------------------------------------
int main(int argc, char * * argv)
{
  // argv[1]: input file name
  // argv[2]: output file name, sorted by ID
  // argv[3]: output file name, sorted by first name
  // argv[4]: output file name, sorted by last name
  if (argc < 5)
    {
      return EXIT_FAILURE;
    }
  // create the necessary variables
  Student * arr;
  int numelem = 0; 

  // read students from the input file
  // return EXIT_FAILURE if reading fails
  bool value = true;
  value = StudentRead(argv[1], &arr, &numelem);
  if (value == false)
    return EXIT_FAILURE;   
 
  // sort the students by IDs
  StudentSortbyID(arr, numelem);

  // write the result to the output (name is argv[2])
  // return EXIT_FAILURE if writing fails
  value = StudentWrite(argv[2], arr, numelem);
   if (value == false)
    return EXIT_FAILURE;   

  // sort the students by first names
  StudentSortbyFirstName(arr, numelem);  

  // write the result to the output (name is argv[3])
  // return EXIT_FAILURE if writing fails
   value = StudentWrite(argv[3], arr, numelem);
   if (value == false)
    return EXIT_FAILURE;   

  // sort the students by last names
  StudentSortbyLastName(arr, numelem);

  // write the result to the output (name is argv[4])
  // return EXIT_FAILURE if writing fails
  value = StudentWrite(argv[4], arr, numelem);
   if (value == false)
    return EXIT_FAILURE;   

  // release allocated memory
  free(arr);

  return EXIT_SUCCESS;
}
