//
// CS264 CA2
// Shannen White
//

#include <iostream>
#include <cstring>

using namespace std;

/*
    Ensure you include sufficient comments to explain your solutions. This can
    come in the form of a multi-line comment before the solution, or inline
    comments left within the solution itself.
*/

// --- 4.1 LENGTH ---
/* unsigned int means an int that can never be negative,
char* is a pointer which points to the first char of the char array */
unsigned int length(const char* str){
    unsigned int len = 0;                   // initialise string length
    // using pointer arithmetic
    while (*str != '\0') {                  // while str doesn't include '\0'
        len++;                              // increase count of the str length
        str++;                              // to continue the loop
    }
    return len;                             // returns length of str
}

// --- 4.2 COPY ---
char* copy(char* dest, const char* src){
    // tried pointer arithmetic first since i did it for 4.1
    // but it didn't work so tried array indexing instead, commented out my original code though
    // while(*src != '\0') {                   // loop through c-string excluding null terminator
    //     *dest = *src;                       // copy from one pointer to the other
    //     src++;                              // increment src to continue with loop
    //     dest++;                             // increase dest to continue with loop
    // }
    // *dest='\0';                             // add null terminator to end of c-string

    // using array indexing
    int i=0;                                // initialise index
    while(src[i] != '\0') {                 // loop through c-string excluding null terminator
        dest[i] = src[i];                   // copy from one pointer to the other
        i++;                                // to continue the while loop
    }
    dest[i]='\0';                           // add null terminator at the end

    if (length(dest)<length(src)) {         // dest needs to be large enough to store a copy of src
        return nullptr;                     // return NULL if dest is too small
    }                                       // ^ can't really test NULL out if not the rest of my test cases won't be displayed on my IDE
    return dest;                            // return dest if copy is successful
}

// --- 4.3 INDEX OF ---
int indexOf(char c, const char* str){
    for (int i=0; i<=length(str); i++) {    // iterate through the loop, using length() from 4.1
        if (str[i] == c) {                  // if char at i matches c,
            return i;                       // return current position
        }                                   // else, continue looping
    }
    return -1;                              // return -1 if c isn't found in str
}

// --- 4.4 SUBSTRING ---
char* substring(int i, int j, const char* str){
    if (i>j || i<0 || j>length(str)) {      // if i & j aren't in the valid range of i<j<=strLen
        return nullptr;                     // return null
    }
    // result is from i to j-1, so length of substring is j-i
    // +1 to account for null terminator
    char* sub = new char[j-i+1];            // issue of memory leak though...

    int count=0;                            // initialise count for substring
    for (int k=i; k<=j-1; k++, count++) {   // loops from i to j-1
        sub[count] = str[k];                // starts at sub[0] and str[i]
    }
    sub[j-i] = '\0';                        // add null terminator at the end
    return sub;                             // return substring
}

// --- 4.5 REPLACE ---
char* replace(char c, char p, const char* str){
    char* result = new char[length(str)+1]; // +1 to account for null terminator
    for (int i=0; i<length(str); i++) {     // iterate through the loop, using length() from 4.1
        if (str[i] == c) {                  // if char at i matches c,
            result[i] = p;                  // replace c with p
        } else {                            // if no c found,
            result[i] = str[i];             // return a copy of str
        }
    }
    result[length(str)] = '\0';             // add null terminator at the end
    return result;                          // return new string (or copy of input string)
}


/*
    - Try to include your test cases below this multi-line comment -

    Ensure your test cases use the following format:

    [function]_name_test_case_[k](){
        test_input = example_value;
        expected_output = example_value;

        result = [function](test_input)
        if(result == output){
            cout << "[function]_name_test_case_[k] PASSED" << endl;
        }
        else{
            cout << "[function]_name_test_case_[k] FAILED" << endl;
        }
    }

    [function] - The name of the function being tested
    [k] - The index of the test
*/

