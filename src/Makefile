# Компилятор

CC := gcc

# Опции компилятора

CFLAGS := -std=c11 -Wall -Werror -pedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla
UNITFLAGS := -lcheck
COV_FLAG :=
OS:=$(shell uname -s)
ifeq ($(OS), Darwin)
	UNITFLAGS += $(shell pkg-config --cflags --libs check)
else
	UNITFLAGS += -lsubunit -lrt -lm -lpthread
endif

# Объектные файлы

OBJS := ./out/s21_math.o
UNITOBJS := ./out/s21_abs_test.o ./out/s21_atan_test.o ./out/s21_exp_test.o ./out/s21_fmod_test.o ./out/s21_sqrt_test.o ./out/s21_acos_test.o ./out/s21_ceil_test.o ./out/s21_fabs_test.o ./out/s21_log_test.o ./out/s21_pow_test.o ./out/s21_tan_test.o ./out/s21_asin_test.o ./out/s21_cos_test.o ./out/s21_floor_test.o ./out/s21_math_test.o ./out/s21_sin_test.o

.PHONY : all clean gcov_report del_lib

test : unit_tests.exe
	./unit_tests.exe || echo

all : COV_FLAG += --coverage
all : clean gcov_report

unit_tests.exe : $(OBJS) $(UNITOBJS) s21_math.a
	$(CC) -o unit_tests.exe $(UNITOBJS) $(UNITFLAGS) -L. -ls21_math -fprofile-arcs -ftest-coverage

gcov_report : COV_FLAG += --coverage
gcov_report : del_lib test
	lcov -t "coverage" -o coverage.info -c -d . 
	genhtml -o report coverage.info
	rm -rf ./*.g*

del_lib :
	rm -rf ./*.a
	rm -rf ./s21_math.o
	rm -rf ./out/s21_math.o
	
s21_math.a : ./out/s21_math.o
	ar rc $@ $^
	ranlib $@
	cp $@ lib$@

./out/%.o : ./unit_tests/%.c
	mkdir -p ./out
	$(CC) $(CFLAGS) $(UNITFLAGS) -c $<
	mv ./*.o ./out/

./out/%.o : ./%.c ./%.h
	mkdir -p ./out
	$(CC) $(CFLAGS) $(COV_FLAG) -c $<
	mv ./*.o ./out/

clean :
	rm -f ./*.exe
	rm -rf ./out
	rm -rf ./*.a
	rm -rf ./*.g*
	rm -rf ./report
	rm -rf ./*.info
