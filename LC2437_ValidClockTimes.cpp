#include <iostream>

int countTime(std::string time) {
    int count = 1;

    for (int i = 0; i < time.length(); ++i){
        if (time[i] == '?'){
            if (i == 0){
                if (time[1] > '3' && time[1] != '?'){
                    count += 1;
                }
                else{
                    count+= 2;
                }
            }
            else if (i == 1){
                if (time[0] == '2'){
                    count +=3;
                }
                else if (time[0] < '2'){
                    count+=9;
                }
                else{
                    count = 24;
                }
            }
            else if (i == 3){
                if (count == 0){
                    count += 6;
                }
                else{
                    count *= 6;
                }
            }
            else if (i == 4){
                if (count == 0){
                    count += 10;
                }
                else{
                    count *= 10;
                }
            }
        }
    }
    return count;
}

int main(){
    std::string ex_time = "23:?9";

    std::cout << countTime(ex_time) << std::endl;
}