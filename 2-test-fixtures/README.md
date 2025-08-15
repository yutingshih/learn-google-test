# Test Fixtures

Test fixtures are used to handle the same data configuration for several different tests.

## Create Fixture

## Use Constructor/Destructor or SetUp/TearDown?

## Write Tests with Fixtures

Use `TEST_F(TestFixtureClass, TestCase)` instead of `TEST(TestSuite, TestCast)`.

## Reference

- https://google.github.io/googletest/primer.html#same-data-multiple-tests
- https://google.github.io/googletest/faq.html#CtorVsSetUp