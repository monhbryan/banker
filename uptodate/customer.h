#include "bankImpl.h"
#include "utils_sleep.h"


class Customer {
private:
  int customerNum;
  int numOfResources;
  std::vector<int> maxDemand;
  std::vector<int> request;
  BankImpl* theBank;
    
  //bool isAllZero(){}
public:
    Customer(int customerNum, std::vector<int>& maxDemand, BankImpl& theBank){}
    Customer(int index, const ext_vector<int>& allocate, const ext_vector<int>& maximum,
                  BankExample* bank_=nullptr)
  : idx(index), alloc(allocate), max_(maximum), need(max_ - alloc), bank(bank_) { }
    void operator()();
};
