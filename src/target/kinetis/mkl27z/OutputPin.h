class MKL27ZOutputPin {
public:
  MKL27ZOutputPin(unsigned N) : Num(N) {}

 void outputLow() const {}
 void outputHigh() const {}

private:
  unsigned Num;
};
