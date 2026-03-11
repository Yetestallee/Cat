#include<iostream>
#include<string>


class cat{
public:
    cat(std::string); 
    void speak(); 
    ~cat(); 
private:
    int age=1;
    std::string name="mimi";
};