#ifndef ATM_STATUS_H
#define ATM_STATUS_H
#include <iostream>
#include <string>
#include <atomic>
#include <memory>

class ATMStatus {
private:
    uint64_t money_bin_;
};

#endif // ATM_STATUS_H