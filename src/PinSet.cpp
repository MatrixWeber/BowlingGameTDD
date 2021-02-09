//
// Created by Weber on 07.02.21.
//

#include "PinSet.h"
bool PinSet::allUp() const
{
    return pins_.all();
}
void PinSet::knockDown(const Pin pin)
{
    pins_[pin] = false;
}
bool PinSet::isDown(const Pin pin) const
{
    return not isUp(pin);
}
bool PinSet::isUp(const Pin pin) const
{
    return pins_.test(pin);
}
bool PinSet::allDown() const
{
    return pins_.none();
}
uint8_t PinSet::upCount() const
{
    return pins_.count();
}
uint8_t PinSet::downCount() const
{
    return pins_.size() - upCount();
}
