#ifndef ATM_INTERFACE_H
#define ATM_INTERFACE_H

#include <iostream>
#include <string>
#include <atomic>
#include <memory>

#include "atm_status.h"
#include "card_information.h"

enum ATMBehavior{
    Seebalance,
    Deposit,
    Withdraw
};

class ATMInterface : public ATMStatus {
public:
    explicit ATMInterface(std::shared_ptr<CardInformation> card_information) {
        card_information_ = card_information;
    }
    virtual bool Initialize() = 0;
    bool Run();
private:
    bool CheckInsertCard();
    bool SelectBehaviorForAccount(int list_num);
    virtual std::string GetCardID() = 0;
    virtual int InputPINNumber() = 0;
    virtual int SelectAccount() = 0;
    virtual ATMBehavior GetBehaviorInput() = 0;
    virtual int GetNumberPadInput() = 0;
    virtual void DisplayBudget(uint64_t budget) = 0;
    virtual void DisplayError() = 0;

    std::atomic<bool> process_flag_;
    std::shared_ptr<CardInformation> card_information_;
};

#endif // ATM_INTERFACE_H