// --- 4.1 LENGTH ---
void length_test_case_1() {
    const char* test_str = "string\0";
    unsigned int expected_length = 6;

    unsigned int result = length(test_str);

    if (result == expected_length) {
        cout << "length_test_case_1 PASSED" << " ('" << test_str << "', length: " << result << ")" << endl;
    }
    else{
        cout << "length_test_case_1 FAILED" << " ('" << test_str << "', length: " << result << ")" << endl;
    }
}

void length_test_case_2() {
    const char* test_str = "Hello World";
    unsigned int expected_length = 11;

    unsigned int result = length(test_str);

    if (result == expected_length) {
        cout << "length_test_case_2 PASSED" << " ('" << test_str << "', length: " << result << ")" << endl;
    }
    else{
        cout << "length_test_case_2 FAILED" << " ('" << test_str << "', length: " << result << ")" << endl;
    }
}

// --- 4.2 COPY ---
void copy_test_case_1() {
    char test_dest[10];
    const char* test_src = "string";

    char* result = copy(test_dest, test_src);

    // while (*test_src && *test_dest) {
    //     if (*test_src != *test_dest) {
    //         check = false;
    //         break;
    //     }
    //     test_src++;
    //     test_dest++;        // can't increment this
    // }

    // manually checking since we can't use strcmp() for comparison
    bool check = true;      // check if test_dest is the same as test_src
    for (int i=0; i<length(result); i++) {
        if (result[i] != test_src[i]) {
            check = false;  // mark boolean as false if chars at i don't match
        }
    }

    if (check) {            // if dest & src are the same
        cout << "copy_test_case_1 PASSED" << " (src: '" << test_src << "', dest: '" << result << "')" << endl;
    }
    else{
        cout << "copy_test_case_1 FAILED" << " (src: '" << test_src << "', dest: '" << result << "')" << endl;
    }
}

void copy_test_case_2() {
    char test_dest[7];
    const char* test_src = "hellooo";

    char* result = copy(test_dest, test_src);

    bool check = true;      // check if test_dest is the same as test_src
    for (int i=0; i<length(result); i++) {
        if (result[i] != test_src[i]) {
            check = false;  // mark boolean as false if chars at i don't match
        }
    }

    if (check) {            // if dest & src are the same
        cout << "copy_test_case_1 PASSED" << " (src: '" << test_src << "', dest: '" << result << "')" << endl;
    }
    else{
        cout << "copy_test_case_1 FAILED" << " (src: '" << test_src << "', dest: '" << result << "')" << endl;
    }
}

// --- 4.3 INDEX OF ---
void indexOf_test_case_1(){
    char test_c = 'i';
    const char* test_str = "string";
    int result = indexOf(test_c, test_str);

    if(result == 3){
        cout << "indexOf_test_case_1 PASSED" << " ('" << test_c << "' in '" << test_str << "', index: " << result << ")" << endl;
    }
    else{
        cout << "indexOf_test_case_1 FAILED" << " ('" << test_c << "' in '" << test_str << "', index: " << result << ")" << endl;
    }
}

void indexOf_test_case_2(){
    char test_c = 'a';
    const char* test_str = "string";
    int result = indexOf(test_c, test_str);

    if(result == -1){
        cout << "indexOf_test_case_2 PASSED" << " ('" << test_c << "' in '" << test_str << "', index: " << result << ")" << endl;
    }
    else{
        cout << "indexOf_test_case_2 FAILED" << " ('" << test_c << "' in '" << test_str << "', index: " << result << ")" << endl;
    }
}

void indexOf_test_case_3(){
    char test_c = 'w';
    const char* test_str = "helloworld";
    int result = indexOf(test_c, test_str);

    if(result == 5){
        cout << "indexOf_test_case_3 PASSED" << " ('" << test_c << "' in '" << test_str << "', index: " << result << ")" << endl;
    }
    else{
        cout << "indexOf_test_case_3 FAILED" << " ('" << test_c << "' in '" << test_str << "', index: " << result << ")" << endl;
    }
}

