
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <string>
#include "customer.h"

int main(int argc, const char* argv[]) {           // TODO   fill in missing code
  // read available resources from command line
  std::string line;
  std::fstream inFile;
  inFile.open("bankers_tiny.txt");
  if(inFile.is_open()){
    std::getline(inFile, line);
  }
  inFile.close();

  std::vector<int> resources;
  std::string delimiter = ",";
  std::string token;
  int counter = 0; //how many individual threads per process
  int pos = 0;
  while( pos = line.find(delimiter) != std::string::npos ){
    token = line.substr(0,pos);
    resources.push_back(stoi(token));
    line.erase(0, pos+delimiter.length());
    counter++;
  }

  std::vector<Customer> customers;
  std::vector<std::thread>   workers;
  BankImpl              theBank(resources);
  std::vector<int>      maxDemand;
  std::vector<int>      allocated;
  
  int threadNum = 0;
  
  // open input file, and read in resources, bank, and customer data from file
    std::vector<std::string> 
    while(std::getline(inFile, line)){

    }

    inFile.close();
  // print state of bank and start threads

  // wait for all threads to complete
  for (int i = 0; i < workers.size(); i++){
      workers[i].join();
  }
}

