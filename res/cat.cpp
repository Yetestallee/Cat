#include<iostream>
#include "cat.h"


cat::cat(std::string name){
    this->name=name;
    std::cout<<"cat "<<name<<" is created"<<std::endl;
}
void cat::speak(){
    std::cout<<"my name is "<<name<<std::endl;
}
cat::~cat(){
    std::cout<<"cat "<<name<<" is destroyed"<<std::endl;
}