// --- 4.4 SUBSTRING ---
void substring_test_case_1(){;
    const char* test_str = "string";    // test input
    const char* test_result = "str";    // expected output
    int test_i=0;
    int test_j=3;

    char* result = substring(test_i, test_j, test_str);

    bool check = true;      // check if result from using substring function is the same as expected output
    for (int i=0; i<length(result); i++) {
        if (result[i] != test_result[i]) {
            check = false;  // mark boolean as false if chars at i don't match
        }
    }

    if(check) {
        cout << "substring_test_case_1 PASSED" << " ('" << result << "' from '" << test_str << "' when i=" << test_i << " and j=" << test_j << ")" << endl;
    }
    else{
        cout << "substring_test_case_1 FAILED" << " ('" << result << "' from '" << test_str << "' when i=" << test_i << " and j=" << test_j << ")" << endl;
    }
}

void substring_test_case_2(){;
    const char* test_str = "string";    // test input
    const char* test_result = "rin";    // expected output
    int test_i=2;
    int test_j=5;

    char* result = substring(test_i, test_j, test_str);

    bool check = true;      // check if result from using substring function is the same as expected output
    for (int i=0; i<length(result); i++) {
        if (result[i] != test_result[i]) {
            check = false;  // mark boolean as false if chars at i don't match
        }
    }

    if(check) {
        cout << "substring_test_case_2 PASSED" << " ('" << result << "' from '" << test_str << "' when i=" << test_i << " and j=" << test_j << ")" << endl;
    }
    else{
        cout << "substring_test_case_2 FAILED" << " ('" << result << "' from '" << test_str << "' when i=" << test_i << " and j=" << test_j << ")" << endl;
    }
}

// --- 4.5 REPLACE ---
void replace_test_case_1(){;
    char test_c = 'i';
    char test_p = 'x';
    const char* test_str = "string";
    const char* test_result = "strxng";

    char* result = replace(test_c, test_p, test_str);

    bool check = true;      // check if result from using replace function is the same as expected output
    for (int i=0; i<length(result); i++) {
        if (result[i] != test_result[i]) {
            check = false;  // mark boolean as false if chars at i don't match
        }
    }

    if(check) {
        cout << "replace_test_case_1 PASSED" << " ('" << test_c << "' to '" << test_p << "' for '" << test_str << "': " << result << ")" << endl;
    }
    else{
        cout << "replace_test_case_1 FAILED" << " ('" << test_c << "' to '" << test_p << "' for '" << test_str << "': " << result << ")" << endl;
    }
}

void replace_test_case_2(){;
    char test_c = 'a';
    char test_p = 'x';
    const char* test_str = "string";
    const char* test_result = "string";

    char* result = replace(test_c, test_p, test_str);

    bool check = true;      // check if result from using replace function is the same as expected output
    for (int i=0; i<length(result); i++) {
        if (result[i] != test_result[i]) {
            check = false;  // mark boolean as false if chars at i don't match
        }
    }

    if(check) {
        cout << "replace_test_case_2 PASSED" << " ('" << test_c << "' to '" << test_p << "' for '" << test_str << "': " << result << ")" << endl;
    }
    else{
        cout << "replace_test_case_2 FAILED" << " ('" << test_c << "' to '" << test_p << "' for '" << test_str << "': " << result << ")" << endl;
    }
}


// Call your test functions in the main function below
int main(){
    // [function]_name_test_case_[k]()
    cout << "--- 4.1 LENGTH ---" << endl;
    length_test_case_1();
    length_test_case_2();

    cout << "--- 4.2 COPY ---" << endl;
    copy_test_case_1();
    copy_test_case_2();

    cout << "--- 4.3 INDEXOF ---" << endl;
    indexOf_test_case_1();
    indexOf_test_case_2();
    indexOf_test_case_3();

    cout << "--- 4.4 SUBSTRING ---" << endl;
    substring_test_case_1();
    substring_test_case_2();

    cout << "--- 4.5 REPLACE ---" << endl;
    replace_test_case_1();
    replace_test_case_2();

    return 0;
}