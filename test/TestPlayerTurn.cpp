//
// Created by Weber on 07.02.21.
//

#include "IPinSet.h"
#include "MockPinSet.h"
#include "Turn.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using namespace testing;

TEST(TestPlayerTurn, GettingAStrikeOnTheFirstBowlResultsInTurnEnded)
{
    MockPinSet mockPinSet;
    Turn turn(mockPinSet);
    uint8_t pins = 10;
    EXPECT_CALL(mockPinSet, knockDown(_)).Times(10);
    EXPECT_CALL(mockPinSet, allDown());
    EXPECT_CALL(mockPinSet, downCount());
    ON_CALL(mockPinSet, allDown()).WillByDefault(Return(true));
    ON_CALL(mockPinSet, downCount()).WillByDefault(Return(pins));
    turn.strike();
    EXPECT_TRUE(turn.ended());
    EXPECT_EQ(pins, turn.totalScore());
}

TEST(TestPlayerTurn, NotGettingAStrikeOnTheFirstBowlResultsInNotTurnEnded)
{
    MockPinSet mockPinSet;
    Turn turn(mockPinSet);
    EXPECT_CALL(mockPinSet, knockDown(Pin::SEVEN));
    EXPECT_CALL(mockPinSet, allDown());
    EXPECT_CALL(mockPinSet, downCount());
    ON_CALL(mockPinSet, allDown()).WillByDefault(Return(false));
    ON_CALL(mockPinSet, downCount()).WillByDefault(Return(1));
    turn.pinDown(Pin::SEVEN);
    EXPECT_FALSE(turn.ended());
}

TEST(TestPlayerTurn, TakingOneBowlWhichIsNotAStrikeShouldThrowAnExceptionOnCallingGetTotal)
{
    MockPinSet mockPinSet;
    Turn turn(mockPinSet);
    EXPECT_CALL(mockPinSet, knockDown(Pin::EIGHT));
    EXPECT_CALL(mockPinSet, allDown());
    EXPECT_CALL(mockPinSet, downCount());
    ON_CALL(mockPinSet, allDown()).WillByDefault(Return(false));
    ON_CALL(mockPinSet, downCount()).WillByDefault(Return(1));
    turn.pinDown(Pin::EIGHT);
    EXPECT_THROW(auto dummy = turn.totalScore(), std::logic_error);
}

TEST(TestPlayerTurn, TakingTwoBowlsShouldNotThrowAnExceptionOnCallingGetTotal)
{
    MockPinSet mockPinSet;
    Turn turn(mockPinSet);
    uint8_t count = 1;
    EXPECT_CALL(mockPinSet, knockDown(Pin::EIGHT));
    EXPECT_CALL(mockPinSet, allDown());
    EXPECT_CALL(mockPinSet, downCount());
    ON_CALL(mockPinSet, allDown()).WillByDefault(Return(false));
    ON_CALL(mockPinSet, downCount()).WillByDefault(Return(count++));
    turn.pinDown(Pin::EIGHT);
    EXPECT_CALL(mockPinSet, knockDown(Pin::TWO));
    EXPECT_CALL(mockPinSet, allDown());
    EXPECT_CALL(mockPinSet, downCount());
    ON_CALL(mockPinSet, allDown()).WillByDefault(Return(true));
    ON_CALL(mockPinSet, downCount()).WillByDefault(Return(count));
    turn.pinDown(Pin::TWO);
    EXPECT_EQ(count, turn.totalScore());
}