
#ifndef __ZEN_FRAMEWORK_FRONT_HPP
#define __ZEN_FRAMEWORK_FRONT_HPP


#include "zen/api.hpp"
#include "zen/constants.hpp"

#include <vector>
#include <map>
#include <iostream>
#include <tuple>
#include <exception>

#include "zen/framework/front.hpp"



namespace zen
{
namespace framework
{
//        using http_connection = int;
//        void web_app_protocol_interface(http_connection);

std::vector<Middleware> middleware_stack;
std::map<std::string, std::tuple<int,Controller>> controllers;

    void boot_filter(Request_context* context, Http_Request* request, Http_Response* response, Next next_middleware)
    {
        std::cout << "boot_filter top" << std::endl;
        next_middleware(request, response);
        std::cout << "boot_filter bottom" << std::endl;
    }
    void terminal_filter(Request_context* context, Http_Request* request, Http_Response* response, Next next_middleware) {
        std::string path = request->get_path();
        std::map<std::string, std::tuple<int, Controller> >::iterator it = controllers.find(path);
        if (it == controllers.end()) {
            response->set_statuscode(&zen::constants::STATUSCODE_404);
            return;
        }

        int method = request->get_method();
        std::tuple<int, Controller> combine = it->second;
        int methods = std::get<0>(combine);
        if ((methods & method) != method) {
            response->set_statuscode(&zen::constants::STATUSCODE_405);
            return;
        }
        try {
            Controller er = std::get<1>(combine);
            er(nullptr,request, response);
        }
        catch (std::exception& e) {

            response->set_statuscode(&zen::constants::STATUSCODE_500);
        }
    }



template<typename Ret, typename... T>
void register_route_abstractor(std::string path, int methods, std::function<Ret(T...)> controller, std::function<std::tuple<T...>(Http_Request*)> param_convertor) {

}

void register_route(std::string path, int methods, Controller controller)
{
    controllers[path] = std::make_tuple(methods, controller);
}

void root_interface_func ( http_connection conncetion )
{
    middleware_stack.push_back(terminal_filter);

    // have current request and response
    // close ,destory objects and exit this thread
    // continue object field
    // sync or async controller
    // {write out to connection}




    // none current request and response
    // close and exit this thread
    // create objects
    // run have






    int stack_index = 0;
    Next next_ref = NULL;
    Next next_func = [&next_ref, &stack_index](Http_Request* request, Http_Response* response) {
        if (stack_index == middleware_stack.size()) {
            std::cout << "invoke Controller func" << std::endl;
            return;
        }
        Middleware filter = middleware_stack[stack_index];
        stack_index++;
        filter(NULL, request, response, next_ref);
    };
    next_ref = next_func;

    Http_Request* request = NULL;//connection.xxx
    Http_Response* response = NULL;//connection.yyy

    boot_filter(NULL, request, response, next_func);
    std::cout << "Hello, world!" << std::endl;




}



}
}
#endif
