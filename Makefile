CFLAGS = -g -Wall -std=c99 -Wshadow --pedantic -Wvla -Werror
DFLAGS = -DTEST_READ -DTEST_WRITE -DTEST_SORTID -DTEST_SORTFIRSTNAME -DTEST_SORTLASTNAME
VALS = valgrind --tool=memcheck --leak-check=full 
GCC = gcc #$(CFLAGS) $(COVFLAGS) $(PROFFLAG)

# "make" will create an executable called pa05
pa06: pa06.o student.o msort.o
	$(GCC) $(CFLAGS) $(DFLAGS) pa06.o student.o msort.o -o pa06

pa06.o: pa06.c student.h constant.h msort.h
	$(GCC) $(CFLAGS) $(DFLAGS) -c pa06.c

student.o: student.c student.h constant.h msort.h	
	$(GCC) $(CFLAGS) $(DFLAGS) -c student.c

msort.o: msort.c student.h msort.h
	$(GCC) $(CFLAGS) $(DFLAGS) -c msort.c


# "make test" will run the three input files
test: pa06
	./pa06 inputs/testinput1 id1 first1 last1
	./pa06 inputs/testinput2 id2 first2 last2
	./pa06 inputs/testinput3 id3 first3 last3
	diff expected/id1 id1
	diff expected/first1 first1
	diff expected/last1 last1
	diff expected/id2 id2
	diff expected/first2 first2
	diff expected/last2 last2
	diff expected/id3 id3
	diff expected/first3 first3
	diff expected/last3 last3
# "make memory" calls valgrind to check memory errors
memory: pa06
	$(VALS) ./pa06 inputs/testinput1 id1 first1 last1
	$(VALS) ./pa06 inputs/testinput2 id2 first2 last2
	$(VALS) ./pa06 inputs/testinput3 id3 first3 last3

# "make clean" remove .o and all output files
clean: 
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f id*

