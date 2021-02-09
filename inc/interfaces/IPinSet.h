//
// Created by Weber on 07.02.21.
//

#ifndef BOWLINGSIMULATOR_IPINSET_H
#define BOWLINGSIMULATOR_IPINSET_H

#include <cstdint>
enum Pin
{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    MAX = TEN + 1
};

class IPinSet
{
  public:
    [[nodiscard]] virtual bool allUp() const = 0;
    virtual void knockDown(const Pin pin) = 0;

//    virtual [[nodiscard]] bool isDown(const Pin pin) const = 0;
//
//    virtual [[nodiscard]] bool isUp(const Pin pin) const = 0;
//
    [[nodiscard]] virtual bool allDown() const = 0;

    [[nodiscard]] virtual uint8_t upCount() const = 0;

    [[nodiscard]] virtual uint8_t downCount() const = 0;
};


#endif//BOWLINGSIMULATOR_IPINSET_H
