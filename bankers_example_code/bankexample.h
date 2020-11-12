//
//  bankexample.h
//  bankers
//
//  Created by William McCarthy on 1011//20.
//

#ifndef bankexample_h
#define bankexample_h

#include "customerexample.h"


class BankExample {
public:
  BankExample() = default;
  BankExample(const ext_vector<int>& available) : avail(available), customers() { }
  
  ext_vector<int> get_avail() const { return avail; }

  void add_customer(CustomerExample* c) { customers.push_back(c); }

  ext_vector<CustomerExample*> get_customers() const { return customers; }
  
  void show() const {
    std::cout << "avail: [" << avail << "]\n";
    for (CustomerExample* c : customers) {
      c->show();
    }
  }
  
  friend std::ostream& operator<<(std::ostream& os, const BankExample& be) {
    be.show();
    return os;
  }

private:
  ext_vector<int> avail;
  ext_vector<CustomerExample*> customers;
};

#endif /* bankexample_h */
