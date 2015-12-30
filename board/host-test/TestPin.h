#ifndef TEST_PIN_H
#define TEST_PIN_H

class TestInputPin {
public:
  TestInputPin(unsigned constantVal) : constantVal(constantVal) {}
  void init() const {}
  unsigned readInput() const { return constantVal; }

private:
  unsigned constantVal;
};

class TestOutputPin {
public:
  TestOutputPin() {}
  void init() const {}
  void outputHigh() const {}
  void outputLow() const {}
};

#endif
