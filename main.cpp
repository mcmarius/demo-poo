//
// Created by marius on 19/03/2020.
//

#include <iostream>
#include <concepts>
#include <olcPixelGameEngine.h>

template <typename T>
concept Printable = requires(const T& v, std::ostream& os) {
    os << v;
};

template <Printable T>
class abc {
    T x;
public:
    friend std::ostream& operator<<(std::ostream& os, const abc<T>& ob) { os << ob.x; return os; }
};

template <typename T>
concept Playable = requires(T v) {
    { v.play() } -> std::same_as<void>;
};

class instrument {
    std::string nume;
public:
    void play() { std::cout << nume; }
    // int play() { std::cout << nume; return 1; }  // err
};

template <Playable T>
class def {
    T x;
public:
    void f() {
        x.play();
    }
};

int main() {
    def<instrument> d;
    d.f();

}
