#ifndef ASSERTIV_H
#define ASSERTIV_H
/*
   Copyright (C) 2013 Object Computing Incorporated.
   All rights reserved.
   See the file license.txt for licensing information.

   Assertive - miminal C++ unit test library.  Nothing to build, just #include
               in your test code, use the TEST() and ASSERT_* macros.
*/
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

namespace {
  class TestRunner;

  struct TestInstance {
    TestRunner* runner;
    std::string test_case_;
    void (*test_func_)();
  };

  class TestRunner {
  public:
    typedef std::vector<TestInstance> Tests;
    TestRunner() : test_case_count_(0), test_case_fail_count_(0),
                   assertion_count_(0), assertion_fail_count_(0)
    {
    }

    ~TestRunner() {
      for (Tests::iterator test = tests_.begin(); test != tests_.end(); ++test) {
        std::cout << "Testing " << test->test_case_ << std::endl;
        ++test_case_count_;
        unsigned int old_assertion_fail_count = assertion_fail_count_;
        test->test_func_();
        // If the assertion fail count increased, the test failed
        if (assertion_fail_count_ > old_assertion_fail_count) {
          ++test_case_fail_count_;
        }
      }

      std::cout << std::setw(10) << test_case_count_ << " Test cases: "
                << test_case_count_ - test_case_fail_count_ << " passed, "
                << test_case_fail_count_ << " failed" << std::endl;
      std::cout << std::setw(10) << assertion_count_ << " Assertions: "
                << assertion_count_ - assertion_fail_count_ << " passed, "
                << assertion_fail_count_ << " failed" << std::endl;
      if (assertion_fail_count_) {
        std::cerr << "Test FAILED" << std::endl;
      } else {
        std::cout << "Test PASSED" << std::endl;
      }
    }

    void add(const char* test_case,
             void (*pfunc)()) {
      TestInstance instance;
      instance.test_case_ = test_case;
      instance.test_func_ = pfunc;
      tests_.push_back(instance);
    }

    void assert_pass() {
      ++assertion_count_;
    }

    void assert_fail() {
      ++assertion_count_;
      ++assertion_fail_count_;
    }
   
  private:
    Tests tests_;
    unsigned int test_case_count_;
    unsigned int test_case_fail_count_;
    unsigned int assertion_count_;
    unsigned int assertion_fail_count_;
  };
} 

TestRunner runner_;

class Registrar {
public:
  Registrar(const char* test_case, void (*pfunc)()) {
    runner_.add(test_case, pfunc);
  }
};

#define TEST(test_case) \
void test_##test_case(); \
Registrar reg_##test_case(#test_case, test_##test_case); \
\
void test_##test_case() 

#define ASSERT_EQ(left, right) if ((left) != (right)) {\
  runner_.assert_fail(); \
  std::cerr << __FILE__ << ":" << __LINE__ \
    << " ASSERT_EQ    Failure: comparing " << (left) << " with " << (right) \
    << std::endl;\
} else { \
  runner_.assert_pass(); \
}

#define ASSERT_TRUE(val) if (!(val)) {\
  runner_.assert_fail(); \
  std::cerr << __FILE__ << ":" << __LINE__ \
    << " ASSERT_TRUE  Failure: checking " << (val) << std::endl;\
} else { \
  runner_.assert_pass(); \
}

#define ASSERT_FALSE(val) if (val) {\
  runner_.assert_fail(); \
  std::cerr << __FILE__ << ":" << __LINE__ \
    << " ASSERT_FALSE Failure: checking " << (val) << std::endl;\
} else { \
  runner_.assert_pass(); \
}
#define ASSERT_NO_THROW(code) try {\
  code \
  runner_.assert_pass(); \
} catch (...) { \
  runner_.assert_fail(); \
  std::cerr << __FILE__ << ":" << __LINE__ \
    << " ASSERT_NO_THROW Failure:" << std::endl;\
}

#ifndef ASSERTIV_NO_MAIN
int main(int , const char* []) {
  return 0;
}
#endif

#endif
