//
// Created by @mikhirurg on 14.07.2020.
//

#include "../../MinGW/lib/gcc/mingw32/8.2.0/include/c++/cstddef"
#include "../../MinGW/lib/gcc/mingw32/8.2.0/include/c++/iostream"
struct Visitor;
struct Number;
struct BinaryOperation;

struct Expression {
  virtual double evaluate() const = 0;
  virtual void visit(Visitor *visitor) const = 0;
  virtual ~Expression() = default;
};

struct Visitor {
  virtual void visitNumber(Number const *number) = 0;
  virtual void visitBinaryOperation(BinaryOperation const *operation) = 0;
  virtual ~Visitor() = default;
};

struct Number : Expression {
  Number(double value)
      : value(value) {}

  double evaluate() const override {
    return value;
  }

  double get_value() const { return value; }

  void visit(Visitor *visitor) const { visitor->visitNumber(this); }

 private:
  double value;
};

struct BinaryOperation : Expression {

  BinaryOperation(Expression const *left, char op, Expression const *right)
      : left(left), op(op), right(right) {}

  ~BinaryOperation() override {
    delete left;
    delete right;
  }

  double evaluate() const override {
    if (op == '+') {
      return left->evaluate() + right->evaluate();
    } else if (op == '-') {
      return left->evaluate() - right->evaluate();
    } else if (op == '*') {
      return left->evaluate() * right->evaluate();
    } else if (op == '/') {
      return left->evaluate() / right->evaluate();
    }
    return -1;
  }

  Expression const *get_left() const { return left; }
  Expression const *get_right() const { return right; }
  char get_op() const { return op; }

  void visit(Visitor *visitor) const { visitor->visitBinaryOperation(this); }

 private:
  Expression const *left;
  Expression const *right;
  char op;
};

struct PrintVisitor : Visitor {
  void visitNumber(Number const *number) {
    std::cout << number->get_value();
  }

  void visitBinaryOperation(BinaryOperation const *bop) {
    std::cout << "(";
    bop->get_left()->visit(this);
    std::cout << " " << bop->get_op() << " ";
    bop->get_right()->visit(this);
    std::cout << ")";
  }
};

struct SharedPtr {

  struct Counter {

    Counter()
        : count_(1) {}

    int count_;
  };

  // реализуйте следующие методы
  //
  explicit SharedPtr(Expression *ptr = 0)
      : ptr_(ptr) {
    counter_ = new Counter();
  }

  ~SharedPtr() {
    counter_->count_--;
    if (counter_->count_ == 0) {
      delete counter_;
      delete ptr_;
    }
  }

  SharedPtr(const SharedPtr &ptr)
      : ptr_(ptr.ptr_), counter_(ptr.counter_) {
    if (ptr_ != nullptr) {
      counter_->count_++;
    }
  }

  SharedPtr &operator=(const SharedPtr &ptr) {
    if (this == &ptr) {
      return *this;
    }

    this->counter_->count_--;
    if (counter_->count_ == 0) {
      delete ptr_;
      delete counter_;
    }

    ptr.counter_->count_++;

    ptr_ = ptr.ptr_;
    counter_ = ptr.counter_;

    return *this;
  }

  Expression *get() const {
    return ptr_;
  }

  void reset(Expression *ptr = 0) {
    if (ptr != ptr_) {
      counter_->count_--;
      if (counter_->count_ == 0) {
        delete ptr_;
        delete counter_;
      }
      ptr_ = ptr;
      counter_ = new Counter();
    } else {
      counter_->count_ = 1;
    }
  }

  Expression &operator*() const {
    return *ptr_;
  }

  Expression *operator->() const {
    return ptr_;
  }

 private:
  Expression *ptr_;
  Counter *counter_;
};

int main() {

  SharedPtr p1;
  {
    SharedPtr p2(new Number(1));
    SharedPtr p3(new Number(2));
    SharedPtr p4(p2);
    SharedPtr p5;
    p5 = p2;
    p5 = p4;
    p1 = p5;
    p3.reset(NULL);
    p3 = p5;
    p5.reset(NULL);
    SharedPtr p6;
    SharedPtr p7;
    p7 = p7;
    p7.reset(NULL);
    p7.reset(new Number(3));
    SharedPtr p8(new Number(4));
    p8.reset(NULL);
  }
  p1 = p1;

  return 0;
}