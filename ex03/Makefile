NAME := ./fixedPointNumber
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP
# CXXFLAGS += -pedantic-errors

SRCS := main.cpp \
		test.cpp \
		Point.cpp \
		Fixed.cpp \

OBJS := $(SRCS:%.cpp=%.o)

DEPS := $(OBJS:%.o=%.d)

INCLUDES := -I.

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CXXFLAGS += -DDEBUG
debug: re

-include $(DEPS)
