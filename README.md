Assertiv
========

Minimal C++ header-only unit test framework from [OCI](http://ociweb.com)

## Why Assertiv?
Assertiv is header-only, designed to be embedded within your own project, rather than having a separate project for your clients to download and build.

No downloads, no build issues, no worrying about runtime libraries, no bjam.

## Features
* Header-only - no library to build
* Outputs file name, line number and failiure conditions
* Summarizes count of total and failing test cases and assertions.

## Usage
* Add Assertiv to your project:

From your project root directory, add the submodule, passing the path to where you want it to reside:

```bash
git submodule add git@github.com:iamtheschmitzer/assertiv.git test/unit/assertiv
```

* Include the header file in your test source:

```c++
#include "assertiv/assertiv.h"
```

* Define test cases with the TEST macro:

```c++
TEST(TestAdditionOperator) {
  // Test code goes here
}
```

* Withing test case, use ASSERT_* macros:

```c++
TEST(TestAdditionOperator) {
  // Test construction and addition of Num class
  ASSERT_EQ(17, Num(8) + Num(9));
  ASSERT_EQ(Num(17), Num(8) + Num(9));
}
```

* There are no more excuses.  Get testing.

