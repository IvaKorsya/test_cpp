#include <vector>
#include <functional>
#include <iostream>
#include <gtest/gtest.h>

#include "candle.h"

class CandleFixture: public ::testing::Test{
protected:
    Candle greenCandle;
    Candle redCandle;

    void SetUp() override{
        greenCandle = Candle(2., 3.1, 1., 3.);
        redCandle = Candle(3., 3.1, 1., 2.);
    }
public:
    ~CandleFixture() override = default;
};

TEST_F(CandleFixture,bodyContains_NotContained){
    ASSERT_FALSE(greenCandle.body_contains(1.1));
    ASSERT_FALSE(redCandle.body_contains(1.1));
}

TEST_F(CandleFixture,bodyContains_Contained){
    ASSERT_TRUE(greenCandle.body_contains(2.1));
    ASSERT_TRUE(redCandle.body_contains(2.1));
}

TEST_F(CandleFixture,bodyContains_EqualsLowOrHigh){
    ASSERT_TRUE(greenCandle.body_contains(2.0));
    ASSERT_TRUE(greenCandle.body_contains(3.0));
    ASSERT_TRUE(redCandle.body_contains(2.0));
    ASSERT_TRUE(redCandle.body_contains(3.0));
}
