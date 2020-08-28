
#include <iostream>
#include <vector>
#include <functional>
#include <tuple>
#include <type_traits>

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


template<int N>
struct Apply2 {

    template<typename Func, typename TuplePack,typename... Args>
     static inline auto apply(Func && func, TuplePack&& tp, Args &&... args)
    -> decltype(Apply2<N-1>::apply(std::forward<Func>(func), std::forward<TuplePack>(tp),::std::get<N-1>(::std::forward<TuplePack>(tp)),::std::forward<Args>(args)...)){
         return Apply2<N-1>::apply(std::forward<Func>(func), std::forward<TuplePack>(tp),::std::get<N-1>(::std::forward<TuplePack>(tp)),::std::forward<Args>(args)...);
     }
};

template<>
struct Apply2<0> {

     template<typename Func, typename TuplePack,typename... Args>
     static inline auto apply(Func && func, TuplePack&& tp, Args &&... args)
     -> decltype(::std::forward<Func>(func)(::std::forward<Args>(args)...)){

         return ::std::forward<Func>(func)(::std::forward<Args>(args)...);
     }
};


std::vector<std::function<void()>> functions;

template<typename Ret,typename...Arg>
void regist_func(std::function<Ret(Arg...)> func,std::function<std::tuple<Arg...>()> arg_func){


    functions.push_back([&func,&arg_func](){
    std::tuple<Arg...>&& args=::std::forward<std::tuple<Arg...>>(arg_func());
    Apply2<std::tuple_size<typename std::decay<std::tuple<Arg...>>::type>::value>::apply(std::forward<std::function<Ret(Arg...)>>(func),
                                                                                         std::forward<std::tuple<Arg...>>(args));
    });

    std::cout << "function call finished" <<std::endl;
}


void fuck(){
    for (auto it= functions.begin();it!=functions.end();it++){
        (*it)();
    }
}

// template<typename F, typename T>
// inline auto apply(F && f, T && t)
// -> decltype(Apply< ::std::tuple_size<typename ::std::decay<T>::type>::value>::apply(::std::forward<F>(f),::std::forward<T>(t))){
//
//     return Apply< ::std::tuple_size<typename ::std::decay<T>::type>::value>::apply(::std::forward<F>(f),::std::forward<T>(t));
// }


int main(int argc, char **argv) {



std::tuple<int, double> tup(23, 4.5);
std::function<int(int,double)> f = [](int a,double b)->int{std::cout << "function lambda\n";return 99;};
std::function<std::tuple<int,double>()> af = [&tup]()->std::tuple<int,double>{return tup;};
regist_func(f,af);

fuck();
    std::cout << "Hello, world!" << std::endl;











    return 0;
}
