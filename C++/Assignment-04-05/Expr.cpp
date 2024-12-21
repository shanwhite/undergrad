//
// PART A - Designing ASTs
// Created by Shannen White on 25/11/24.
//

#include "Expr.h"
#include "Visitor.h"

#include <iostream>
using namespace std;

// PART A
/**
 * adds the + operator between left and right expressions of a binary expression
 * by converting left expression to string representation
 * then adding the binary operator (+) to the string
 * then converting the right expression to string representation
 * and finally printing out the entire expression
 * for e.g., 3+4 or (3+4)+(5)
 * @return string representation of leftExpr + rightExpr
 */
string AddExpr::toStr() {
    return leftExpr->toStr() + " + " + rightExpr->toStr();
}

/**
 * adds the - operator between left and right expressions of a binary expression
 * by converting left expression to string representation
 * then adding the binary operator (-) to the string
 * then converting the right expression to string representation
 * and finally printing out the entire expression
 * @return string representation of leftExpr - rightExpr
 */
string SubExpr::toStr() {
    return leftExpr->toStr() + " - " + rightExpr->toStr();
}

/**
 * adds the * operator between left and right expressions of a binary expression
 * by converting left expression to string representation
 * then adding the binary operator (*) to the string
 * then converting the right expression to string representation
 * and finally printing out the entire expression
 * @return string representation of leftExpr * rightExpr
 */
string MulExpr::toStr() {
    return leftExpr->toStr() + " * " + rightExpr->toStr();
}

/**
 * adds the / operator between left and right expressions of a binary expression
 * by converting left expression to string representation
 * then adding the binary operator (/) to the string
 * then converting the right expression to string representation
 * and finally printing out the entire expression
 * @return string representation of leftExpr / rightExpr
 */
string DivExpr::toStr() {
    return leftExpr->toStr() + " / " + rightExpr->toStr();
}

/**
 * adds the % operator between left and right expressions of a binary expression
 * by converting left expression to string representation
 * then adding the binary operator (%) to the string
 * then converting the right expression to string representation
 * and finally printing out the entire expression
 * @return string representation of leftExpr % rightExpr
 */
string ModExpr::toStr() {
    return leftExpr->toStr() + " % " + rightExpr->toStr();
}

/**
 * get string representation of constant expression
 * @return string representation of constExpr
 */
string ConstExpr::toStr() {
    return to_string(constExpr);    // to_string converts constExpr from int to string
}

// PART B
/**
 * evaluate the addition between left and right expressions of a binary expression
 * @param visitor traverses the ASTs and visits AddExpr node
 * @return result of adding left and right expressions
 */
double AddExpr::eval(Visitor* visitor) {
    return visitor->visit(this);
}

/**
 * evaluate the subtraction between left and right expressions of a binary expression
 * @param visitor traverses the ASTs and visits SubExpr node
 * @return result of subtracting right expression from left expression
 */
double SubExpr::eval(Visitor* visitor) {
    return visitor->visit(this);
}

/**
 * evaluate the multiplication between left and right expressions of a binary expression
 * @param visitor traverses the ASTs and visits MulExpr node
 * @return result of multiplying left and right expressions
 */
double MulExpr::eval(Visitor* visitor) {
    return visitor->visit(this);
}

/**
 * evaluate the division between left and right expressions of a binary expression
 * @param visitor traverses the ASTs and visits DivExpr node
 * @return result of dividing left expression by right expression
 */
double DivExpr::eval(Visitor* visitor) {
    return visitor->visit(this);
}

/**
 * evaluate the modulo between left and right expressions of a binary expression
 * @param visitor traverses the ASTs and visits ModExpr node
 * @return result of modulo of left expression by right expression
 */
double ModExpr::eval(Visitor* visitor) {
    return visitor->visit(this);
}

/**
 * evaluate the value of a constant expression
 * @param visitor traverses the ASTs and visits ConstExpr node
 * @return value of constant expression
 */
double ConstExpr::eval(Visitor* visitor) {
    return visitor->visit(this);
}