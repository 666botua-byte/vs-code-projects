CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

TARGET := place_app
SRCS := main.cpp Place.cpp Region.cpp City.cpp Megalopolis.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

