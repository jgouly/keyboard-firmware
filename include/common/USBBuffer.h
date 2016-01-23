#ifndef COMMON_USB_BUFFER_H
#define COMMON_USB_BUFFER_H

class USBBuffer {
  constexpr static unsigned MAX_BUFFER_SIZE = 6;
public:
  void push_back(unsigned val) {
   if (counter < MAX_BUFFER_SIZE) {
      data[counter++] = val;
    }
  }
  const unsigned *getData() const {
    return data;
  }
  unsigned size() const {
    return counter;
  }
private:
  unsigned counter = 0;
  unsigned data[MAX_BUFFER_SIZE];
};

#endif
