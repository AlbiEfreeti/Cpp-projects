#include <iostream>
#include <random>
#include <vector>


using namespace std;
//Author: Alba Gracia, Informatics Engineering Student in Polytecnic University of Valencia
//19.04.2024

//William Springer's "Programmer's Guide to Computer Science". Chessboard exercise from page 125.
//Algorithm: creates a random square Matrix, representing a chessboard with white and black pieces, represented in 1s and 0s. The probability
//for 0 and 1 is 0.5, it can be changed. a random matrix of order (1 to 50) is created, submatrix function checks for the biggest chessboard inside
//our matrix that only cosists of 1s. The order of that board is printed as well as the starting matrix.




double p = 0.5;
random_device rd;
mt19937 gen(rd());
discrete_distribution<> distrib({p, 1.0 - p}); // Probability distribution for 0s and 1s

int getRandomZeroOrOne() {
    return distrib(gen);
}

vector<vector<int>> createRandomMatrix() {
    int n = uniform_int_distribution<int>(1, 50)(gen); // Random size between 1 and 1000
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // Initialize matrix with all 0s

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = getRandomZeroOrOne();
        }
    }

    return matrix;
}

int submatrix(const vector<vector<int>>& matrix) {
    int matrixsize = matrix.size();
    int submatrixcounter = 1;

    for (int i = 0; i < matrixsize; ++i) {
        for (int j = 0; j < matrixsize; ++j) {
            if (matrix[i][j] == 1) {
                int k = 1;
                while (i + k < matrixsize && j + k < matrixsize) {
                    bool allOnes = true;
                    for (int r = i; r <= i + k; ++r) {
                        for (int c = j; c <= j + k; ++c) {
                            if (matrix[r][c] != 1) {
                                allOnes = false;
                                break;
                            }
                        }
                        if (!allOnes) {
                            break;
                        }
                    }
                    if (allOnes) {
                        ++k;
                        if (k > submatrixcounter) {
                            submatrixcounter = k;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }

    return submatrixcounter;
}

int main() {
    vector<vector<int>> randomMatrix = createRandomMatrix();
    int subMSize = submatrix(randomMatrix);

    cout << "Size of kxk Matrix with all 1s: " << subMSize << endl;

    // Print the random matrix
    cout << "Random Matrix of order: " << randomMatrix.size() << endl;
    for (const auto& row : randomMatrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}


