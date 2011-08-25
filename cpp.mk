GTEST_DIR = /usr/src/gtest
USER_DIR = ./
CPPFLAGS += -I$(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra
TESTS = unittest
GTEST_HEADERS = /usr/include/gtest/*.h /usr/include/gtest/internal/*.h

all: $(TESTS)

clean:
	rm -f $(TESTS) gtest.a gtest_main.a *.o *~

test: $(TESTS)
	time ./$(TESTS)

## my code
answer.o: $(USER_DIR)/answer.cc $(USER_DIR)/answer.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/answer.cc

unittest.o: $(USER_DIR)/unittest.cc \
		   $(USER_DIR)/answer.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/unittest.cc

unittest: answer.o unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

## gtest code
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a: gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^
