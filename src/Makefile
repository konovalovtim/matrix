CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
TFLAGS=-fprofile-arcs -ftest-coverage

all: s21_matrix.a test gcov_report

s21_matrix.a:
	$(CC) $(CFLAGS) -c *.c
	ar r s21_matrix.a *.o
	rm *.o

test: objects_test objects_lib
	$(CC) $(TFLAGS) object_files/*.o -o test -lcheck
	./test
	mv *.gcda object_files

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c unit_tests/unit_tests.c
	rm .clang-format

objects_test:
	$(CC) $(CFLAGS) -c unit_tests/unit_tests.c
	mv *.o object_files

objects_lib:
	$(CC) $(CFLAGS) -c $(TFLAGS) *.c
	mv *.o object_files
	mv *.gcno object_files

gcov_report:
	lcov -t test -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html

style:
	cp ../materials/linters/.clang-format .
	clang-format -n  *.c *.h unit_tests/unit_tests.c
	rm .clang-format

clean:
	@-rm Report/report.* object_files/*.* *.a *.html *.info Report/* test

rebuild: clean all