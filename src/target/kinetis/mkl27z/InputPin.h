class MKL27ZInputPin {
public:
  MKL27ZInputPin(unsigned N) : Num(N) {}

  unsigned readInput() const { return 0; }

private:
  unsigned Num;
};
