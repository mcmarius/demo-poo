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

// Override base class with your custom functionality
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		// Name your application
		sAppName = "Example";
	}

public:
    // cppcheck-suppress unusedFunction
	[[maybe_unused]] bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

    // cppcheck-suppress unusedFunction
	[[maybe_unused]] bool OnUserUpdate([[maybe_unused]] float fElapsedTime) override
	{
		// Called once per frame, draws random coloured pixels
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
		return true;
	}
};

int main() {
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();

    def<instrument> d;
    d.f();

}
