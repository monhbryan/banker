#include "bankImpl.h"
#include "utils_sleep.h"


class Customer {
private:
  int customerNum;
  int numOfResources;
  std::vector<int> maxDemand;
  std::vector<int> request;
  BankImpl* theBank;
    
  bool isAllZero(){

  }
public:
    Customer(int customerNum, std::vector<int>& maxDemand, BankImpl& theBank);
    void operator()();
};
