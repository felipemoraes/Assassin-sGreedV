mkdir -p bin
g++ -std=c++11 -O3 -o bin/Assassin_sGreedV src/main.cc src/solve_coin_change.cc src/solve_coin_change_fb.cc src/solve_coin_change_pd.cc src/solve_coin_change_ag.cc
