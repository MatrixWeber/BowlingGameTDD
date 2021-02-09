//
// Created by Weber on 07.02.21.
//

#ifndef BOWLINGSIMULATOR_TURN_H
#define BOWLINGSIMULATOR_TURN_H


#include "interfaces/IPinSet.h"
#include <PinSet.h>
class Turn
{
  private:
    enum class TurnsTaken
    {
        NONE,
        ONE,
        TWO
    };
  public:
    explicit Turn(IPinSet& pinSet) : pinSet_(pinSet){}
    void strike();

    [[nodiscard]] bool ended() const;

    void pinDown(const Pin pin);

    [[nodiscard]] uint8_t totalScore() const;

  private:
    [[nodiscard]] TurnsTaken countTaken() const;
    [[nodiscard]] bool isOver() const;

  private:
    IPinSet& pinSet_;
    bool isEnded_{};
    uint8_t totalScore_{};
    TurnsTaken turnsTaken_{};
    void knockAllPinsDown();
};


#endif//BOWLINGSIMULATOR_TURN_H
