#include <iostream>
#include "Car.h"

using namespace std;


int main(){
        if(gpioInitialise()<0){
                printf("fail\n");
                return 1;
        }
        Car car;
        int choice=0;
        

        /*
        cout<<"hello\n";
        cin>>choice;
        while(choice!=3){
        if(choice==1){
                car.moveForward();
        }
        if(choice==2){
                car.turnLeft();
        }
        if(choice==3){
                break;
        }
        */
      //car.turnLeft();

    while (choice != 5) {
        std::cout << "\n===== CAR MENU =====\n";
        std::cout << "1. Move Forward\n";
        std::cout << "2. Move Backward\n";
        std::cout << "3. Turn Left\n";
        std::cout << "4. Turn Right\n";
        //cout << "5. Camera ON\n";
        //cout << "6. Camera OFF\n";
        //cout << "7. Take Picture\n";
        //cout << "8. Show Car Status\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        
        if (choice == 1) car.moveForward();
        else if (choice == 2){ 
      car.moveBackward();
        //gpioTerminate();
        }
        else if (choice == 3){ 
        car.turnRight();
        //gpioTerminate();
        }
        else if (choice == 4){ 
        car.turnLeft();
        //gpioTerminate();
        }
        //else if (choice == 5) car.cameraOn();
       //else if (choice == 6) car.cameraOff();
       //else if (choice == 7) car.takePicture();
       //else if (choice == 8) car.printStatus();
        else if (choice == 5) {
            std::cout << "Exiting program.\n";
car.stop();
            break;
            return 0;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
       //gpioTerminate();
    return 0;
    
}
       // gpioTerminate();

/*
int main() {
        if (gpioInitialise() < 0) {
        std::cerr << "pigpio init failed\n";
        // You might want to throw or set an error flag
        return 1;
        } 
    Car car;
    int choice;

    while (true) {
        std::cout << "\n===== CAR MENU =====\n";
        std::cout << "1. Move Forward\n";
        std::cout << "2. Move Backward\n";
        std::cout << "3. Turn Left\n";
        std::cout << "4. Turn Right\n";
        //cout << "5. Camera ON\n";
        //cout << "6. Camera OFF\n";
        //cout << "7. Take Picture\n";
        //cout << "8. Show Car Status\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) car.moveForward();
        else if (choice == 2) car.moveBackward();
        else if (choice == 3) car.turnLeft();
        else if (choice == 4) car.turnRight();
        //else if (choice == 5) car.cameraOn();
       //else if (choice == 6) car.cameraOff();
       // else if (choice == 7) car.takePicture();
       // else if (choice == 8) car.printStatus();
        else if (choice == 5) {
            std::cout << "Exiting program.\n";
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
*/
