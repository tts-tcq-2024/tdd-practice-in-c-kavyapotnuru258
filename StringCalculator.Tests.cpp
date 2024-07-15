#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    const char* input = "Hello, world!";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    const char* input = "0";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    const char*  input = "1,2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    const char*  input = "1\n2,3";
    int result =add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    const char*  input = "1,1001";
    int result =add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    const char*  input = "//;\n1;2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}
// #include <gtest/gtest.h>
// #include "StringCalculator.h"

// // Test for empty input
// TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
//     int expectedresult = 0;
//     const char* input = "";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for single zero input
// TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
//     int expectedresult = 0;
//     const char* input = "0";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for sum of two numbers
// TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
//     int expectedresult = 3;
//     const char* input = "1,2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for newline and comma as delimiters
// TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
//     int expectedresult = 6;
//     const char* input = "1\n2,3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for ignoring numbers greater than 1000
// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
//     int expectedresult = 1;
//     const char* input = "1,1001";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for custom delimiter
// TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
//     int expectedresult = 3;
//     const char* input = "//;\n1;2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for negative number handling
// // TEST(StringCalculatorAddTests, ExpectNegativeNumbersThrowException) {
// //     const char* input = "1,-2,3";
// //     ASSERT_EXIT({
// //         add(input);
// //     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,");
// // }

// // // Test for multiple negative numbers
// // TEST(StringCalculatorAddTests, ExpectMultipleNegativesThrowException) {
// //     const char* input = "1,-2,-3,4";
// //     ASSERT_EXIT({
// //         add(input);
// //     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,-3,");
// // }

// // Test for numbers with custom delimiters of any length
// TEST(StringCalculatorAddTests, ExpectSumWithLongCustomDelimiter) {
//     int expectedresult = 6;
//     const char* input = "//[***]\n1***2***3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for ignoring numbers greater than 1000 in a custom delimiter scenario
// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000WithCustomDelimiter) {
//     int expectedresult = 6;
//     const char* input = "//;\n1;2;1001;3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for input with only newlines
// TEST(StringCalculatorAddTests, SumWithOnlyNewlines) {
//     int expectedresult = 6;
//     const char* input = "1\n2\n3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }
// #include <gtest/gtest.h>
// #include "StringCalculator.h"

// // Test for empty input
// TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
//     int expectedresult = 0;
//     const char* input = "";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for single zero input
// TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
//     int expectedresult = 0;
//     const char* input = "0";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for sum of two numbers
// TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
//     int expectedresult = 3;
//     const char* input = "1,2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for newline and comma as delimiters
// TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
//     int expectedresult = 6;
//     const char* input = "1\n2,3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for ignoring numbers greater than 1000
// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
//     int expectedresult = 1;
//     const char* input = "1,1001";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for custom delimiter
// TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
//     int expectedresult = 3;
//     const char* input = "//;\n1;2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for negative number handling
// TEST(StringCalculatorAddTests, ExpectNegativeNumbersThrowException) {
//     const char* input = "1,-2,3";
//     ASSERT_EXIT({
//         add(input);
//     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,");
// }

// // Test for multiple negative numbers
// TEST(StringCalculatorAddTests, ExpectMultipleNegativesThrowException) {
//     const char* input = "1,-2,-3,4";
//     ASSERT_EXIT({
//         add(input);
//     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,-3,");
// }

