#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <signal.h>
using namespace std;
// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
   cout << "Caught signal " << signum << endl;
   // Terminate program
   exit(signum);
}
int main(){
   // Register signal and signal handler
   signal(SIGINT, signal_callback_handler);
   while(true){
      cout << "Program processing..." << endl;
      sleep(5);
   }
   cout <<  "this code unreachable" << endl;
   return EXIT_SUCCESS;
}