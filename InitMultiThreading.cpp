#include"InitMultiThreading.h"
#include <thread>
#include <chrono>

//void kitchen_cleaner() {
//    while (true) {
//        printf("Olivia cleaned the kitchen.\n");
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//    }
//}

//void cpu_waster() {
//    printf("CPU Waster Process ID: %d\n", getpid());
//    printf("CPU Waster Thread ID %d\n", std::this_thread::get_id());
//    while (true) continue;
//}

void InitMT::examples() {
    //examples 
    //thread declaration 
  /*  std::thread olivia(kitchen_cleaner);
    for (int i = 0; i < 3; i++) {
        printf("Barron is cooking...\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
    printf("Barron is done!\n");

    //Important : this will make the current thread wait till olivia thread finishes its work 
    olivia.join();*/

    //std::thread olivia(kitchen_cleaner);
    ////Important : this will detach the current thread from olvia thread and enables it to finish the program 
    //olivia.detach();
    //for (int i = 0; i < 3; i++) {
    //    printf("Barron is cooking...\n");
    //    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    //}
    //printf("Barron is done!\n");

    //printf("Main Process ID: %d\n", getpid());
    //printf("Main Thread ID: %d\n", std::this_thread::get_id());
    //std::thread thread1(cpu_waster);
    //std::thread thread2(cpu_waster);

    //while (true) { // keep the main thread alive "forever"
    //    std::this_thread::sleep_for(std::chrono::seconds(1));
    //}
}

void InitMT::execute() {
	std::map<int, int> limits = { {6, 16},{20, 112} };
	Context::execute(limits, "InitMultiThreading.cpp");
}


