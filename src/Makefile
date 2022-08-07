OS := $(shell uname -s)
CC = gcc
FLAG = -Wall -Werror -Wextra
FLAG_C = -c -Wall -Werror -Wextra
CL_11 = -std=c11
PR_NAME = s21_math
ALL_FILE = $(PR_NAME).c 
ALL_FILE_O = $(PR_NAME).o


ifeq ($(OS), Darwin)
	FLAGS_PLATFORM = -lcheck
else
	FLAGS_PLATFORM = -lcheck -lsubunit -lrt -lm -lpthread -g
endif

all: clean $(PR_NAME).a

$(PR_NAME).a:
	@$(CC) $(FLAG_C) $(ALL_FILE)
	@ar rcs $(PR_NAME).a $(ALL_FILE_O)

test: $(PR_NAME).a
	@gcc unit_test.c $(PR_NAME).a $(FLAGS_PLATFORM) -o tests.o
	@./tests.o

gcov_report:
	@$(CC) --coverage $(ALL_FILE) unit_test.c $(FLAGS_PLATFORM) -o gov_report.o
	@./gov_report.o
	@lcov -t $(PR_NAME)_tests -o $(PR_NAME)_tests.info -c -d .
	@genhtml -o report $(PR_NAME)_tests.info

clean:
	@rm -f *.a
	@rm -f *.o
	@rm -f *.gcda
	@rm -f *.gcdo
	@rm -f *.gcno
	@rm -f *.info

leaks: $(ALL_FILE_O)
	@CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./tests.o

style: $(ALL_FILE)
	@cp ../materials/linters/CPPLINT.cfg ./
	@python3 ./../materials/linters/cpplint.py --extensions=c $(ALL_FILE) unit_test.c $(PR_NAME).h
	@rm -f CPPLINT.cfg

cppcheck: $(ALL_FILE_O)
	@cppcheck --enable=all --suppress=missingIncludeSystem . $(ALL_FILE)

check: style cppcheck