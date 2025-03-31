#include <iostream>
#include <thread>
#include <chrono>
int main() { while (true) { std::cout << "[chat] Listening for messages..." << std::endl; std::this_thread::sleep_for(std::chrono::seconds(5)); } }