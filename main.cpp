#include <iostream>
#include <vector>

//#include "zen/api.hpp"

// error,page

// redirect url
// forward url

// text
// template
// json
// file
// steam
// chunk

        char* Controller(int request ,int response){
            return "hello";
        }

        using next= void (*)(int,int);
        using Middleware = void (*)(int, int,next);
        std::vector<Middleware> middleware_stack;

        int stack_index = 0 ;
        next next_ref = NULL;
        void next_middleware(int request,int response){
            stack_index++;
            if (stack_index == middleware_stack.size()){
                std::cout<<"invoke Controller func"<<std::endl;
            }else{
                auto instance =middleware_stack[stack_index];
                instance(request,response,next_ref);
            }
        }



void middle1(int request, int response,next func){
    std::cout<<"middle1 top"<<std::endl;
    func(request,response);
    std::cout<<"middle1 bottom"<<std::endl;
}
void middle2(int request, int response,next func){
        std::cout<<"middle2 top"<<std::endl;
    func(request,response);
    std::cout<<"middle2 bottom"<<std::endl;
}
void middle3(int request, int response,next func){
        std::cout<<"middle3 top"<<std::endl;
    func(request,response);
    std::cout<<"middle3 bottom"<<std::endl;
}


        using http_connection = int;
        using root_interface = void (*)(http_connection);


int main(int argc, char **argv) {



next_ref = next_middleware;


middleware_stack.push_back(middle1);
middleware_stack.push_back(middle2);
middleware_stack.push_back(middle3);

middle1(0,9,next_ref);



    std::cout << "Hello, world!" << std::endl;
    return 0;
}
