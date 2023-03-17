#include "../test/util/card_information_mock.h"
#include "../test/util/atm_interface_mock.h"

using ::testing::_;
using ::testing::AnyNumber;
using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

class ATMInterfaceTest : public ::testing::Test {
protected:
  std::shared_ptr<CardInformationMock> card_infor_mock_;
  std::shared_ptr<ATMInterfaceMock> atm_obj_;

  void SetUp() override {
    card_infor_mock_ = std::make_shared<CardInformationMock>();
    atm_obj_ = std::make_shared<ATMInterfaceMock>(card_infor_mock_);
    test_account_.emplace_back("1111");
    test_account_budget_ = std::pair<bool, uint64_t>(true, 10000);
    test_account_budget2_ = std::pair<bool, uint64_t>(false, 10000);
  }
  std::vector<AccountNumber> test_account_;
  std::pair<bool, uint64_t> test_account_budget_;
  std::pair<bool, uint64_t> test_account_budget2_;
};

TEST_F(ATMInterfaceTest, FullTest1) {
  EXPECT_CALL(*atm_obj_, GetCardID())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return("test")));
  EXPECT_CALL(*card_infor_mock_, GetCardInformation("test"))
    .Times(AtLeast(1))
    .WillOnce(Return(test_account_));
  EXPECT_CALL(*atm_obj_, InputPINNumber())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(1234)));
  EXPECT_CALL(*card_infor_mock_, SendPinNumberCheckMessageOfAccount(1234))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(true)));
  EXPECT_CALL(*atm_obj_, SelectAccount())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(0)));
  EXPECT_CALL(*atm_obj_, GetBehaviorInput())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(Seebalance)));
  EXPECT_CALL(*card_infor_mock_, GetBudgetOfAccount("1111"))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(test_account_budget_)));
  EXPECT_CALL(*atm_obj_, DisplayBudget(test_account_budget_.second))
    .Times(AtLeast(1));
  EXPECT_EQ(true, atm_obj_->Run());
}

TEST_F(ATMInterfaceTest, FullTest2) {
  EXPECT_CALL(*atm_obj_, GetCardID())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return("test")));
  EXPECT_CALL(*card_infor_mock_, GetCardInformation("test"))
    .Times(AtLeast(1))
    .WillOnce(Return(test_account_));
  EXPECT_CALL(*atm_obj_, InputPINNumber())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(1234)));
  EXPECT_CALL(*card_infor_mock_, SendPinNumberCheckMessageOfAccount(1234))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(true)));
  EXPECT_CALL(*atm_obj_, SelectAccount())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(0)));
  EXPECT_CALL(*atm_obj_, GetBehaviorInput())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(Deposit)));
  EXPECT_CALL(*atm_obj_, GetNumberPadInput())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(5000)));
  EXPECT_CALL(*card_infor_mock_, SendDepositMessageOfAccount("1111", 5000))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(test_account_budget_)));
  EXPECT_CALL(*atm_obj_, DisplayBudget(test_account_budget_.second))
    .Times(AtLeast(1));
  EXPECT_EQ(true, atm_obj_->Run());
}

TEST_F(ATMInterfaceTest, FullTest3) {
  EXPECT_CALL(*atm_obj_, GetCardID())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return("test")));
  EXPECT_CALL(*card_infor_mock_, GetCardInformation("test"))
    .Times(AtLeast(1))
    .WillOnce(Return(test_account_));
  EXPECT_CALL(*atm_obj_, InputPINNumber())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(1234)));
  EXPECT_CALL(*card_infor_mock_, SendPinNumberCheckMessageOfAccount(1234))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(true)));
  EXPECT_CALL(*atm_obj_, SelectAccount())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(0)));
  EXPECT_CALL(*atm_obj_, GetBehaviorInput())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(Withdraw)));
  EXPECT_CALL(*atm_obj_, GetNumberPadInput())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(5000)));
  EXPECT_CALL(*card_infor_mock_, SendWithdrawMessageOfAccount("1111", 5000))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(test_account_budget_)));
  EXPECT_CALL(*atm_obj_, DisplayBudget(test_account_budget_.second))
    .Times(AtLeast(1));
  EXPECT_EQ(true, atm_obj_->Run());
}

TEST_F(ATMInterfaceTest, FullTest4) {
  EXPECT_CALL(*atm_obj_, GetCardID())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return("test")));
  EXPECT_CALL(*card_infor_mock_, GetCardInformation("test"))
    .Times(AtLeast(1))
    .WillOnce(Return(test_account_));
  EXPECT_CALL(*atm_obj_, InputPINNumber())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(1234)));
  EXPECT_CALL(*card_infor_mock_, SendPinNumberCheckMessageOfAccount(1234))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(true)));
  EXPECT_CALL(*atm_obj_, SelectAccount())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(0)));
  EXPECT_CALL(*atm_obj_, GetBehaviorInput())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(Seebalance)));
  EXPECT_CALL(*card_infor_mock_, GetBudgetOfAccount("1111"))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(test_account_budget2_)));
  EXPECT_CALL(*atm_obj_, DisplayError())
    .Times(AtLeast(1));
  EXPECT_EQ(false, atm_obj_->Run());
}

TEST_F(ATMInterfaceTest, FullTest5) {
  EXPECT_CALL(*atm_obj_, GetCardID())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return("test")));
  EXPECT_CALL(*card_infor_mock_, GetCardInformation("test"))
    .Times(AtLeast(1))
    .WillOnce(Return(test_account_));
  EXPECT_CALL(*atm_obj_, InputPINNumber())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(1234)));
  EXPECT_CALL(*card_infor_mock_, SendPinNumberCheckMessageOfAccount(1234))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(true)));
  EXPECT_CALL(*atm_obj_, SelectAccount())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(0)));
  EXPECT_CALL(*atm_obj_, GetBehaviorInput())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(Deposit)));
  EXPECT_CALL(*atm_obj_, GetNumberPadInput())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(5000)));
  EXPECT_CALL(*card_infor_mock_, SendDepositMessageOfAccount("1111", 5000))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(test_account_budget2_)));
  EXPECT_CALL(*atm_obj_, DisplayError())
    .Times(AtLeast(1));
  EXPECT_EQ(false, atm_obj_->Run());
}

TEST_F(ATMInterfaceTest, FullTest6) {
  EXPECT_CALL(*atm_obj_, GetCardID())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return("test")));
  EXPECT_CALL(*card_infor_mock_, GetCardInformation("test"))
    .Times(AtLeast(1))
    .WillOnce(Return(test_account_));
  EXPECT_CALL(*atm_obj_, InputPINNumber())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(1234)));
  EXPECT_CALL(*card_infor_mock_, SendPinNumberCheckMessageOfAccount(1234))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(true)));
  EXPECT_CALL(*atm_obj_, SelectAccount())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(0)));
  EXPECT_CALL(*atm_obj_, GetBehaviorInput())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(Withdraw)));
  EXPECT_CALL(*atm_obj_, GetNumberPadInput())
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(15000)));
  EXPECT_CALL(*card_infor_mock_, SendWithdrawMessageOfAccount("1111", 15000))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Return(test_account_budget2_)));
  EXPECT_CALL(*atm_obj_, DisplayError())
    .Times(AtLeast(1));
  EXPECT_EQ(false, atm_obj_->Run());
}