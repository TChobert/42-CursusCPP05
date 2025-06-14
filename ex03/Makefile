##### VARIABLES #####

## COLORS ##

GREEN =\033[0;32m
YELLOW =\033[0;33m
RESET =\033[0m

## TARGET ##

NAME := Interns

## COMPILATION ##

CC := c++

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -std=c++98

ifeq ($(d), 1)
		CFLAGS += -g3
endif

ifeq ($(d), 2)
		CFLAGS += -fsanitize=address,undefined -g3
endif

## SOURCES ##

SRCS += main.cpp
SRCS += Bureaucrat.cpp
SRCS += AForm.cpp
SRCS += ShrubberyCreationForm.cpp
SRCS += RobotomyRequestForm.cpp
SRCS += PresidentialPardonForm.cpp
SRCS += Intern.cpp

## INCLUDES ##

INCLUDES_DIR := .

INCLUDES += Bureaucrat.hpp
INCLUDES += ShrubberyCreationForm.hpp
INCLUDES += AForm.hpp
INCLUDES += RobotomyRequestForm.hpp
INCLUDES += PresidentialPardonForm.hpp
INCLUDES += Intern.hpp

## OBJECTS ##

OBJS := $(SRCS:.cpp=.o)

## RULES ##

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Interns compiled!$(RESET)"

$(OBJS): %.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re%