#include "card_information.h"

bool CardInformation::CheckPinNumber(int pin_number) {
    return SendPinNumberCheckMessageOfAccount(pin_number);
}

bool CardInformation::LoadCardInformation(std::string card_id) {
    accounts_ = GetCardInformation(card_id);
    return !accounts_.empty();
};

std::pair<bool, uint64_t> CardInformation::SeeBalance(int list_number) {
    AccountNumber& acc = accounts_.at(list_number);
    
    std::pair<bool, uint64_t> result = GetBudgetOfAccount(acc);
    if(!result.first)
        return std::pair<bool, uint64_t>(false, 0);
    return result;
}

std::pair<bool, uint64_t> CardInformation::Deposit(int list_number, uint64_t deposit_money) {    
    AccountNumber& acc = accounts_.at(list_number);
    std::pair<bool, uint64_t> result = SendDepositMessageOfAccount(acc, deposit_money);
    if(!result.first)
        return std::pair<bool, uint64_t>(false, 0);
    return result;
}

std::pair<bool, uint64_t> CardInformation::Withdraw(int list_number, uint64_t with_draw_money) {
    AccountNumber& acc = accounts_.at(list_number);
    std::pair<bool, uint64_t> result = SendWithdrawMessageOfAccount(acc, with_draw_money);
    if(!result.first)
        return std::pair<bool, uint64_t>(false, 0);
    return result;
}