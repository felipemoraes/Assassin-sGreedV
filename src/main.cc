#include <iostream>
#include <string>
#include "solve_coin_change_ag.h"
#include "solve_coin_change_pd.h"
#include "solve_coin_change_fb.h"

using std::cout;
using std::string;

int main(int argc, char** argv){
    // Parse comand line arguments
    string enemies_file, levels_file, output_file, type;
    if (argc < 9) {
        cout << "Usage: ./Assassins_GreedV --enemeis [enemes_file] --levels [levels_file] --output [output_file] --type [fb|pd|ag]" << endl; 
        return 1;
    }
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
    if (type == "fb"){
        SolveCoinChangeFb solvec(levels_file,enemies_file,output_file);
        solvec.solve();
    } else if (type == "ag") {
        SolveCoinChangeAg solvec(levels_file,enemies_file,output_file);
        solvec.solve();
    } else if (type == "pd") {
        SolveCoinChangePd solvec(levels_file,enemies_file,output_file);
        solvec.solve();
    }
    return 0;
}