// // Test for numbers with custom delimiters of any length
// TEST(StringCalculatorAddTests, ExpectSumWithLongCustomDelimiter) {
//     int expectedresult = 6;
//     const char* input = "//[***]\n1***2***3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for ignoring numbers greater than 1000 in a custom delimiter scenario
// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000WithCustomDelimiter) {
//     int expectedresult = 6;
//     const char* input = "//;\n1;2;1001;3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for input with only newlines
// TEST(StringCalculatorAddTests, SumWithOnlyNewlines) {
//     int expectedresult = 6;
//     const char* input = "1\n2\n3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for multiple delimiters
// TEST(StringCalculatorAddTests, ExpectSumWithMultipleDelimiters) {
//     int expectedresult = 6;
//     const char* input = "//[;][%]\n1;2%3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for custom delimiter of varying lengths
// TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimitersVaryingLengths) {
//     int expectedresult = 10;
//     const char* input = "//[**][%%]\n5**3%%2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for large input with ignored numbers
// TEST(StringCalculatorAddTests, LargeInputIgnoredNumbers) {
//     int expectedresult = 3;
//     const char* input = "1,2,1000,1001,3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for consecutive delimiters
// TEST(StringCalculatorAddTests, ExpectSumWithConsecutiveDelimiters) {
//     int expectedresult = 6;
//     const char* input = "//;\n1;;2;3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for input with leading and trailing newlines
// TEST(StringCalculatorAddTests, ExpectSumWithLeadingTrailingNewlines) {
//     int expectedresult = 3;
//     const char* input = "\n1\n2\n3\n";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }
// #include <gtest/gtest.h>
// #include "StringCalculator.h"

// // Test for empty input
// TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
//     int expectedresult = 0;
//     const char* input = "";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for single zero input
// TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
//     int expectedresult = 0;
//     const char* input = "0";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for sum of two numbers
// TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
//     int expectedresult = 3;
//     const char* input = "1,2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for newline and comma as delimiters
// TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
//     int expectedresult = 6;
//     const char* input = "1\n2,3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for ignoring numbers greater than 1000
// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
//     int expectedresult = 1;
//     const char* input = "1,1001";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for custom delimiter
// TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
//     int expectedresult = 3;
//     const char* input = "//;\n1;2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for negative number handling
// TEST(StringCalculatorAddTests, ExpectNegativeNumbersThrowException) {
//     const char* input = "1,-2,3";
//     ASSERT_EXIT({
//         add(input);
//     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,");
// }

// // Test for multiple negative numbers
// TEST(StringCalculatorAddTests, ExpectMultipleNegativesThrowException) {
//     const char* input = "1,-2,-3,4";
//     ASSERT_EXIT({
//         add(input);
//     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,-3,");
// }

// // Test for numbers with custom delimiters of any length
// TEST(StringCalculatorAddTests, ExpectSumWithLongCustomDelimiter) {
//     int expectedresult = 6;
//     const char* input = "//[***]\n1***2***3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for ignoring numbers greater than 1000 in a custom delimiter scenario
// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000WithCustomDelimiter) {
//     int expectedresult = 6;
//     const char* input = "//;\n1;2;1001;3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for input with only newlines
// TEST(StringCalculatorAddTests, SumWithOnlyNewlines) {
//     int expectedresult = 6;
//     const char* input = "1\n2\n3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for multiple delimiters
// TEST(StringCalculatorAddTests, ExpectSumWithMultipleDelimiters) {
//     int expectedresult = 6;
//     const char* input = "//[;][%]\n1;2%3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for custom delimiter of varying lengths
// TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimitersVaryingLengths) {
//     int expectedresult = 10;
//     const char* input = "//[**][%%]\n5**3%%2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for large input with ignored numbers
// TEST(StringCalculatorAddTests, LargeInputIgnoredNumbers) {
//     int expectedresult = 3;
//     const char* input = "1,2,1000,1001,3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for consecutive delimiters
// TEST(StringCalculatorAddTests, ExpectSumWithConsecutiveDelimiters) {
//     int expectedresult = 6;
//     const char* input = "//;\n1;;2;3";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for input with leading and trailing newlines
// TEST(StringCalculatorAddTests, ExpectSumWithLeadingTrailingNewlines) {
//     int expectedresult = 3;
//     const char* input = "\n1\n2\n3\n";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// // Test for single negative number in custom delimiter
// TEST(StringCalculatorAddTests, SingleNegativeWithCustomDelimiter) {
//     const char* input = "//;\n1;-2;3";
//     ASSERT_EXIT({
//         add(input);
//     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,");
// }

