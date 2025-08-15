# Simple Tests

## Basic Concepts

- test case: a particular execution path with specific inputs and the result verifications
- test suite: contains multiple test cases, may share some common objects or subroutines (i.e. fixture)
- test program: contains multiple test suites

## Assertions

An assertion's result can be one of the following:

- success
- nonfatal fails: with `EXPECT_*` macro
- fatal fails: with `ASSERT_*` macro
    - It possibly skips the clean-up code, so remember to check if memory is properly freed.

To customize failure message, stream it into the macro using `<<` operator. For example:

```cpp
ASSERT_EQ(x.size(), y.size()) << "Vector lengths are not matched";

for (int i = 0; i < x.size(); ++i) {
    EXPECT_EQ(x[i], y[i]) << "Two vectors differ at index " << i;
}
```

## Simple Tests

Here is a skeleton of a simple test program.

```cpp
#include <gtest/gtest.h>

TEST(TestSuiteName, TestName1) {
    // Assertion1
    // ...
}

TEST(TestSuiteName, TestName2) {
    // Assertion1
    // Assertion2
    // Assertion3
    // ...
}
```

See [`test_factorial.cc`](./test_factorial.cc) for a practical example.

## Reference

https://google.github.io/googletest/primer.html#simple-tests
