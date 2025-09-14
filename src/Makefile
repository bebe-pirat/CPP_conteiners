SHELL = /bin/sh

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++20 
TFLAGS = -lgtest -lgtest_main -lpthread
GFLAGS = -fprofile-arcs -ftest-coverage
LIB_NAME = s21_conteiners.a

SRC_DIR = .
TEST_DIR = tests
BUILD_DIR = .

LIB_SRC = $(SRC_DIR)/s21_queue.cpp $(SRC_DIR)/s21_set.cpp
LIB_OBJ = $(BUILD_DIR)/s21_queue.o $(BUILD_DIR)/s21_set.o
TEST_SRC = $(TEST_DIR)/s21_conteiners_tests.cpp
TEST_OBJ = $(BUILD_DIR)/s21_conteiners_tests.o

all: $(LIB_NAME) 

# TODO: добавить к all цель test

s21_conteiners.a: $(LIB_OBJ)
	ar rcs $@ $^
	ranlib $@

s21_conteiners.o: $(LIB_SRC) $(SRC_DIR)/s21_queue.h $(SRC_DIR)/s21_set.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# s21_conteiners_tests.o: $(TEST_SRC) $(SRC_DIR)/s21_queue.h $(SRC_DIR)/s21_set.h | $(BUILD_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# test: $(LIB_NAME) $(TEST_OBJ)
# 	$(CC) $(CFLAGS) $(TEST_OBJ) $(LIB_NAME) $(TFLAGS) -o test
# 	./test

# gcov_report: clean 
# 	$(CC) $(CFLAGS) $(GFLAGS) -c $(LIB_SRC) -o $(LIB_OBJ)
# 	$(CC) $(CFLAGS) -c $(TEST_SRC) -o $(TEST_OBJ)
# 	$(CC) $(LIB_OBJ) $(TEST_OBJ) $(TFLAGS) $(GFLAGS) -o gcov_report

# 	./gcov_report
# 	lcov -t "gcovreport" -o gcovreport.info -c -d . --no-external
# 	genhtml -o report gcovreport.info
# 	rm -rf *.gcda *.gcno
# 	open ./report/index.html

clang:
	clang-format -i --style=Google $(LIB_SRC) $(TEST_SRC) $(SRC_DIR)/s21_queue.h $(SRC_DIR)/s21_set.h

valgrind: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $(BUILD_DIR)/test

clean:
	rm -rf *.o $(LIB_NAME) test *.gcda *.gcno *.info gcov_report report/

rebuild: clean all