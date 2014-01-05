#include <string.h>


class SharpIRProximitySensor {
static const int NUM_LAST = 3;

  int _hist[NUM_LAST];
  int _curr;
  int _pin;


  void inc();
  int filter(int);

  public:
  SharpIRProximitySensor(int pin) {
    _pin = pin;
    _curr = 0;
    clear();
  }

  void clear(void);

  int read(void) ;
};