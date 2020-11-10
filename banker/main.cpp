
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>

#include "customer.h"


int main(int argc, const char* argv[]) {           // TODO   fill in missing code
  // read available resources from command line
  
  std::vector<Customer> customers;
  std::vector<thread>   workers;
  BankImpl              theBank(resources);
  std::vector<int>      maxDemand;
  std::vector<int>      allocated;
  
  int threadNum = 0;
  
  // open input file, and read in resources, bank, and customer data from file
  
  // print state of bank and start threads

  // wait for all threads to complete
  for (int i = 0; i < workers.size(); i++){
      workers[i].join();
  }
}

