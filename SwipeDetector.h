
class SwipeDetector {
public:
enum Swipe {
    SWIPE_NONE,
    SWIPE_LEFT,
    SWIPE_RIGHT
  };

SwipeDetector() {
  z = REST;
}

  Swipe detect(int left, int right);
private:
char last_t;
char last2_t;


enum Zustand {
  REST,
  Z1,
  Z2,
  Z3,
  Z4,
  Z5,
  Z6,
};

Zustand z;


static const char T00 = 0;
static const char T01 = 1;
static const char T10 = 2;
static const char T11 = 3;

Swipe filter(char t);

  bool isTriggered(int distance);
Swipe stateMachineInternal(char t);


};