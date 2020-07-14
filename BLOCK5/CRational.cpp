//
// Created by @mikhirurg on 13.07.2020.
//

#include <iostream>

struct Rational {
  Rational(int numerator = 0, int denominator = 1)
      : numerator_(numerator), denominator_(denominator) {}

  void add(Rational rational) {
    int new_numerator = numerator_ * rational.denominator_ + denominator_ * rational.numerator_;
    int new_denominator = denominator_ * rational.denominator_;

    numerator_ = new_numerator;
    denominator_ = new_denominator;
  }

  void sub(Rational rational) {
    int new_numerator = numerator_ * rational.denominator_ - denominator_ * rational.numerator_;
    int new_denominator = denominator_ * rational.denominator_;

    numerator_ = new_numerator;
    denominator_ = new_denominator;
  }

  void mul(Rational rational) {
    int new_numerator = numerator_ * rational.numerator_;
    int new_denominator = denominator_ * rational.denominator_;

    numerator_ = new_numerator;
    denominator_ = new_denominator;
  }

  void div(Rational rational) {
    int new_numerator = numerator_ * rational.denominator_;
    int new_denominator = denominator_ * rational.numerator_;

    numerator_ = new_numerator;
    denominator_ = new_denominator;
  }

  void neg() {
    numerator_ = -numerator_;
  }

  void inv() {
    int tmp = numerator_;
    numerator_ = denominator_;
    denominator_ = tmp;
  }

  double to_double() const {
    return double(numerator_) / denominator_;
  }

  operator double() const {
    return to_double();
  }

  Rational &operator+=(int a) {
    Rational tmp(a, 1);
    add(tmp);
    return *this;
  }

  Rational &operator-=(int a) {
    Rational tmp(a, 1);
    sub(tmp);
    return *this;
  }

  Rational &operator*=(int a) {
    Rational tmp(a, 1);
    mul(tmp);
    return *this;
  }

  Rational &operator/=(int a) {
    Rational tmp(a, 1);
    div(tmp);
    return *this;
  }

  Rational operator+() const {
    return Rational(numerator_, denominator_);
  }

  Rational operator-() const {
    Rational tmp(numerator_, denominator_);
    tmp.neg();
    return tmp;
  }

  Rational &operator+=(const Rational a) {
    add(a);
    return *this;
  }

  Rational &operator-=(const Rational a) {
    sub(a);
    return *this;
  }

  Rational &operator*=(const Rational a) {
    mul(a);
    return *this;
  }

  Rational &operator/=(const Rational a) {
    div(a);
    return *this;
  }

  bool operator<(Rational const &rhs) const {
    return numerator_ * rhs.denominator_ < denominator_ * rhs.numerator_;
  }

  bool operator==(Rational const &rhs) const {
    return numerator_ * rhs.denominator_ == denominator_ * rhs.numerator_;
  }

 private:
  int numerator_;
  int denominator_;
};

bool operator==(int a, Rational const &rsh) {
  return Rational(a) == rsh;
}

bool operator!=(Rational const &lsh, Rational const &rsh) {
  return !(lsh == rsh);
}

bool operator<(int a, Rational const &rsh) {
  return Rational(a) < rsh;
}

bool operator>(Rational const &lsh, Rational const &rsh) {
  return rsh < lsh;
}

bool operator>=(Rational const &lsh, Rational const &rsh) {
  return !(lsh < rsh);
}

bool operator<=(Rational const &lsh, Rational const &rsh) {
  return !(lsh > rsh);
}

Rational operator-(Rational const &lsh, Rational const &rhs) {
  Rational tmp = Rational(lsh);
  tmp -= rhs;
  return tmp;
}

Rational operator+(Rational const &lsh, Rational const &rhs) {
  Rational tmp = Rational(lsh);
  tmp += rhs;
  return tmp;
}

Rational operator*(Rational const &lsh, Rational const &rhs) {
  Rational tmp = Rational(lsh);
  tmp += rhs;
  return tmp;
}

Rational operator/(Rational const &lsh, Rational const &rhs) {
  Rational tmp = Rational(lsh);
  tmp /= rhs;
  return tmp;
}

int main() {

  Rational rational(5, 1);

  std::cout << (2 / rational).to_double() << std::endl;

  return 0;
}