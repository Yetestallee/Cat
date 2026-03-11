#include<iostream>
#include "cat.h"
#include<memory>

void pass_unique_value(std::unique_ptr<cat> c){
    c->speak();
}

void pass_unique_reference(std::unique_ptr<cat>& c){
    c->speak();
}

void pass_shared_value(std::shared_ptr<cat> c){
    c->speak();
    std::cout<<"use count: "<<c.use_count()<<std::endl;
}


int main() {
    std::cout << "-------------start------------"<< std::endl;
    //unique_ptr
    std ::unique_ptr<cat> c1=std::make_unique<cat>("dyy");
    c1->speak();
    pass_unique_value(std::move(c1)); //将c1的所有权转移给pass_unique_value函数，c1不再拥有对象
    if(c1==nullptr){
        std::cout<<"c1 is nullptr"<<std::endl;
    }

    std::unique_ptr<cat> c2=std::make_unique<cat>("ddy");
    c2->speak();
    pass_unique_reference(c2); //将c2传递给pass_unique_reference函数，c2仍然拥有对象
    if(c2==nullptr){
        std::cout<<"c2 is nullptr"<<std::endl;
    }
    
    //shared_ptr
    std::shared_ptr<cat> c3=std::make_shared<cat>("ddd");
    c3->speak();
    std::shared_ptr<cat> c4=c3; //c4和c3
    c4->speak();
    std::cout<<"c3 use count: "<<c3.use_count()<<std::endl;
    c4.reset(); //c4不再拥有对象，c3仍然拥有对象
    std::cout<<"c3 use count: "<<c3.use_count()<<std::endl;
    std::cout<<"c4 use count: "<<c4.use_count()<<std::endl;
    pass_shared_value(c3); //将c3传递给pass_shared_value函数，c3仍然拥有对象
    std::cout<<"c3 use count: "<<c3.use_count()<<std::endl;
    //c3的引用计数没有增加，因为pass_shared_value函数接受的是shared_ptr的值传递，传递的是c3的副本，副本的引用计数为1，函数结束后副本被销毁，引用计数减少1，c3的引用计数不变

    //weak_ptr
    std::shared_ptr<cat> c5=std::make_shared<cat>("dddy");
    c5->speak();
    std::weak_ptr<cat> c6=c5; //c6是c5的弱引用，不增加引用计数
    std::cout<<"c5 use count: "<<c5.use_count()<<std::endl;
    auto c7=c6.lock(); 
    std::cout<<"c5 use count: "<<c5.use_count()<<std::endl;
    



    std::cout << "-------------end------------"<< std::endl;
    return 0;
}