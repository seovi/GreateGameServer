#include <iostream>
#include <thread>
#include <chrono>
int main() { while (true) { std::cout << "[zone] Updating world state..." << std::endl; std::this_thread::sleep_for(std::chrono::seconds(5)); } }