// // Test for multiple negative numbers with custom delimiter
// TEST(StringCalculatorAddTests, MultipleNegativesWithCustomDelimiter) {
//     const char* input = "//;\n1;-2;-3;4";
//     ASSERT_EXIT({
//         add(input);
//     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,-3,");
// }
// #include <gtest/gtest.h>
// #include "StringCalculator.h"

// // Test for empty input
// TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
//     ASSERT_EQ(add(""), 0);
// }

// // Test for single zero input
// TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
//     ASSERT_EQ(add("0"), 0);
// }

// // Test for sum of two numbers
// TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
//     ASSERT_EQ(add("1,2"), 3);
// }

// // Test for newline and comma as delimiters
// TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
//     ASSERT_EQ(add("1\n2,3"), 6);
// }

// // Test for ignoring numbers greater than 1000
// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
//     ASSERT_EQ(add("1,1001"), 1);
// }

// // Test for custom delimiter
// TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
//     ASSERT_EQ(add("//;\n1;2"), 3);
// }

// // Test for negative number handling
// TEST(StringCalculatorAddTests, ExpectNegativeNumbersThrowException) {
//     ASSERT_EXIT({
//         add("1,-2,3");
//     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,");
// }

// // Test for multiple negative numbers
// TEST(StringCalculatorAddTests, ExpectMultipleNegativesThrowException) {
//     ASSERT_EXIT({
//         add("1,-2,-3,4");
//     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,-3,");
// }

// // Test for numbers with custom delimiters of any length
// TEST(StringCalculatorAddTests, ExpectSumWithLongCustomDelimiter) {
//     ASSERT_EQ(add("//[***]\n1***2***3"), 6);
// }

// // Test for ignoring numbers greater than 1000 in a custom delimiter scenario
// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000WithCustomDelimiter) {
//     ASSERT_EQ(add("//;\n1;2;1001;3"), 6);
// }

// // Test for input with only newlines
// TEST(StringCalculatorAddTests, SumWithOnlyNewlines) {
//     ASSERT_EQ(add("1\n2\n3"), 6);
// }

// // Test for leading and trailing newlines
// TEST(StringCalculatorAddTests, ExpectSumWithLeadingTrailingNewlines) {
//     ASSERT_EQ(add("\n1\n2\n3\n"), 6);
// }

// // Test for single negative with custom delimiter
// TEST(StringCalculatorAddTests, SingleNegativeWithCustomDelimiter) {
//     ASSERT_EXIT({
//         add("//;\n1;-2;3");
//     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,");
// }

// // Test for multiple negatives with custom delimiter
// TEST(StringCalculatorAddTests, MultipleNegativesWithCustomDelimiter) {
//     ASSERT_EXIT({
//         add("//;\n1;-2;-3;4");
//     }, ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,-3,");
// }

// // Test for large input ignored numbers
// TEST(StringCalculatorAddTests, LargeInputIgnoredNumbers) {
//     ASSERT_EQ(add("1,2,3,1001,1002"), 6);
// }

// // Test for numbers with various delimiters including multiple characters
// TEST(StringCalculatorAddTests, ExpectMultipleDelimiters) {
//     ASSERT_EQ(add("//[***][%]\n1***2%3"), 6);
// }

// // Test for handling multiple custom delimiters
// TEST(StringCalculatorAddTests, ExpectMultipleCustomDelimiters) {
//     ASSERT_EQ(add("//[;][|]\n1;2|3"), 6);
// }

// // Test for leading and trailing delimiters
// TEST(StringCalculatorAddTests, LeadingAndTrailingDelimiters) {
//     ASSERT_EQ(add("//;\n;1;2;3;"), 6);
// }

// // Test for input only with delimiters and no numbers
// TEST(StringCalculatorAddTests, InputWithOnlyDelimiters) {
//     ASSERT_EQ(add("//;\n;;"), 0);
// }

// // Test for empty tokens due to delimiters
// TEST(StringCalculatorAddTests, EmptyTokensWithDelimiters) {
//     ASSERT_EQ(add("//;\n1;;2"), 3);
// }

