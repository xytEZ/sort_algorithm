CXX = clang++

RM = rm -f

CFLAGS += -Wextra -Wall
CFLAGS += -I.
CXXFLAGS += -std=c++11

LDFLAGS = -lcppunit -ldl

NAME = testSortAlgorithm

SRCS =  main.cpp \
	TestSortAlgorithm.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
