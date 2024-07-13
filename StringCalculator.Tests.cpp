#include <gtest/gtest.h>
#include "StringCalculator.h"

// Test cases for StringCalculator

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int result = add("");
    ASSERT_EQ(result, 0);
}

TEST(StringCalculatorAddTests, ExpectNumberForSingleNumberInput) {
    int result = add("1");
    ASSERT_EQ(result, 1);
}

TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int result = add("1,2");
    ASSERT_EQ(result, 3);
}

TEST(StringCalculatorAddTests, ExpectSumForUnknownAmountOfNumbers) {
    int result = add("1,2,3,4,5");
    ASSERT_EQ(result, 15);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int result = add("1\n2,3");
    ASSERT_EQ(result, 6);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int result = add("//;\n1;2");
    ASSERT_EQ(result, 3);
}

TEST(StringCalculatorAddTests, ExpectSumWithLongCustomDelimiter) {
    int result = add("//[***]\n1***2***3");
    ASSERT_EQ(result, 6);
}

TEST(StringCalculatorAddTests, ThrowsExceptionForNegativeNumbers) {
    EXPECT_THROW({
        add("1,-2,3");
    }, const char*);
}

TEST(StringCalculatorAddTests, ThrowsExceptionForMultipleNegativeNumbers) {
    EXPECT_THROW({
        add("1,-2,3,-4");
    }, const char*);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int result = add("2,1001");
    ASSERT_EQ(result, 2);
}

TEST(StringCalculatorAddTests, ExpectSumWithMultipleCustomDelimiters) {
    int result = add("//[*][%]\n1*2%3*4");
    ASSERT_EQ(result, 10);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineAndComma) {
    int result = add("1,2\n3,4");
    ASSERT_EQ(result, 10);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiterIncludingBrackets) {
    int result = add("//[abc]\n1abc2abc3");
    ASSERT_EQ(result, 6);
}


