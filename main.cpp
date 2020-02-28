/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

 Pointers

 Please look at the screenshot in the files to see what happens if you copy this assignment into Xcode
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
         you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    double value;
    std::string name;

    T(double v, const char* n)  {
        this->value = v;
        this->name = n;

    } //1
    //2
    //3
};

struct CompareVals
{
    T* compare(T* a, T* b) //5
    {
        if (a != nullptr && b != nullptr) // check for nullptr
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float val1 { 0 }, val2 { 0 };
    float distFcn(float* updatedValue) 
    {
        std::cout << "U's val1 value: " << this->val1 << std::endl;
        std::cout << "U's val2 value: " << this->val2 << std::endl;
        this->val1 = *updatedValue;
        std::cout << "U's val1 updated value: " << this->val1 << std::endl;
        while( std::abs(this->val2 - this->val1) > 0.001f )
        {
            if(this->val2 > this->val1) // if val2 is larger I decrease it
            {
                this->val2 -= std::abs(this->val2 - this->val1) / 2;
            }
            else // if val2 is smaller I increase it
            {
                this->val2 += std::abs(this->val2 - this->val1) / 2;
            }
        }
        std::cout << "U's val2 updated value: " << this->val2 << std::endl;
        return this->val2 * this->val1;
    }
     
};

struct DistanceStruct
{
    static float distFcn(U* that, float* updatedValue )        //10
    {
        std::cout << "U's val1 value: " << that->val1 << std::endl;
        std::cout << "U's val2 value: " << that->val2 << std::endl;
        that->val1 = *updatedValue;
        std::cout << "U's val1 updated value: " << that->val1 << std::endl;
        while( std::abs(that->val2 - that->val1) > 0.001f )
        {
            if(that->val2 > that->val1) // if val2 is larger I decrease it
            {
                that->val2 -= std::abs(that->val2 - that->val1) / 2;
            }
            else // if val2 is larger I increase it
            {
                that->val2 += std::abs(that->val2 - that->val1) / 2;
            }
        }
        std::cout << "U's val2 updated value: " << that->val2 << std::endl;
        return that->val2 * that->val1;
    }
};
        
int main()
{
    T varT1(1 , "var1");                                             //6
    T varT2(2 , "var2");                                          //6

    CompareVals f;                                            //7
    auto* smaller = f.compare(&varT1 , &varT2);                              //8
    if (smaller != nullptr) // check for nullptr
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    
    U U1;
    float updatedValue = 5.f;
    std::cout << "[static func]" << std::endl;
    float multValuesU1 = DistanceStruct::distFcn(&U1, &updatedValue);
    std::cout << "U1's multiplied values: " << multValuesU1 << std::endl;
    
    U U2;
    std::cout << "[member func]" << std::endl;
    float multValuesU2 = U2.distFcn(&updatedValue);
    std::cout << "U2's multiplied values: " << multValuesU2 << std::endl;

}
