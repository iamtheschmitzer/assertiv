Assertiv
========

Minimal C++ header-only unit test framework from [OCI](http://ociweb.com)

Assertiv is a header-only unit test framework.  It is designed to be embedded within your own open-source project, rather than having a separate project for your clients to download and build.

## Usage
1. Add Assertiv to your project:

From your project root directory, add the submodule, passing the path to where you want it to reside:

> git submodule add git@github.com:iamtheschmitzer/assertiv.git test/unit/assertiv

2. Include the header file in your test source:

```c++
#include "assertiv/assertiv.h"
```

3. Define test cases with the TEST macro:

```c++
TEST(TestAdditionOperator) {
  // Test code goes here
}
```

4. Withing test case, use ASSERT_* macros:

```c++
TEST(TestAdditionOperator) {
  // Test construction and addition of Num class
  ASSERT_EQ(17, Num(8) + Num(9));
  ASSERT_EQ(Num(17), Num(8) + Num(9));
}
```

5. There are no more excuses.  Get testing.

## Features
* Header-only - no library to build
* Output file, line number and failiure conditions
* Summarizes count of total and failing test cases and assertions.

