CXX = g++
CXXFLAGS = -c -std=c++17 -I. -Werror -Wpedantic -Wall -g -fPIC

TARGET = player
LIBPROJECT = $(TARGET).a
TESTPROJECT = test-$(TARGET)

SOURCES = player.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

TEST_SOURCES = test-player.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

LDXXFLAGS = -L. -l:$(LIBPROJECT)
LDGTESTFLAGS = $(LDXXFLAGS) -lgtest -lgtest_main -pthread

default: all

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

$(LIBPROJECT): $(OBJECTS)
	ar rsv $(LIBPROJECT) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

$(TESTPROJECT): $(LIBPROJECT) $(TEST_OBJECTS)
	$(CXX) -o $(TESTPROJECT) $(TEST_OBJECTS) $(LDGTESTFLAGS)

runtests: $(TESTPROJECT)
	./$(TESTPROJECT)

all: $(TARGET) $(LIBPROJECT)

tests: $(LIBPROJECT) $(TESTPROJECT)

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS)

cleanall: clean
	rm -f $(TARGET) $(LIBPROJECT) $(TESTPROJECT)
