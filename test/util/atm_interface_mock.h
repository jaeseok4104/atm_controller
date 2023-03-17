#ifndef ATM_INTERFACE_MOCK_H
#define ATM_INTERFACE_MOCK_H

#include "glog/logging.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "gtest/gtest_prod.h"

#include "atm_interface.h"

class ATMInterfaceMock : public ATMInterface {
public:
    ATMInterfaceMock(std::shared_ptr<CardInformation> card_info) : ATMInterface(card_info) {};
    MOCK_METHOD0(Initialize, bool());
    MOCK_METHOD0(GetCardID, std::string());
    MOCK_METHOD0(InputPINNumber, int());
    MOCK_METHOD0(SelectAccount, int());
    MOCK_METHOD0(GetBehaviorInput, ATMBehavior());
    MOCK_METHOD0(GetNumberPadInput, int());
    MOCK_METHOD1(DisplayBudget, void(uint64_t));
    MOCK_METHOD0(DisplayError, void());
};

#endif // ATM_INTERFACE_MOCK_H