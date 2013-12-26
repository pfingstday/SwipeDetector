class SharpIRProximitySensor {

  int _pin;
  int _last;
  int _last2;

  public:
  SharpIRProximitySensor(int pin) {
    _pin = pin;
  }

  int read(void) ;
};