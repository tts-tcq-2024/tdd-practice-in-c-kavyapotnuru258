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
// TEST(StringCalculatorAddTests, ExpectSumWithLongCustomDelimiter) {
//     int expectedresult = 6;
//     const char* input = "//[***]\n1***2***3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, HandleNullInputGracefully) {
//     int expectedresult = 0;
//     int result = add(nullptr);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput2) {
//     int expectedresult = 0;
//     const char* input = "";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, GetDelimiter_CustomDelimiterSpecialChars) {
//     int expectedresult = 3;
//     const char* input = "//[$\n1$$2$$-3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }
#include <gtest/gtest.h>
#include "string_calculator.h"

// Test case for empty string input
TEST(StringCalculatorTest, HandlesEmptyString) {
    ASSERT_EQ(add(""), 0);
}

// Test case for single number input
TEST(StringCalculatorTest, HandlesSingleNumber) {
    ASSERT_EQ(add("5"), 5);
}

// Test case for two numbers input separated by a comma
TEST(StringCalculatorTest, HandlesTwoNumbersComma) {
    ASSERT_EQ(add("1,2"), 3);
}

// Test case for multiple numbers input separated by a comma
TEST(StringCalculatorTest, HandlesMultipleNumbersComma) {
    ASSERT_EQ(add("1,2,3,4"), 10);
}

// Test case for numbers with newlines between them
TEST(StringCalculatorTest, HandlesNewlineBetweenNumbers) {
    ASSERT_EQ(add("1\n2,3"), 6);
}

// Test case for custom single-character delimiter
TEST(StringCalculatorTest, HandlesCustomSingleCharacterDelimiter) {
    ASSERT_EQ(add("//;\n1;2;3"), 6);
}

// Test case for custom multi-character delimiter
TEST(StringCalculatorTest, HandlesCustomMultiCharacterDelimiter) {
    ASSERT_EQ(add("//[***]\n1***2***3"), 6);
}

// Test case for numbers larger than 1000 being ignored
TEST(StringCalculatorTest, IgnoresNumbersLargerThan1000) {
    ASSERT_EQ(add("2,1001"), 2);
    ASSERT_EQ(add("//;\n1002;1003;4"), 4);
}

// Test case for multiple custom delimiters
TEST(StringCalculatorTest, HandlesMultipleCustomDelimiters) {
    ASSERT_EQ(add("//[*][%]\n1*2%3"), 6);
}

// Test case for custom delimiters with special characters
TEST(StringCalculatorTest, HandlesCustomDelimitersWithSpecialCharacters) {
    ASSERT_EQ(add("//[***][%%]\n1***2%%3"), 6);
}

// Test case for negative numbers throwing an error
TEST(StringCalculatorTest, ThrowsErrorOnNegativeNumbers) {
    ASSERT_EXIT(add("1,-2,3,-4"), ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,-4");
}

// Test case for input with no valid numbers
TEST(StringCalculatorTest, HandlesNoValidNumbers) {
    ASSERT_EQ(add("1001,1002,1003"), 0);
}

// Test case for custom delimiter at the beginning of input with no numbers
TEST(StringCalculatorTest, HandlesCustomDelimiterWithNoNumbers) {
    ASSERT_EQ(add("//;\n"), 0);
}



