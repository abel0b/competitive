#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

struct Problem {
    int mat_size;
    int * mat;
    int idx(int i, int j);
    bool solve();
    ~Problem();
};

int Problem::idx(int i, int j) {
    return i*mat_size+j;
}

Problem::~Problem() {
    delete[] mat;
}

bool Problem::solve() {
    bool solved = true;
    
    vector<map<int,bool>> lines(mat_size, map<int,bool>());
    vector<map<int,bool>> columns(mat_size, map<int,bool>());
    vector<int> line_nok(mat_size, 0);
    vector<int> column_nok(mat_size, 0);

    long int k = 0; // trace of the matrix
    
    bool latin_square = true;
    
    for (int line = 0; line < mat_size; line++) {
        k += mat[idx(line, line)];
        for (int col = 0; col < mat_size; col++) {
            int elt = mat[idx(line, col)];
            if (lines[line].find(elt) == lines[line].end()) {
                lines[line][elt] = true;
            }
            else {
                line_nok[line] = 1;
            }
            
            if (columns[col].find(elt) == columns[col].end()) {
                columns[col][elt] = true;
            }
            else {
                column_nok[col] = 1;
            }

            if (elt <= 0 && elt > mat_size) {
                latin_square = false;
            }
        }
    }

    long int r = std::accumulate(line_nok.begin(), line_nok.end(), 0); // nb rows with repeated elements
    long int c = std::accumulate(column_nok.begin(), column_nok.end(), 0); // nb cols with repeated elements
    
    cout << k << " " << r << " " << c << endl;

    return solved;
}

int main() {
    int test_cases;
    cin >> test_cases;

    for(int test_case=0; test_case<test_cases; ++test_case) {
        Problem problem;
        cin >> problem.mat_size;
        problem.mat = new int[problem.mat_size*problem.mat_size];
        for (int line = 0; line < problem.mat_size; line++) {
            for (int col = 0; col < problem.mat_size; col++) {
                cin >> problem.mat[problem.idx(line,col)];
            }
        }
        std::cout << "Case #" << test_case+1 << ": ";
        assert(problem.solve());
    }

    return 0;       
}