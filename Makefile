NAME = testSortAlgorithm

CXX = clang++
CFLAGS = -W -Wall -Wextra 
CXXFLAGS = -std=c++11

TESTLIBS = -lcppunit

SRCS =  main.cpp \
	TestSortAlgorithm.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(TESTLIBS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
