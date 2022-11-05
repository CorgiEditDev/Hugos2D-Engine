#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>

std::vector<double> history;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void checker(){
    while(false){
        int c = getchar();
            if(c == 'w'){
                for(auto&l:history){
                    std::cout << "history line "<< l << '\n';
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            } 
    }
}
int main(){
    system("CLS");
    float result = 0; 
    std::thread thread(checker);
    SetConsoleTextAttribute(hConsole, 0);
    while(true){
        float number = 0;
        std::cin >> number;
        if(result == 98678111){  /// Cheat code : 98678111
                for(auto&l:history){
                    std::cout << "history line "<< l << '\n';
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
        }
        else{
            history.push_back(number);
            result += number;
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "Current res : "<< (float)result <<'\n';
            SetConsoleTextAttribute(hConsole, 0);
        }
        
    }
}