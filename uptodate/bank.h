#include <vector>

class Bank {
public:
    virtual void addCustomer(int threadNum, std::vector<int>& maxDemand,
                             std::vector<int>& allocated) = 0;
    virtual void getState() = 0;
    
    virtual int requestResources(int threadNum, std::vector<int>& request) = 0;
    virtual bool releaseResources(int threadNum) = 0;
};











