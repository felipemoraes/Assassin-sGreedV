#include <iostream>
#include <string>
#include "solve_coin_change_fb.h"

using std::cout;
using std::string;

int main(int argc, char** argv){
    // Parse comand line arguments
    string enemies_file, levels_file, output_file, type; 
    for(int i=0; i<argc; i++){
       string param(argv[i]);
        if(param == "--enemies" || param == "-e"){
            i++;
            enemies_file = string(argv[i]);
        } else if (param == "--levels" || param == "-l") {
            i++;
            levels_file = string(argv[i]);
         } else if (param == "--output" || param == "-o"){
            i++;
            output_file = string(argv[i]);
        } else if (param == "--type" || param == "-t"){
            i++;
            type = string(argv[i]);
        }
    }
    SolveCoinChangeFb solve_fb(levels_file,enemies_file,output_file);
    solve_fb.solve();
    return 0;
}
