#include <vector>
#include <functional>
#include <iostream>
#include <gtest/gtest.h>

#include "candle.h"

class CandleFixture: public ::testing::Test{
protected:
    Candle greenCandle;
    Candle redCandle;
    Candle nullCandle;

    void SetUp() override{
        greenCandle = Candle(2., 3.1, 1., 3.);
        redCandle = Candle(3., 3.1, 1., 2.);
        nullCandle = Candle(0.,0.,0.,0.);
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

TEST_F(CandleFixture,bodyContains_EqualsOpenOrClose){
    ASSERT_TRUE(greenCandle.body_contains(2.0));
    ASSERT_TRUE(greenCandle.body_contains(3.0));
    ASSERT_TRUE(redCandle.body_contains(2.0));
    ASSERT_TRUE(redCandle.body_contains(3.0));
}

TEST_F(CandleFixture,contains_NotContained){
    ASSERT_FALSE(greenCandle.contains(0.5));
    ASSERT_FALSE(redCandle.contains(0.5));
}

TEST_F(CandleFixture,contains_Contained){
    ASSERT_TRUE(greenCandle.contains(1.5));
    ASSERT_TRUE(redCandle.contains(1.5));
}

TEST_F(CandleFixture,contains_EqualsLowOrHigh){
    ASSERT_TRUE(greenCandle.contains(3.1));
    ASSERT_TRUE(greenCandle.contains(1.));
    ASSERT_TRUE(redCandle.contains(3.1));
    ASSERT_TRUE(redCandle.contains(1.));
}

TEST_F(CandleFixture,fullSize_NullCandle){
    ASSERT_DOUBLE_EQ(nullCandle.full_size(),0.);
}

TEST_F(CandleFixture,fullSize_redCandle){
    ASSERT_DOUBLE_EQ(redCandle.full_size(),2.1);
}

TEST_F(CandleFixture,fullSize_greenCandle){
    ASSERT_DOUBLE_EQ(greenCandle.full_size(),2.1);
}

TEST_F(CandleFixture,bodySize_NullCandle){
    ASSERT_DOUBLE_EQ(nullCandle.body_size(),0.);
}

TEST_F(CandleFixture,bodySize_redCandle){
    ASSERT_DOUBLE_EQ(redCandle.body_size(),1.);
}

TEST_F(CandleFixture,bodySize_greenCandle){
    ASSERT_DOUBLE_EQ(greenCandle.body_size(),1.);
}
