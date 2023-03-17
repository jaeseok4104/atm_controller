#ifndef CARD_INFORMATION_MOCK_H
#define CARD_INFORMATION_MOCK_H

#include "glog/logging.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "gtest/gtest_prod.h"

#include "card_information.h"

class CardInformationMock : public CardInformation {
public:
    MOCK_METHOD1(GetCardInformation, std::vector<AccountNumber>(std::string));
    MOCK_METHOD1(SendPinNumberCheckMessageOfAccount, bool(int));
    MOCK_METHOD1(GetBudgetOfAccount, std::pair<bool, uint64_t>(std::string));
    MOCK_METHOD2(SendDepositMessageOfAccount, std::pair<bool, uint64_t>(std::string, uint64_t));
    MOCK_METHOD2(SendWithdrawMessageOfAccount, std::pair<bool, uint64_t>(std::string, uint64_t));
};

#endif // CARD_INFORMATION_MOCK_H