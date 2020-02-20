#include <iostream>
using namespace std;

class A {
 protected:
  virtual void h() { cout << " A::h "; }

 public:
  virtual void g() const { cout << " A::g "; }
  virtual void f() {
    cout << " A::f ";
    g();
    h();
  }
  void m() {
    cout << " A::m ";
    g();
    h();
  }
  virtual void k() {
    cout << " A::k ";
    h();
    m();
  }
  virtual A* n() {
    cout << " A::n ";
    return this;
  }
};

class B : public A {
 protected:
  virtual void h() { cout << " B::h "; }

 public:
  virtual void g() { cout << " B::g "; }
  void m() {
    cout << " B::m ";
    g();
    h();
  }
  void k() {
    cout << " B::k ";
    g();
    h();
  }
  B* n() {
    cout << " B::n ";
    return this;
  }
};

class C : public B {
 protected:
  virtual void h() const { cout << " C::h "; }

 public:
  virtual void g() { cout << " C::g "; }
  void m() {
    cout << " C::m ";
    g();
    h();
  }
  void k() {
    cout << " C::k ";
    h();
  }
};

int main() {
  A* p2 = new B();
  A* p3 = new C();
  B* p4 = new B();
  B* p5 = new C();
  const A* p6 = new C();

  // p2->f();
  // p2->m();
  p3->k();
  // p3->f();
  // p4->m();
  // p4->k();
  // p4->g();
  // p5->g();
}

class C {
  int a;
  float b;
  C& operator=(const C& c) {
    a = c.a;
    b = c.b;
    return *this;
  }
};

class D {};
class F : public D {
  F(const F& f) : D(f), l(f.l), ref(f.ref), p(f.p) {}
};