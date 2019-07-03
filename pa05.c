// You must modify this file
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"

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





  // read students from the input file
  // return EXIT_FAILURE if reading fails




  // sort the students by IDs
  



  // write the result to the output (name is argv[2])
  // return EXIT_FAILURE if writing fails





  // sort the students by first names
  



  // write the result to the output (name is argv[3])
  // return EXIT_FAILURE if writing fails




  // sort the students by last names
  



  // write the result to the output (name is argv[4])
  // return EXIT_FAILURE if writing fails






  // release allocated memory





  return EXIT_SUCCESS;
}
