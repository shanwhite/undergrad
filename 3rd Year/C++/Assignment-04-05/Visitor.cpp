//
// PART B - Implementing Evaluator
// Created by Shannen White on 04/12/24.
//

#include "Expr.h"
#include "Visitor.h"

#include <iostream>
using namespace std;

/**
 * retrieve string representation of constant expression
 * @return string representation of constExpr
 */
double NumVisitor::visit(Expr* expr) {
    cerr << "Error!" << endl;   // print error message
    return 0.0;
}

/**
 * evaluate the addition of left and right expressions of a binary expression
 * @param expr AddExpr node that holds left and right expressions of the binary expression
 * @return result of addition of left and right expressions
 */
double NumVisitor::visit(AddExpr* expr) {
    // utilise getLeftExpr() and getRightExpr() from BinaryExpr class
    double left = expr->getLeftExpr()->eval(this);
    double right = expr->getRightExpr()->eval(this);
    return left + right;
}

/**
 * evaluate the subtraction of left expression by right expression of a binary expression
 * @param expr SubExpr node that holds left and right expressions of the binary expression
 * @return result of subtraction between left and right expressions
 */
double NumVisitor::visit(SubExpr* expr) {
    double left = expr->getLeftExpr()->eval(this);
    double right = expr->getRightExpr()->eval(this);
    return left - right;
}

/**
 * evaluate the multiplication of left and right expressions of a binary expression
 * @param expr MulExpr node that holds left and right expressions of the binary expression
 * @return result of multiplication of left and right expressions
 */
double NumVisitor::visit(MulExpr* expr) {
    double left = expr->getLeftExpr()->eval(this);
    double right = expr->getRightExpr()->eval(this);
    return left * right;
}

/**
 * evaluate the division of left expression by right expression of a binary expression
 * NOTE: right expression cannot be zero as zero cannot be the divisor; if zero, print error message
 * @param expr DivExpr node that holds left and right expressions of the binary expression
 * @return result of division of left expression by right expression
 */
double NumVisitor::visit(DivExpr* expr) {
    double left = expr->getLeftExpr()->eval(this);
    double right = expr->getRightExpr()->eval(this);

    if (right==0) {
        cerr << "Error! Unable to divide by 0" << endl; // print error message if right expression is zero
        return 0.0;
    }
    return left / right;
}

/**
 * evaluate the modulo of left expression by right expression of a binary expression
 * NOTE: modulo can only be used for integers
 * NOTE: right expression cannot be zero as zero cannot be the divisor; if zero, print error message
 * @param expr ModExpr node that holds left and right expressions of the binary expression
 * @return result of modulo of left expression by right expression
 * ^ i.e. the remainder after dividing left expression by right expression
 */
double NumVisitor::visit(ModExpr* expr) {
    // static_cast<int> to convert left and right expressions from double to int
    int left = static_cast<int>(expr->getLeftExpr()->eval(this));
    int right = static_cast<int>(expr->getRightExpr()->eval(this));

    if (right==0) {
        cerr << "Error! Unable to divide by 0" << endl; // print error message if right expression is zero
        return 0.0;
    }
    return left % right;
}

/**
 * retrieve string representation of constant expression
 * @return string representation of constExpr
 */
double NumVisitor::visit(ConstExpr* expr) {
    return expr->getConstExpr();
}