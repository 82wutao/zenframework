
#ifndef __ZEN_FRAMEWORK_FRONT_HPP
#define __ZEN_FRAMEWORK_FRONT_HPP


#include "zen/api.hpp"

#include <vector>
#include <iostream>

namespace zen
{
namespace framework
{

//        using http_connection = int;
//        void web_app_protocol_interface(http_connection);

void boot_filter ( request_context* context, Http_Request* request,Http_Response* response,Next next_middleware )
{
    std::cout<<"middle1 top"<<std::endl;
    next_middleware ( request,response );
    std::cout<<"middle1 bottom"<<std::endl;
}

std::vector<Middleware> middleware_stack;
void root_interface_func ( http_connection conncetion )
{

    // have current request and response
    // close ,destory objects and exit this thread
    // continue object field
    // sync or async controller
    // {write out to connection}

    // none current request and response
    // close and exit this thread
    // create objects
    // run have

    int stack_index=0;
    Next next_ref = NULL;
    Next next_func = [next_ref,&stack_index] ( Http_Request* request,Http_Response* response ) {
        if ( stack_index == middleware_stack.size() ) {
            std::cout<<"invoke Controller func"<<std::endl;
            return;
        }
        Middleware instance =middleware_stack[stack_index];
        instance ( NULL,request,response,next_ref );
        stack_index++;
    };
    next_ref = next_func;

    Http_Request* request = NULL;//connection.xxx
    Http_Response* response = NULL;//connection.yyy

    boot_filter ( NULL,request,response,next_func );






}

}
}
#endif
