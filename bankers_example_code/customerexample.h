//
//  customerexample.h
//  bankers
//
//  Created by William McCarthy on 1011//20.
//

#ifndef customerexample_h
#define customerexample_h

#include "bankexample.h"

class BankExample;


class CustomerExample {
public:
//  CustomerExample() = default;
  CustomerExample(int index, const ext_vector<int>& allocate, const ext_vector<int>& maximum,
                  BankExample* bank_=nullptr)
  : idx(index), alloc(allocate), max_(maximum), need(max_ - alloc), bank(bank_) { }
  
  bool needs_met() const { return alloc == max_; }
  
  void show() const {
    std::cout << "P#" << idx << "    " << alloc << "    " << max_ << "    " << need << "\n";
  }
  
  ext_vector<int> create_req() { /* TODO */ }
  
private:
  int idx;
  ext_vector<int> alloc;
  ext_vector<int> max_;
  ext_vector<int> need;

  BankExample* bank;
};

#endif /* customerexample_h */
