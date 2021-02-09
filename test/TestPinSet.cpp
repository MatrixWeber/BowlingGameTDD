//
// Created by Weber on 07.02.21.
//

#include "PinSet.h"
#include "gtest/gtest.h"

TEST(TestPinSet, DefaultConstructingSetupHasAllPinsStanding)
{
    const PinSet pins;
    EXPECT_TRUE(pins.allUp());
    EXPECT_FALSE(pins.allDown());
}

TEST(TestPinSet, APinSetWithOnePinKnockedDownDoesNotReturnTrueWhenWeCheckAllPinsAreStanding)
{
    PinSet pins;
    pins.knockDown(Pin::ONE);
    EXPECT_FALSE(pins.allUp());
}

TEST(TestPinSet, APinSetWithOnePinKnockedDownCanConfirmThatThePinIsNotSetButAllOthersAre)
{
    PinSet pins;
    const Pin four = Pin::FOUR;
    pins.knockDown(four);
    EXPECT_TRUE(pins.isDown(four));
    for(uint8_t pin = Pin::ONE; pin < Pin::MAX; ++pin)
    {
        if(pin == four)
        {
            continue;
        }
        EXPECT_FALSE(pins.isDown(static_cast<Pin>(pin)));
    }
}

TEST(TestPinSet, IsUpReturnsTheOpositOfIsDownForAnyGivenPin)
{
    PinSet pins;
    pins.knockDown(Pin::EIGHT);
    pins.knockDown(Pin::FIVE);
    for(uint8_t pin = Pin::ONE; pin < Pin::MAX; ++pin)
    {
        EXPECT_TRUE(pins.isDown(static_cast<Pin>(pin)) != pins.isUp(static_cast<Pin>(pin)));
    }
}

TEST(TestPinSet, AllPinsDownReturnsTrueWhenWeKnockDownAllThePins)
{
    PinSet pins;
    for(uint8_t pin = Pin::ONE; pin < Pin::MAX; ++pin)
    {
        pins.knockDown(static_cast<const Pin>(pin));
    }
    EXPECT_TRUE(pins.allDown());
    EXPECT_FALSE(pins.allUp());
}

TEST(TestPinSet, AllPinsDownReturnsFalseWhenOnlyOnePinIsDown)
{
    PinSet pins;
    pins.knockDown(Pin::TEN);
    EXPECT_FALSE(pins.allDown());
}

TEST(TestPinSet, PinsUpReturnsCountWhenWeKnockDownSomePinsAndPinsDownReturnsTheOpposit)
{
    PinSet pins;
    pins.knockDown(Pin::SIX);
    pins.knockDown(Pin::THREE);
    EXPECT_EQ(8, pins.upCount());
    EXPECT_EQ(2, pins.downCount());
    pins.knockDown(Pin::TWO);
    pins.knockDown(Pin::SEVEN);
    EXPECT_EQ(6, pins.upCount());
    EXPECT_EQ(4, pins.downCount());
}