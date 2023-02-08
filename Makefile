.PHONY: all

GCC=gcc -g3 -fsanitize=address -Wall -Wextra -Werror
PROJECT_NAME=my_printf
MAIN_FILE=my_printf.c
SOURCES=*.c
OBJECTS=*.o

all: ${MAIN_FILE}

${MAIN_FILE}: ${OBJECTS}
	@${GCC} -o ${PROJECT_NAME} ${MAIN_FILE}

${OBJECTS}:
	@${GCC} -c ${SOURCES}

clean:
	@rm -f ${OBJECTS}

fclean: clean
	@rm ${PROJECT_NAME}

re: fclean all	
