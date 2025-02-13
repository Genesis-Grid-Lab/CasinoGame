#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>

#include <memory>
#include <unordered_map>

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args){
    return std::make_shared<T>(std::forward<Args>(args)...);
}
