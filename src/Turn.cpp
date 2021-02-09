//
// Created by Weber on 07.02.21.
//

#include "Turn.h"
void Turn::strike()
{
    knockAllPinsDown();
    isEnded_ = pinSet_.allDown();
    totalScore_ = pinSet_.downCount();
    turnsTaken_ = TurnsTaken::TWO;
}
void Turn::knockAllPinsDown()
{
    for (uint8_t pin = ONE; pin < MAX; ++pin)
    {
        pinSet_.knockDown(static_cast<Pin>(pin));
    }
}

bool Turn::ended() const
{
    return isEnded_;
}
void Turn::pinDown(const Pin pin)
{
    pinSet_.knockDown(pin);
    isEnded_ = pinSet_.allDown();
    turnsTaken_ = countTaken();
    totalScore_ = pinSet_.downCount();
}
Turn::TurnsTaken Turn::countTaken() const
{
    return turnsTaken_ == TurnsTaken::NONE
                 ? TurnsTaken::ONE
         : turnsTaken_ == TurnsTaken::ONE
                 ? TurnsTaken::TWO
                 : turnsTaken_;
}
uint8_t Turn::totalScore() const
{
    if (isOver())
    {
        return totalScore_;
    }
    throw std::logic_error{"FATAL: Cannot get score until final turn taken"};
}

bool Turn::isOver() const { return turnsTaken_ == TurnsTaken::TWO and isEnded_; }
