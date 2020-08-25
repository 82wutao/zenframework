#ifndef __ZEN_FRAMEWORK_Front_HPP
#define __ZEN_FRAMEWORK_Front_HPP

#include "zen/constants.hpp"
#include "zen/api.hpp"

#include <string>
#include <functional>

using namespace zen::constants;

namespace zen {


    namespace framework {
        template<typename Ret, typename... T>
        void register_route_abstractor(std::string , int , std::function<Ret(T...)>, std::function<std::tuple<T...>(Http_Request*)>);

        void register_route(std::string , int , Controller);
        void root_interface_func(http_connection conncetion);
    }
}
#endif
