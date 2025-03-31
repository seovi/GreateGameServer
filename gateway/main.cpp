#include <iostream>
#include <thread>
#include <chrono>
int main() { while (true) { std::cout << "[gateway] Waiting for clients..." << std::endl; std::this_thread::sleep_for(std::chrono::seconds(5)); } }