// // Test for large input
// TEST(StringCalculatorAddTests, LargeInput) {
//     const char* input = "1,2,3,4,5,6,7,8,9,10,1000";
//     ASSERT_EQ(add(input), 55);
// }

// // Test for very large numbers, ensuring they are ignored
// TEST(StringCalculatorAddTests, VeryLargeNumbers) {
//     ASSERT_EQ(add("1,2,3,10000"), 6);
// }

// // Test for custom delimiter and ignore logic
// TEST(StringCalculatorAddTests, CustomDelimiterWithIgnoredNumbers) {
//     ASSERT_EQ(add("//;\n1;2;1001;4"), 7);
// }
// #include <gtest/gtest.h>
// #include "StringCalculator.h"

// // Test for empty input
// TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
//     ASSERT_EQ(add(""), 0);
// }

// // Test for single zero input
// TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
//     ASSERT_EQ(add("0"), 0);
// }

// // Test for sum of two numbers
// TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
//     ASSERT_EQ(add("1,2"), 3);
// }

// // Test for newline and comma as delimiters
// TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
//     ASSERT_EQ(add("1\n2,3"), 6);
// }

// // Test for ignoring numbers greater than 1000
// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
//     ASSERT_EQ(add("1,1001"), 1);
// }

// // Test for custom delimiter
// TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
//     ASSERT_EQ(add("//;\n1;2"), 3);
// }

// // Test for negative number handling
// TEST(StringCalculatorAddTests, ExpectNegativeNumbersThrowException) {
//     char expected_error[] = "negatives not allowed: -2,";
//     testing::internal::CaptureStderr();
//     ASSERT_EXIT(add("1,-2,3"), ::testing::ExitedWithCode(EXIT_FAILURE), expected_error);
// }

// // Test for multiple negative numbers
// TEST(StringCalculatorAddTests, ExpectMultipleNegativesThrowException) {
//     char expected_error[] = "negatives not allowed: -2,-3,";
//     testing::internal::CaptureStderr();
//     ASSERT_EXIT(add("1,-2,-3,4"), ::testing::ExitedWithCode(EXIT_FAILURE), expected_error);
// }

// // Test for numbers with custom delimiters of any length
// TEST(StringCalculatorAddTests, ExpectSumWithLongCustomDelimiter) {
//     ASSERT_EQ(add("//[***]\n1***2***3"), 6);
// }

// // Test for ignoring numbers greater than 1000 in a custom delimiter scenario
// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000WithCustomDelimiter) {
//     ASSERT_EQ(add("//;\n1;2;1001;3"), 6);
// }

// // Test for input with only newlines
// TEST(StringCalculatorAddTests, SumWithOnlyNewlines) {
//     ASSERT_EQ(add("1\n2\n3"), 6);
// }

// // Test for leading/trailing newlines
// TEST(StringCalculatorAddTests, ExpectSumWithLeadingTrailingNewlines) {
//     ASSERT_EQ(add("\n1\n2\n3\n"), 6);
// }

// // Test for single negative with custom delimiter
// TEST(StringCalculatorAddTests, SingleNegativeWithCustomDelimiter) {
//     char expected_error[] = "negatives not allowed: -1,";
//     testing::internal::CaptureStderr();
//     ASSERT_EXIT(add("//;\n1;-1;2"), ::testing::ExitedWithCode(EXIT_FAILURE), expected_error);
// }

// // Test for multiple negatives with custom delimiter
// TEST(StringCalculatorAddTests, MultipleNegativesWithCustomDelimiter) {
//     char expected_error[] = "negatives not allowed: -1,-2,";
//     testing::internal::CaptureStderr();
//     ASSERT_EXIT(add("//;\n1;-1;2;-2"), ::testing::ExitedWithCode(EXIT_FAILURE), expected_error);
// }

// // Test for large input
// TEST(StringCalculatorAddTests, LargeInput) {
//     const char* input = "1,2,3,1000,1001,4\n5";
//     ASSERT_EQ(add(input), 15); // 1 + 2 + 3 + 1000 + 4 + 5 = 15
// }



