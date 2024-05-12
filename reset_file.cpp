#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ofstream;

void output_data(float theta0, float theta1, string file_name)
{
    ofstream file(file_name);
    if (!file.good()) { cout << "Error opening file" << endl; exit(1); }
    file << "theta0,theta1\n";
    file << theta0 << "," << theta1 << endl;
    file.close();
}

int main()
{
    output_data(0, 0, "output.csv");
    return 0;
}
