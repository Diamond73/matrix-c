SHELL := /bin/bash
CC = gcc
LINUX = -lsubunit -lrt -lpthread -lm
LCHECK = -lcheck
CFLAGS = -Werror -Wall -Wextra -std=c11
LFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname -s)
TEST_DIR := test
TEST := s21_test.c
OBJ_DIR = objects
OBJ = $(wildcard $(OBJ_DIR)/*.o)
GCOV_DIR := gcov
GCOV := $(TEST_DIR)/$(GCOV_DIR)
CORE = helpers/validation_funcs.c arith/arith.c lin_alg_func/lin_alg_func.c born_die/born_die.c helpers/math_func.c init/init.c
CL = -n

all: s21_matrix.a test gcov_report

s21_matrix.a: born_die.o arith.o validation_funcs.o math_func.o lin_alg_func.o
	ar rcs s21_matrix.a $(OBJ)

born_die.o: make_obj_dir
	$(CC) $(CFLAGS) -c born_die/born_die.c -o $(OBJ_DIR)/born_die.o
arith.o: make_obj_dir
	$(CC) $(CFLAGS) -c arith/arith.c -o $(OBJ_DIR)/arith.o
validation_funcs.o: make_obj_dir
	$(CC) $(CFLAGS) -c helpers/validation_funcs.c -o $(OBJ_DIR)/validation_funcs.o
math_func.o: make_obj_dir
	$(CC) $(CFLAGS) -c helpers/math_func.c -o $(OBJ_DIR)/math_func.o
lin_alg_func.o: make_obj_dir
	$(CC) $(CFLAGS) -c lin_alg_func/lin_alg_func.c -o $(OBJ_DIR)/lin_alg_func.o
init.o: make_obj_dir
	$(CC) $(CFLAGS) -c init/init.c -o $(OBJ_DIR)/init.o

test: $(TEST) s21_matrix.a
ifeq ($(OS), Darwin)    
	$(CC) $(CFLAGS) -g  $(TEST) $(CORE) -o $(TEST_DIR)/test.out $(LCHECK)
else    
	 $(CC) $(CFLAGS) -g $(TEST) $(CORE) -o $(TEST_DIR)/test.out $(LCHECK) $(LINUX)
endif    
	chmod +x $(TEST_DIR)/test.out
	./$(TEST_DIR)/test.out

gcov_report: gcov_test.info
	lcov -t "Tests coverage" -o $(GCOV)/test.info -c -d .    
	genhtml -o $(GCOV)/report/ $(GCOV)/test.info
	open ./$(GCOV)/report/index.html
	rm $(GCOV)/*.gcno
	rm $(GCOV)/*.gcda
	rm $(GCOV)/test.info


gcov_test.info: gcov_test.gcda
	lcov -t "Report" -o $(GCOV)/gcov_test.info --no-external -c -d .

gcov_test.gcda: gcov_test    
	chmod +x $(GCOV)/gcov_t
	./$(GCOV)/gcov_t

gcov_test: make_gcov_dir
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) -g $(LFLAGS) $(TEST) $(CORE) -o $(TEST_DIR)/$(GCOV_DIR)/$@ $(LCHECK)
else
	$(CC) $(CFLAGS) -g $(LFLAGS) $(TEST) $(CORE) -o $(TEST_DIR)/$(GCOV_DIR)/gcov_t $(LCHECK) $(LINUX)
endif

make_gcov_dir:
	mkdir -p $(TEST_DIR)/$(GCOV_DIR)

make_obj_dir:
	mkdir -p $(OBJ_DIR)

rebuild: clean all

clean:
	rm -rf *.o *.a *.info *.h.gch *.out test.out gcov_test 
	rm -rf *.gcno *.gcda
	rm -rf *dSYM
	rm -rf $(GCOV)
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_DIR)/test.out

leaks: test
ifeq ($(OS), Darwin)
	leaks --atExit -- ./$(TEST_DIR)/test.out
else
	valgrind   ./$(TEST_DIR)/test.out --leak-check=full
endif

clang:
	clang-format-18 $(CL) arith/*.c
	clang-format-18 $(CL) born_die/*.c
	clang-format-18 $(CL) helpers/*.c
	clang-format-18 $(CL) init/*.c
	clang-format-18 $(CL) lin_alg_func/*.c
	clang-format-18 $(CL) helpers/*.c
	clang-format-18 $(CL) *.c

