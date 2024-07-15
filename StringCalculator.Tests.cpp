// #include <gtest/gtest.h>
// #include "StringCalculator.h"

// TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
//     int expectedresult = 0;
//     const char* input = "Hello, world!";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
//     int expectedresult = 0;
//     const char* input = "0";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
//     int expectedresult = 3;
//     const char*  input = "1,2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
//     int expectedresult = 6;
//     const char*  input = "1\n2,3";
//     int result =add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
//     int expectedresult = 1;
//     const char*  input = "1,1001";
//     int result =add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
//     int expectedresult = 3;
//     const char*  input = "//;\n1;2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }
#include <gtest/gtest.h>
#include "StringCalculator.h"

// Test for empty input
TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    const char* input = "";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for single zero input
TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    const char* input = "0";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for sum of two numbers
TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    const char* input = "1,2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for newline and comma as delimiters
TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    const char* input = "1\n2,3";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for ignoring numbers greater than 1000
TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    const char* input = "1,1001";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for custom delimiter
TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    const char* input = "//;\n1;2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for negative number handling
TEST(StringCalculatorAddTests, ExpectNegativeNumbersThrowException) {
    const char* input = "1,-2,3";
    ASSERT_EXIT({
        add(input);
    }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,");
}

// Test for multiple negative numbers
TEST(StringCalculatorAddTests, ExpectMultipleNegativesThrowException) {
    const char* input = "1,-2,-3,4";
    ASSERT_EXIT({
        add(input);
    }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,-3,");
}

// Test for numbers with custom delimiters of any length
TEST(StringCalculatorAddTests, ExpectSumWithLongCustomDelimiter) {
    int expectedresult = 6;
    const char* input = "//[***]\n1***2***3";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for ignoring numbers greater than 1000 in a custom delimiter scenario
TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000WithCustomDelimiter) {
    int expectedresult = 6;
    const char* input = "//;\n1;2;1001;3";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for input with only newlines
TEST(StringCalculatorAddTests, SumWithOnlyNewlines) {
    int expectedresult = 6;
    const char* input = "1\n2\n3";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

