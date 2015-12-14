#ifndef Repository_h
  #define Repository_h

  #include <StandardCplusplus.h>
  #include <string>
  #include <vector>

  using namespace std;

  class Repository {
  
    vector <Pin> controlledPins;

    // Init Button Input Session idle

    public:
      Repository();
      Repository(Pin controlledPins[]);
      Pin getPin(string name);
      Pin getPin(int pinNumber);
      void add(Pin pin);
      void remove(Pin pin);
    
    private:
      Pin find(string identity);
      Pin find(int pinNumber);
    
  };

#endif
