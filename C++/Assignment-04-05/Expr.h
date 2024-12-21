//
// PART A - Designing ASTs
// Created by Shannen White on 25/11/24.
//

#ifndef EXPR_H
#define EXPR_H

#include <string>
using namespace std;

// PART B - declaration of Visitor class from Visitor.cpp
class Visitor;

// base class (parent)
class Expr {
public:
    // returns a string representation of an expression
    virtual string toStr() = 0; // =0 (pure specifier) makes the virtual function pure

    /**
     * PART B - pure virtual evaluation method
     * @param visitor traverses the ASTs
     */
    virtual double eval(Visitor* visitor) = 0;

    // virtual destructor for base class
    virtual ~Expr() {}
};

// derived class (child) -- BinaryExpr extends Expr
class BinaryExpr : public Expr {
protected:
    // declaring left and right expressions of binary expression
    Expr* leftExpr;
    Expr* rightExpr;
public:
    /**
     * constructor of binary expression that can hold left and right expressions
     * @param left is the left expression of the binary expression
     * @param right is the right expression of the binary expression
     */
    BinaryExpr(Expr* left, Expr* right) : leftExpr(left), rightExpr(right) {}

    /**
     * retrieve the left expression of a binary expression
     * @return a pointer that points to the left expression of a binary expression
     */
    Expr* getLeftExpr() const {
        return leftExpr;
    }

    /**
     * set the left expression of a binary expression
     * @param left is the left expression of the binary expression
     */
    void setLeftExpr(Expr* left) {
        leftExpr = left;
    }

    /**
     * retrieve the right expression of a binary expression
     * @return a pointer that points to the right expression of a binary expression
     */
    Expr* getRightExpr() const {
        return rightExpr;
    }

    /**
     * set the right expression of a binary expression
     * @param right is the right expression of the binary expression
     */
    void setRightExpr(Expr* right) {
        rightExpr = right;
    }

    // virtual destructor for BinaryExpr class (acts as base class for the ASTs)
    virtual ~BinaryExpr() {
        delete leftExpr;
        delete rightExpr;
    }
};

// derived class (grandchild) -- AddExpr extends BinaryExpr
class AddExpr : public BinaryExpr {
public:
    /**
     * constructor for addition of left and right expressions of a binary expression
     * @param left is the left expression of the binary expression
     * @param right is the right expression of the binary expression
     */
    AddExpr(Expr* left, Expr* right) : BinaryExpr(left, right) {}

    // converts expression to string form
    string toStr() override;

    /**
     * PART B - evaluator that traverses the ASTs and outputs the result of the addition expression
     * @param visitor traverses the ASTs
     */
    double eval(Visitor* visitor) override;
};

// derived class (grandchild) -- SubExpr extends BinaryExpr
class SubExpr : public BinaryExpr {
public:
    /**
     * constructor for subtraction of the right expression from the left expression of a binary expression
     * @param left is the left expression of the binary expression
     * @param right is the right expression of the binary expression
     */
    SubExpr(Expr* left, Expr* right) : BinaryExpr(left, right) {}

    // converts expression to string form
    string toStr() override;

    /**
     * PART B - evaluator that traverses the ASTs and outputs the result of the subtraction expression
     * @param visitor traverses the ASTs
     */
    double eval(Visitor* visitor) override;
};

// derived class (grandchild) -- MulExpr extends BinaryExpr
class MulExpr : public BinaryExpr {
public:
    /**
     * constructor for multiplication of left and right expressions of a binary expression
     * @param left is the left expression of the binary expression
     * @param right is the right expression of the binary expression
     */
    MulExpr(Expr* left, Expr* right) : BinaryExpr(left, right) {}

    // converts expression to string form
    string toStr() override;

    /**
     * PART B - evaluator that traverses the ASTs and outputs the result of the multiplication expression
     * @param visitor traverses the ASTs
     */
    double eval(Visitor* visitor) override;
};

// derived class (grandchild) -- DivExpr extends BinaryExpr
class DivExpr : public BinaryExpr {
public:
    /**
     * constructor for division of left expression by right expression of a binary expression
     * @param left is the left expression of the binary expression
     * @param right is the right expression of the binary expression
     */
    DivExpr(Expr* left, Expr* right) : BinaryExpr(left, right) {}

    // converts expression to string form
    string toStr() override;

    /**
     * PART B - evaluator that traverses the ASTs and outputs the result of the division expression
     * @param visitor traverses the ASTs
     */
    double eval(Visitor* visitor) override;
};

// derived class (grandchild) -- ModExpr extends BinaryExpr
class ModExpr : public BinaryExpr {
public:
    /**
     * constructor for modulo of left expression by right expression of a binary expression
     * @param left is the left expression of the binary expression
     * @param right is the right expression of the binary expression
     */
    ModExpr(Expr* left, Expr* right) : BinaryExpr(left, right) {}

    // converts expression to string form
    string toStr() override;

    /**
     * PART B - evaluator that traverses the ASTs and outputs the result of the modulo expression
     * @param visitor traverses the ASTs
     */
    double eval(Visitor* visitor) override;
};

// derived class (child) -- ConstExpr extends Expr
class ConstExpr : public Expr {
protected:
    int constExpr;  // declare constExpr value
public:
    /**
     * constructor for constant expression
     * @param value is the integer value of the constant expression
     */
    ConstExpr(int value) : constExpr(value) {}

    /**
     * retrieve the value of a constant expression
     * @return a pointer that points to the constant expression
     */
    int getConstExpr() const {
        return constExpr;
    }

    // converts expression to string form
    string toStr() override;

    /**
     * PART B - evaluates the value of a constant expression
     * @param visitor traverses the ASTs
     */
    double eval(Visitor* visitor) override;
};

#endif // EXPR_H