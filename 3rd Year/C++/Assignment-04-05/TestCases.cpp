//
// PART A & B - Test Cases for ASTs
// Created by Shannen White on 25/11/24.
//

#include "Expr.h"
#include "Visitor.h"

#include <iostream>
using namespace std;

// test case for addition expression
void Test_Case_1_AddExpr() {
    // initialise constant expressions
    ConstExpr* c1 = new ConstExpr(7);
    ConstExpr* c2 = new ConstExpr(2);

    // initialise addition expression
    AddExpr* a1 = new AddExpr(c1, c2);

    // PART B - initialise visitor
    Visitor* visitor = new NumVisitor();

    // print results
    cout << "Test_Case_1_AddExpr (Part A): " << a1->toStr() << endl;        // expected output: 7 + 2
    cout << "Test_Case_1_AddExpr (Part B): " << a1->eval(visitor) << endl;  // expected output: 9

    // deallocate memory
    delete visitor;
    delete a1; // recursively deletes c1, c2
}

// test case for subtraction expression
void Test_Case_2_SubExpr() {
    // initialise constant expressions
    ConstExpr* c1 = new ConstExpr(9);
    ConstExpr* c2 = new ConstExpr(4);

    // initialise subtraction expression
    SubExpr* s1 = new SubExpr(c1, c2);

    // PART B - initialise visitor
    Visitor* visitor = new NumVisitor();

    // print results
    cout << "Test_Case_2_SubExpr (Part A): " << s1->toStr() << endl;        // expected output: 9 - 4
    cout << "Test_Case_2_SubExpr (Part B): " << s1->eval(visitor) << endl;  // expected output: 5

    // deallocate memory
    delete visitor;
    delete s1; // recursively deletes c1, c2
}

// test case for multiplication expression
void Test_Case_3_MulExpr() {
    // initialise constant expressions
    ConstExpr* c1 = new ConstExpr(3);
    ConstExpr* c2 = new ConstExpr(6);

    // initialise multiplication expression
    MulExpr* m1 = new MulExpr(c1, c2);

    // PART B - initialise visitor
    Visitor* visitor = new NumVisitor();

    // print results
    cout << "Test_Case_3_MulExpr (Part A): " << m1->toStr() << endl;        // expected output: 3 * 6
    cout << "Test_Case_3_MulExpr (Part B): " << m1->eval(visitor) << endl;  // expected output: 18

    // deallocate memory
    delete visitor;
    delete m1; // recursively deletes c1, c2
}

// test case for division expression
void Test_Case_4_DivExpr() {
    // initialise constant expressions
    ConstExpr* c1 = new ConstExpr(9);
    ConstExpr* c2 = new ConstExpr(3);

    // initialise division expression
    DivExpr* d1 = new DivExpr(c1, c2);

    // PART B - initialise visitor
    Visitor* visitor = new NumVisitor();

    // print results
    cout << "Test_Case_4_DivExpr (Part A): " << d1->toStr() << endl;        // expected output: 9 / 3
    cout << "Test_Case_4_DivExpr (Part B): " << d1->eval(visitor) << endl;  // expected output: 3

    // deallocate memory
    delete visitor;
    delete d1; // recursively deletes c1, c2
}

// test case for modulo expression
void Test_Case_5_ModExpr() {
    // initialise constant expressions
    ConstExpr* c1 = new ConstExpr(5);
    ConstExpr* c2 = new ConstExpr(2);

    // initialise modulo expression
    ModExpr* mod1 = new ModExpr(c1, c2);

    // PART B - initialise visitor
    Visitor* visitor = new NumVisitor();

    // print results
    cout << "Test_Case_5_ModExpr (Part A): " << mod1->toStr() << endl;         // expected output: 5 % 2
    cout << "Test_Case_5_ModExpr (Part B): " << mod1->eval(visitor) << endl;   // expected output: 1

    // deallocate memory
    delete visitor;
    delete mod1; // recursively deletes c1, c2
}

// test case for all expressions
void Test_Case_6_AllExpr() {
    // initialise constant expressions
    ConstExpr* c1 = new ConstExpr(5);
    ConstExpr* c2 = new ConstExpr(2);
    ConstExpr* c3 = new ConstExpr(3);
    ConstExpr* c4 = new ConstExpr(6);
    ConstExpr* c5 = new ConstExpr(8);
    ConstExpr* c6 = new ConstExpr(2);

    // initialise expressions
    AddExpr* add1 = new AddExpr(c1, c2);
    SubExpr* sub1 = new SubExpr(add1, c3);
    MulExpr* mul1 = new MulExpr(sub1, c4);
    DivExpr* div1 = new DivExpr(mul1, c5);
    ModExpr* mod1 = new ModExpr(div1, c6);

    // PART B - initialise visitor
    Visitor* visitor = new NumVisitor();

    // print results
    cout << "Test_Case_6_AllExpr (Part A): " << mod1->toStr() << endl;          // expected output: 5 + 2 - 3 * 6 / 8 % 2
                                                                                // (= 7-3*6/8%2  = 4*6/8%2 = 24/8%2 = 3%2 = 1)
    cout << "Test_Case_6_AllExpr (Part B): " << mod1->eval(visitor) << endl;    // expected output: 1

    // deallocate memory
    delete visitor;
    delete mod1; // recursively deletes the other expressions
}

// main class
int main() {
    // EXAMPLE FROM ca4_5.pdf
    cout << "*******************************" << endl;
    cout << "EXAMPLE" << endl;
    cout << "*******************************" << endl;
    ConstExpr* c1 = new ConstExpr(3);
    ConstExpr* c2 = new ConstExpr(4);
    ConstExpr* c3 = new ConstExpr(5);
    AddExpr* e1 = new AddExpr(c1,c2);
    SubExpr* e2 = new SubExpr(e1,c3);
    cout << "Part A: " << e1->toStr() << endl;          // output: 3+4
    cout << "Part A: " << e2->toStr() << endl;          // output: 3+4-5
    Visitor* visitor = new NumVisitor();
    cout << "Part B (Eval of " << e2->toStr() << "): " << e2->eval(visitor) << endl ;   // output: 2
    cout << "*******************************" << endl;

    // deallocate memory
    delete visitor;
    delete e2; // recursively deletes the other expressions

    // MY TEST CASES
    cout << "TEST CASES" << endl;
    cout << "*******************************" << endl;
    Test_Case_1_AddExpr();
    Test_Case_2_SubExpr();
    Test_Case_3_MulExpr();
    Test_Case_4_DivExpr();
    Test_Case_5_ModExpr();
    Test_Case_6_AllExpr();
    cout << "*******************************" << endl;

    return 0;
}