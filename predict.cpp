#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::stringstream;
using std::stof;

void predict(float theta0, float theta1, float millage) {
    cout << "Predicted price: " << theta0 + theta1 * millage << endl;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./predict <float_millage>" << endl;
        return 1;
    }
    ifstream file("training_data.csv");
    if (!file.good()) { cout << "Error opening file" << endl; exit(1); }
    string line;
    getline(file, line);
    cout << line << endl;
    getline(file, line);
    cout << line << endl;
    stringstream ss(line);
    float theta0, theta1;
    char usless_data;
    ss >> theta0 >> usless_data >> theta1;
    if (ss.fail()) { cout << "Error reading file" << endl; exit(1); }
    file.close();
    predict(theta0, theta1, stof(argv[1]));
    return 0;
}