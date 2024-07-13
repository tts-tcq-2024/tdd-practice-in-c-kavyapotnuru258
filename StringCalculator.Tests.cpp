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

// Expanded test cases

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    const char* input = "";
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
    const char* input = "1,2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    const char* input = "1\n2,3";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 2;
    const char* input = "2,1001";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    const char* input = "//;\n1;2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithLongCustomDelimiter) {
    int expectedresult = 6;
    const char* input = "//[***]\n1***2***3";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ThrowsExceptionForSingleNegativeNumber) {
    const char* input = "1,-2,3";
    EXPECT_THROW({
        try {
            add(input);
        } catch (const char* msg) {
            EXPECT_STREQ(msg, "negatives not allowed: -2");
            throw;
        }
    }, const char*);
}

TEST(StringCalculatorAddTests, ThrowsExceptionForMultipleNegativeNumbers) {
    const char* input = "1,-2,3,-4";
    EXPECT_THROW({
        try {
            add(input);
        } catch (const char* msg) {
            EXPECT_STREQ(msg, "negatives not allowed: -2, -4");
            throw;
        }
    }, const char*);
}

TEST(StringCalculatorAddTests, ExpectSumWithMultipleCustomDelimiters) {
    int expectedresult = 10;
    const char* input = "//[*][%]\n1*2%3*4";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineAndComma) {
    int expectedresult = 10;
    const char* input = "1,2\n3,4";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiterIncludingBrackets) {
    int expectedresult = 6;
    const char* input = "//[abc]\n1abc2abc3";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}


