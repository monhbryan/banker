
#include "bank.h"
#include <string>
#include <iostream>
#include <thread>
#include <mutex>


class BankImpl : public Bank {
private:
  int numOfThreads;
  int numOfResources;
  
  std::vector<int> available;
  std::vector<std::vector<int>> maximum;
  std::vector<std::vector<int>> allocation;
  std::vector<std::vector<int>> need;
  std::vector<bool> finished;
  std::mutex lock;
    
  void showAllMatrices(const std::vector<std::vector<int>>& alloc,
                       const std::vector<std::vector<int>>& max,
                       const std::vector<std::vector<int>>& need, const std::string& msg);
  void showVector(std::vector<int>& vect, std::string msg, bool finished = false);
  bool isAvailable(const std::vector<int>& resource);

  void allocate(int threadNum,   std::vector<int>& resource)
  void deallocate(int threadNum, std::vector<int>& resource);
  bool hasMaximum(int threadNum);
  bool isProcessFinished();
  std::vector<int> cpath;

  bool isSafeState(int threadNum, std::vector<int>& request);
        
public:
  BankImpl(std;:vector<int>& resources);
  void addCustomer(int threadNum, std::vector<int>& maxDemand, std::vector<int>& allocated);
  void getState() {

  int requestResources(int threadNum, std::vector<int>& request);
  bool releaseResources(int threadNum);
};
