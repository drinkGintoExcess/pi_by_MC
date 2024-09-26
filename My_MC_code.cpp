#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>
#include <iomanip>
int main() {
// Start the timer
auto start = std::chrono::high_resolution_clock::now();
// Matrix size
int matrixSize = 100000;
// Define the range of the coordinates
double minCoord = -1.0;
double maxCoord = 1.0;
// Calculate the step size
double step = (maxCoord - minCoord) / (matrixSize - 1);
// Generate the x and y axis values
std::vector<double> x(matrixSize);
std::vector<double> y(matrixSize);
for (int i = 0; i < matrixSize; ++i) {
x[i] = minCoord + i * step;
y[i] = minCoord + i * step;
}
// Randomly select 1,000,000 samples
int numSamples = 100;
std::vector<int> xIndices(numSamples);
std::vector<int> yIndices(numSamples);
// Use random number generator to fill the indices
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, matrixSize - 1);
for (int i = 0; i < numSamples; ++i) {
xIndices[i] = dis(gen);
yIndices[i] = dis(gen);
}
// Create arrays for the selected sample coordinates
std::vector<double> xSamples(numSamples);
std::vector<double> ySamples(numSamples);
for (int i = 0; i < numSamples; ++i) {
xSamples[i] = x[xIndices[i]];
ySamples[i] = y[yIndices[i]];
}
// Save the data points to a file
std::ofstream dataFile("Randomly_Selected_100_Samples.txt");
for (int i = 0; i < numSamples; ++i) {
dataFile << xSamples[i] << "," << ySamples[i] << "\n";
}
dataFile.close();
// Evaluate x^2 + y^2 for the selected samples
int countWithinCircle = 0;
for (int i = 0; i < numSamples; ++i) {
if ((xSamples[i] * xSamples[i] + ySamples[i] * ySamples[i])
<= 1) {
countWithinCircle += 1;
}
}
// Calculate the result
double result = (static_cast<double>(countWithinCircle) /
numSamples) * 4;
// Stop the timer
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsedTime = end - start;
// Report the number of samples where x^2 + y^2 <= 1
std::cout << "Number of samples where x^2 + y^2 <= 1: " <<
countWithinCircle << std::endl;
std::cout << "Result (count/number of samples * 4): " << result
<< std::endl;
// Report the time taken for the entire operation
std::cout << "Time taken for the entire operation: " <<
elapsedTime.count() << " seconds" << std::endl;
return 0;
}