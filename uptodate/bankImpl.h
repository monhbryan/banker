
#include "bank.h"
#include <string>
#include <iostream>
#include <thread>
#include <mutex>


class BankImpl : public Bank {
private:
  int numOfThreads; // the number of threads in the system
  int numOfResources; // the number of resources
  
  std::vector<int> available; // the amount available of each resource
  std::vector<std::vector<int>> maximum; // the maximum demand of each thread
  std::vector<std::vector<int>> allocation; // the amount currently allocated to each thread
  std::vector<std::vector<int>> need; // the remaining needs of each thread
  std::vector<bool> finished;
  std::mutex lock;
    
  void showAllMatrices(std::vector<std::vector<int>>& alloc,
                      std::vector<std::vector<int>>& max,
                      std::vector<std::vector<int>>& need, const std::string& msg){
    // TODO
    std::cout << msg;
    for(int i = 0 ; i < numOfThreads ; i++){
        std::cout << std::endl << "\t";
        showVector(alloc[i], "", finished[i]);
        std::cout << "    ";
        showVector(max[i], "", finished[i]);
        std::cout << "     ";
        showVector(need[i], "", finished[i]);

    }
    std::cout << std::endl;

  }

  void showVector(std::vector<int>& vect, std::string msg, bool finished = false){
    // TODO
    if (finished == true){
      std::cout << "-----------finished--------";
      return;
    }
    std::cout << msg << "{";
    for(int i = 0; i < vect.size() ; i++ ){
        std::cout << vect[i] << " ";
    }
    std::cout << "}";
  }

  bool isAvailable(const std::vector<int>& resource){
    //TODO
    for (int i = 0; i< resource.size(); i++){
      if(resource[i] > available[i]){
        return false;
      }
    }
    return true;
  }

  void allocate(int threadNum,   std::vector<int>& resource){
    //TODO
    for(int i =0; i < resource.size() ; i++){
        available[i] -= resource[i];
        allocation[threadNum][i] += resource[i];
        need[threadNum][i] -= resource[i];
    }
  }
  void deallocate(int threadNum, std::vector<int>& resource){
    //TODO
    for (int i = 0; i < resource.size() ; i++){
        available[i] += resource[i];
        allocation[threadNum][i] -= resource[i];
        need[threadNum][i] += resource[i];
    }
  }
  bool hasMaximum(int threadNum){
    //TODO
    bool max = true;
    for(int i = 0; i< allocation[threadNum].size() ; i++){
      if(allocation[threadNum][i] < maximum[threadNum][i]){
        max = false;
      }
    }
    return max;
  }
  bool isProcessFinished(){
    //TODO
    bool check = true;
    for(int i =0 ; i < numOfThreads ; i++){
      if(finished[i] == false){
        check = false;
      }
    }
    return check;
  }
  std::vector<int> cpath;

  bool isSafeState(int threadNum, std::vector<int>& request){
    //TODO
    if (isAvailable(request) == false){
      return false; 
    }

    std::vector<int> originalAlloc = allocation[threadNum];
    bool isSafe = false;

    allocate(threadNum, request);

    if(hasMaximum(threadNum) == true) { // Success (allocation = max)
        deallocate(threadNum, allocation[threadNum]);
        finished[threadNum] = true;
    }

    // 2. Find index i such that :
      // Finish[i] == false
      // Need i <= work;
      // if no such i exists, system is safe

        // 3. Work = Work + Alloc
        // Finish[i] = True
        // Go to step 2


// 4. If Finish [i] == true for all i; system is safe

}

public:
  BankImpl(std::vector<int>& resources){
    // Create a new bank (w/ resources)
    available = resources;
    numOfThreads = 0;
  }

  void addCustomer(int threadNum, std::vector<int>& maxDemand, std::vector<int>& allocated){
   // ADD Customers to bank
    allocation.push_back(allocated);
    maximum.push_back(maxDemand);
    std::vector<int> needVector;
    for(int i = 0; i < allocated.size(); i++){
      needVector.push_back(maxDemand[i] - allocated[i]);
    }
    need.push_back(needVector);
    finished.push_back(false);
    numOfThreads++;
  }

  void getState(){
    // outputs available, allocation, max and need matrices for each thread
    std::cout << std::endl;
    showVector(available, "Available: ");
    std::cout << std::endl;
    showAllMatrices(allocation, maximum, need, "");
    std::cout << std::endl;

  }


  int requestResources(int threadNum, std::vector<int>& request){
  // Requests rscs, specify # of customer being added. Block until req is satisfied safely.

  std::lock_guard<std::mutex> mutexlock(lock);

  for(int i = 0; i< request.size() ; i++){
    if(request[i] > available[i] || request[i] > available[i]){return -1;}
  }

  printf("#P %d ", threadNum);
  showVector(request, "RQ: ");
  showVector(need[threadNum], ", Needs: ");
  showVector(available, ", Available: ");


  if(isSafeState(threadNum, request) == true){ 
    allocate(threadNum, request);
    printf("Approved: %d", threadNum);
    showVector(allocation[threadNum], " now at: ");
    std::cout << std::endl;
    getState();
    return 1;
  }
  else{
    std::cout << " Denied" << std::endl;
    return 0;
  }
  }

  bool releaseResources(int threadNum){
   // Release Rscs
  std::lock_guard<std::mutex> mutexlock(lock);

  if (hasMaximum(threadNum) == false){
    return false;
  }
  printf("------>#P%d has all of the resources required!", threadNum);
  printf("---------\ncust#: %d", threadNum);
  showVector(allocation[threadNum], " releasing: ");

  deallocate(threadNum, allocation[threadNum]);
  finished[threadNum] = true;
  return true;
  }

};
