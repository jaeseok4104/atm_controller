#include "atm_interface.h"

bool ATMInterface::Run() {
    if(!CheckInsertCard())
        return false;
    if(!card_information_->CheckPinNumber(InputPINNumber())) {
        return false;
    }

    int selected_acc_list_num = SelectAccount();
    return SelectBehaviorForAccount(selected_acc_list_num);
}

bool ATMInterface::CheckInsertCard() {
    std::string card_id = GetCardID();
    return card_information_->LoadCardInformation(card_id);
}

bool ATMInterface::SelectBehaviorForAccount(int list_num) {
    ATMBehavior behavior = GetBehaviorInput();
    std::pair<bool, uint64_t> result;
    switch (behavior)
    {
    case ATMBehavior::Seebalance:
        result = card_information_->SeeBalance(list_num);
        if(!result.first)
            DisplayError();
        else DisplayBudget(result.second);
        break;
    case ATMBehavior::Deposit:
        result = card_information_->Deposit(list_num, GetNumberPadInput());
        if(!result.first)
            DisplayError();
        else DisplayBudget(result.second);
        break;
    case ATMBehavior::Withdraw:
        result = card_information_->Withdraw(list_num, GetNumberPadInput());
        if(!result.first)
            DisplayError();
        else DisplayBudget(result.second);
        break;
    default:
        DisplayError();
        break;
    }
    return result.first;
}