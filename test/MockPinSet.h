//
// Created by Weber on 08.02.21.
//

#ifndef BOWLINGSIMULATOR_MOCKPINSET_H
#define BOWLINGSIMULATOR_MOCKPINSET_H

#include "IPinSet.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class MockPinSet : public IPinSet
{
  public:
    MOCK_METHOD(bool, allUp, (), (const, override));
    MOCK_METHOD(void, knockDown, (const Pin pin), (override));
    MOCK_METHOD(bool, allDown, (), (const, override));
    MOCK_METHOD(uint8_t, upCount, (), (const, override));
    MOCK_METHOD(uint8_t, downCount, (), (const, override));

//    bool isDown(const Pin pin) const override
//    {
//        return false;
//    }
//    bool isUp(const Pin pin) const override
//    {
//        return false;
//    }
//    bool allDown() const override
//    {
//        return false;
//    }
};
#endif//BOWLINGSIMULATOR_MOCKPINSET_H
