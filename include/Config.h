#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <random>
#include <memory>
#include <unordered_map>

#define CARD_WIDTH 56
#define CARD_HEIGHT 97
#define SCREEN_WIDTH 387
#define SCREEN_HEIGHT 688

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args){
    return std::make_shared<T>(std::forward<Args>(args)...);
}

inline uint64_t RandomU64() {
  static std::random_device device;
  static std::mt19937_64 generator(device());
  static std::uniform_int_distribution<uint64_t> distribution;
  return distribution(generator);
}
