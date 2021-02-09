//
// Created by Weber on 07.02.21.
//

#ifndef BOWLINGSIMULATOR_PINSET_H
#define BOWLINGSIMULATOR_PINSET_H

#include <IPinSet.h>
#include <bitset>

class PinSet : public IPinSet
{
    public:
    [[nodiscard]] bool allUp() const override;
    void knockDown(const Pin pin) override;

    [[nodiscard]] bool isDown(const Pin pin) const ;

    [[nodiscard]] bool isUp(const Pin pin) const ;

    [[nodiscard]] bool allDown() const override;

    [[nodiscard]] uint8_t upCount() const override;

    [[nodiscard]] uint8_t downCount() const override;

    private:
    std::bitset<Pin::MAX> pins_{0b11'1111'1111};
};


#endif//BOWLINGSIMULATOR_PINSET_H
