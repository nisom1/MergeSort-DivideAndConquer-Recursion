// Do not remove #ifdef ... #endif before and after each function.
// 
// They are used to test different functions in your program and give
// partial credits, in case your program does not work completely.

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StudentPrint(Student * stu, int num)
{
  printf("There are %d students\n", num);
  for (int ind = 0; ind < num; ind ++)
    {
      printf("ID = %d, First Name = %s, Last Name = %s\n",
	     stu[ind].ID,  stu[ind].firstname, stu[ind].lastname);
    }
}

#ifdef TEST_READ
// return false if anything is wrong 
// return true if reading the file successfully and the data is save in
// the allocated memory
// input: filename, the name of the input file
// output: address of the allocated memory
// output: number of students
bool StudentRead(char * filename, Student * * stu, int * numelem)
{
  // open the file to read






  // if fopen fails, return false
  // do not use fclose since fopen already fails





  // count the number of lines to determine the number of students



  
  // return to the beginning of the file
  // you can use fseek or
  // fclose followed by fopen
  // You need to check whether fseek or fopen fails
  // Do not use rewind because it does not report whether it fails










  // allocate memory for the data










  // check whether memory allocation fails









  // read the data from the file and store the data in the allocated memory












  // close the file








  return true;
}
#endif

#ifdef TEST_WRITE
// return false if anything is wrong 
// return true if writing the file successfully
// input: filename, the name of the output file
// input: address of the student array
// input: number of students

bool StudentWrite(char * filename, Student * stu, int numelem)
{
  // open the file to read








  // if fopen fails, return false
  // do not use fclose since fopen already fails








  // write the students to the output file








}
#endif 

#ifdef TEST_SORTID
void StudentSortbyID(Student * stu, int numelem)
{


}
#endif

#ifdef TEST_SORTFIRSTNAME
void StudentSortbyFirstName(Student * stu, int numelem)
{

}
#endif

#ifdef TEST_SORTLASTNAME
}
void StudentSortbyLastName(Student * stu, int numelem)
{

}
#endif
