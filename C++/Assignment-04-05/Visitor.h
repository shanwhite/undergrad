//
// PART B - Implementing Evaluator
// Created by Shannen White on 04/12/24.
//

#ifndef VISITOR_H
#define VISITOR_H

// declaration of classes from Expr.cpp
class Expr;
class AddExpr;
class SubExpr;
class MulExpr;
class DivExpr;
class ModExpr;
class ConstExpr;

// base class
class Visitor {
public:
    // pure virtual functions for each AST including Expr
    virtual double visit(Expr* expr) = 0;
    virtual double visit(AddExpr* expr) = 0;
    virtual double visit(SubExpr* expr) = 0;
    virtual double visit(MulExpr* expr) = 0;
    virtual double visit(DivExpr* expr) = 0;
    virtual double visit(ModExpr* expr) = 0;
    virtual double visit(ConstExpr* expr) = 0;

    // virtual destructor for base class
    virtual ~Visitor() {}
};

// class where evaluator is implemented
class NumVisitor : public Visitor {
public:
    // evaluator methods that override the ones in the Visitor class
    double visit(Expr* expr) override;
    double visit(AddExpr* expr) override;
    double visit(SubExpr* expr) override;
    double visit(MulExpr* expr) override;
    double visit(DivExpr* expr) override;
    double visit(ModExpr* expr) override;
    double visit(ConstExpr* expr) override;
};

#endif // VISITOR_H