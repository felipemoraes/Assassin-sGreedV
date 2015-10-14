//
//  solve_coin_change_pd.cc
//  
//
//  Created by Felipe Moraes.
//
//
//

#include "solve_coin_change_pd.h"

SolveCoinChangePd::SolveCoinChangePd(string changes_file, string coins_file, string output_file) : SolveCoinChange(changes_file,coins_file, output_file) {
}

void SolveCoinChangePd::solve(){
    std::string line;   
    ifstream fchange(changes_file_);
    ofstream foutput(output_file_);
    if (fchange.is_open()){
        while (getline(fchange,line)){
            /*variable for time measure*/
            float execution_time = 0;
            struct timeval t_start;
            struct timeval t_end;                            
            gettimeofday(&t_start, NULL);

            int change = stoi(line);
            int *table = new int[change+1];
            int *s = new int[change+1];
            table[0] = 0;
            for (int j = 1; j <= change; ++j){
                table[j] = INT_MAX;
                for (int i = 0; i<coins_->size();++i){
                    int coin = (*coins_)[i];
                    if(j >= coin && 1 + table[j-coin] < table[j]){
                        table[j] = 1 + table[j-coin];
                        s[j] = i;
                    } 
                }
            }
            foutput << table[change] << " ";
            int k = change;
            while (k) {
                foutput << (*coins_)[s[k]] << " ";
                k = k - (*coins_)[s[k]];
            }
            foutput << std::endl;        
            delete[] table;
            delete[] s;
            gettimeofday(&t_end, NULL);
            execution_time = (t_end.tv_sec-t_start.tv_sec)*1000000;
            execution_time = (execution_time+(t_end.tv_usec-t_start.tv_usec))/1000000;
            printf("%.5f\n", execution_time);
       }
    } else {
        std::cout << "File not found: " << changes_file_ << std::endl;
    }
}


