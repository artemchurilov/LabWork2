CXX = g++
CXXFLAGS = -std=c++17 -I. -Werror -Wpedantic -Wall -Wextra -g -fPIC $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs) -lm

TARGET = prog
LIBPROJECT = lib$(TARGET).a
TESTPROJECT = test-$(TARGET)

SRC_DIR = src
TEST_DIR = tests

SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/obj/obj.cpp $(SRC_DIR)/entity/entity.cpp $(SRC_DIR)/player/player.cpp $(SRC_DIR)/menu/menu.cpp $(SRC_DIR)/battlefield/battlefield.cpp
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(OBJECTS:.o=.d)

TEST_SOURCES = $(TEST_DIR)/test-obj.cpp $(TEST_DIR)/test-entity.cpp $(TEST_DIR)/test-player.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
TEST_DEPENDS = $(TEST_OBJECTS:.o=.d)

LDXXFLAGS = -L. -l:$(LIBPROJECT) $(LDFLAGS)
LDGTESTFLAGS = $(LDXXFLAGS) -lgtest -lgtest_main -pthread

.PHONY: all clean cleanall tests runtests

all: $(TARGET) $(LIBPROJECT)

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(LIBPROJECT): $(OBJECTS)
	$(AR) rcs $@ $^

$(TESTPROJECT): $(LIBPROJECT) $(TEST_OBJECTS)
	$(CXX) -o $@ $(TEST_OBJECTS) $(LDGTESTFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPENDS) $(TEST_DEPENDS)

tests: $(TESTPROJECT)

runtests: $(TESTPROJECT)
	./$(TESTPROJECT)

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(DEPENDS) $(TEST_DEPENDS)

cleanall: clean
	rm -f $(TARGET) $(LIBPROJECT) $(TESTPROJECT)