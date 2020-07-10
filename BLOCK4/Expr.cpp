//
// Created by @mikhirurg on 07.07.2020.
//

#include <iostream>

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
  virtual ~Visitor() {}
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

bool check_equals(Expression const *left, Expression const *right) {
  return *(int **) left == *(int **) right;
}

int main() {

  Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));

  Expression *expr = new BinaryOperation(new Number(3), '+', sube);

  // std::cout << check_equals(sube, new Number(1)) << std::endl;

  PrintVisitor *visitor = new PrintVisitor();
  visitor->visitBinaryOperation(dynamic_cast<const BinaryOperation *>(expr));

  std::cout << std::endl;

  std::cout << expr->evaluate() << std::endl;

  delete expr;
  delete visitor;
  return 0;
}