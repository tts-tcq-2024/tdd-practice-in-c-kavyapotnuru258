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

TEST(StringCalculatorAddTests, ReturnZeroForEmptyString) {
    ASSERT_EQ(add(""), 0);
}

TEST(StringCalculatorAddTests, ReturnNumberForSingleNumber) {
    ASSERT_EQ(add("1"), 1);
    ASSERT_EQ(add("2"), 2);
}

TEST(StringCalculatorAddTests, ReturnSumForTwoNumbers) {
    ASSERT_EQ(add("1,2"), 3);
    ASSERT_EQ(add("10,20"), 30);
}

TEST(StringCalculatorAddTests, ReturnSumForUnknownAmountOfNumbers) {
    ASSERT_EQ(add("1,2,3"), 6);
    ASSERT_EQ(add("1,2,3,4,5"), 15);
}

TEST(StringCalculatorAddTests, ReturnSumForNewLineDelimiter) {
    ASSERT_EQ(add("1\n2,3"), 6);
    ASSERT_EQ(add("1\n2\n3,4"), 10);
}

TEST(StringCalculatorAddTests, ReturnSumForCustomDelimiter) {
    ASSERT_EQ(add("//;\n1;2"), 3);
    ASSERT_EQ(add("//.\n2.3.4"), 9);
}




