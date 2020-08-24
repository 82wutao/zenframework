
#include "zen/api.hpp"
#include <iostream>
#include <vector>
#include <tuple>

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


using namespace zen::framework;


void middle1(Request_context* context,Http_Request* request, Http_Response* response,Next func){
    std::cout<<"middle1 top"<<std::endl;
    func(request,response);
    std::cout<<"middle1 bottom"<<std::endl;
}
void middle2(Request_context* context,Http_Request* request, Http_Response* response,Next func){
        std::cout<<"middle2 top"<<std::endl;
    func(request,response);
    std::cout<<"middle2 bottom"<<std::endl;
}
void middle3(Request_context* context,Http_Request* request, Http_Response* response,Next func){
        std::cout<<"middle3 top"<<std::endl;
    func(request,response);
    std::cout<<"middle3 bottom"<<std::endl;
}

template<typename Ret,typename... T>
void regist(std::function<Ret(T...)> ctlor,std::function<std::tuple<T...>(int)> abs) {

}


void boot_filter (Request_context* context, Http_Request* request,Http_Response* response,Next next_middleware )
{
    std::cout<<"boot_filter top"<<std::endl;
    next_middleware ( request,response );
    std::cout<<"boot_filter bottom"<<std::endl;
}

std::vector<Middleware> middleware_stack;
int main(int argc, char **argv) {





    middleware_stack.push_back(middle1);
    middleware_stack.push_back(middle2);
    middleware_stack.push_back(middle3);




    int stack_index=0;
    Next next_ref = NULL;
    Next next_func = [&next_ref,&stack_index] ( Http_Request* request,Http_Response* response ) {
        if ( stack_index == middleware_stack.size() ) {
            std::cout<<"invoke Controller func"<<std::endl;
            return;
        }
        Middleware instance =middleware_stack[stack_index];
        stack_index++;
        instance ( NULL,request,response,next_ref );
    };
    next_ref = next_func;

    Http_Request* request = NULL;//connection.xxx
    Http_Response* response = NULL;//connection.yyy

    boot_filter ( NULL,request,response,next_func );
    std::cout << "Hello, world!" << std::endl;











    return 0;
}
