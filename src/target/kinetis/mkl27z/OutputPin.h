class MKL27ZOutputPin {
public:
  MKL27ZOutputPin(unsigned N) : Num(N) {}

  void init() const {}

  void outputLow() const {}
  void outputHigh() const {}

private:
  unsigned Num;
};
