/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

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
        if (updatedValue != nullptr)
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
        if ((that != nullptr) && (updatedValue != nullptr)) // check for nullptrs
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
        else
        {
            std::cout << "Arguments are null pointers" << std::endl;
            return -1.0f;
        }
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
