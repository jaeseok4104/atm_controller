#ifndef CARD_INFORMATION_H
#define CARD_INFORMATION_H
#include <iostream>
#include <vector>
#include <utility>
#include <string>

using AccountNumber = std::string;

class CardInformation {
public:
    CardInformation(){
        correct_pin_number_ = false;
    };
    bool CheckPinNumber(int pin_number);
    bool LoadCardInformation(std::string card_id);

    std::pair<bool, uint64_t> SeeBalance(int list_number);
    std::pair<bool, uint64_t> Deposit(int list_number, uint64_t deposit_money);
    std::pair<bool, uint64_t> Withdraw(int list_number, uint64_t with_draw_money);
protected:
    virtual std::vector<AccountNumber> GetCardInformation(std::string card_id) = 0;
    virtual bool SendPinNumberCheckMessageOfAccount(int pin_number) = 0;
    virtual std::pair<bool, uint64_t> GetBudgetOfAccount(std::string account_number) = 0;
    virtual std::pair<bool, uint64_t> SendDepositMessageOfAccount(std::string account_number, uint64_t deposit_money) = 0;
    virtual std::pair<bool, uint64_t> SendWithdrawMessageOfAccount(std::string account_number, uint64_t with_draw_money) = 0;
    
    std::string card_id;
    std::vector<AccountNumber> accounts_;
    bool correct_pin_number_;
};

#endif // CARD_INFORMATION_H