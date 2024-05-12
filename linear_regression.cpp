#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::find;
using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::getline;
using std::cout;
using std::endl;
using std::distance;


vector<string> get_feature_names(string line)
{
    stringstream ss(line);
    string feature;
    vector<string> feature_names;
    while(getline(ss, feature, ','))
    {
        feature_names.push_back(feature);
    }
    return feature_names;
}

vector<float> get_feature_data(string line)
{
    stringstream ss(line);
    string feature;
    vector<float> feature_data;
    while(getline(ss, feature, ','))
        feature_data.push_back(stof(feature));
    return feature_data;
}


void normalize_data(vector<vector<float> > &training_data, int parameter_index)
{
    if (training_data.size() == 0) return;
    float max = training_data[0][parameter_index];
    for (int i = 0; i < training_data.size(); i++)
    {
        if (training_data[i][parameter_index] > max)
            max = training_data[i][parameter_index];
    }
    for (int i = 0; i < training_data.size(); i++)
    {
        training_data[i][parameter_index] /= max;
    }
}

void linear_regression(vector<vector<float> > &training_data, int feature_index, int label_index)
{
    float theta0 = 0.0 , theta1 = 0.0;
    float learning_rate = 1;
    int epochs = 1;
    for (int j = 0; j < epochs; j++)
    {
        float temp0 = 0.0, temp1 = 0.0;
        for (int i = 0; i < training_data.size(); i++)
        {
            float predicted_value = theta0 + theta1 * training_data[i][feature_index];
            temp0 += predicted_value - training_data[i][label_index];
            temp1 += (predicted_value - training_data[i][label_index]) * training_data[i][feature_index];
        }
        theta0 -= learning_rate * temp0 / training_data.size();
        theta1 -= learning_rate * temp1 / training_data.size();
    }
    cout << theta0 << " " << theta1 << endl;
}

void setup(string data_file, string prediction_label)
{   
    ifstream file(data_file);
    if (!file.good()) { cout << "Error opening file" << endl; exit(1); }
    string line;
    vector<vector<float> > training_data;
    vector<float> feature_data;
    vector<string> feature_names;
    int i = 0, index = 0;
    while(getline(file, line))
    {
        if (i == 0) feature_names = get_feature_names(line);
        else training_data.push_back(get_feature_data(line));
        i++;
    }
    cout << training_data.size() << endl;
    file.close();
    auto check_label = find(feature_names.begin(), feature_names.end(), prediction_label);
    if (check_label == feature_names.end()) exit(1);
    else index = distance(feature_names.begin(), check_label);
    normalize_data(training_data, index);
    normalize_data(training_data, index ^ 1);
    linear_regression(training_data, index^1, index);
}
    // bool a = true;
    // bool b = false;
    // cout << (a ^ a) << endl; // Output: 0 (false)
    // cout << (a ^ b) << endl; // Output: 1 (true)
    // cout << (b ^ a) << endl; // Output: 1 (true)
    // cout << (b ^ b) << endl; // Output: 0 (false)
    //4. **Bitwise Operators**: `&` (bitwise AND), `|` (bitwise OR), `^` (bitwise XOR), `~` (bitwise NOT), `<<` (left shift), `>>` (right shift)

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "To Run the program, please provide the data file and the prediction label as arguments" << endl;
        return 1;
    }
    if (argc != 3)
    {
        cout << "Usage: ./linear_regression <data_file.csv> , <prediction_label>" << endl;
        return 1;
    }
    setup(argv[1], argv[2]);
    return 0;
}

