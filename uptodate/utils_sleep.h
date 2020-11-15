
#include <cstdlib>
#include <ctime>
#include <thread>


class sleep_util {
public:
  static const int SLEEP_TIME = 4;
    
  SleepUtilities() = default;
    
  static void short_sleep(){
    int sleeptime = 1 + (int)(SLEEP_TIME * rand() / RAND_MAX);
    short_sleep(sleeptime);     // sleep between zero and SLEEP_TIME
  }
  
  static void short_sleep(int duration){
    try {
      this_thread::sleep_for(chrono::seconds(duration));
    }
    catch (exception e) { throw e; }
  }
};

