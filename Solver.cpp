#include <algorithm>
#include <vector>
#include <math.h>
#include "Solver.h"
 
double Solver::way(const vector<int>& p) {
    double WAY = 0.0;
    for (int i = 0; i < p.size()-1; ++i) {
        WAY = WAY+res[p[i]][p[i+1]];
    }
    return WAY;
}

 Solver::Solver(ifstream &fin) : DB(fin){
    bool f=1;
    while (f) {
        f = 0;
        for (int i = 1; i < answer.size() - 2; ++i) {
            for (int j = i + 1; j < answer.size() - 1; ++j) {
                for (int k = j + 1; k < answer.size(); ++k) {
                    vector<int> new_answer = answer;
                    // Выполняем 3-opt
                    reverse(new_answer.begin() + i, new_answer.begin() + j + 1);
                    reverse(new_answer.begin() + j + 1, new_answer.begin() + k + 1);
                    if (way(new_answer) < way(answer)) {
                        answer = new_answer;
                        f = 1;
                    }
                }
            }
        }
    }
    L=way(answer);
}

