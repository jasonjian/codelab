#include <stdio.h>

namespace shape {

class shape {
public:
  virtual ~shape() {}
};

class circle : public shape {
public:
  circle() { puts("circle()"); }
  ~circle() { puts("~circle()"); }
};

class triangle : public shape {

public:
  triangle() { puts("triangle()"); }
  ~triangle() { puts("~triangle()"); }
};

class result {
public:
  result() { puts("result()"); }
  ~result() { puts("~result()"); }
};

    void test();

} // namespace shape
