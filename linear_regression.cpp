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
    {
        feature_data.push_back(stof(feature));
    }
    return feature_data;
}

void linear_regresion(string data_file, string prediction_label)
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
    file.close();
    auto check_label = find(feature_names.begin(), feature_names.end(), prediction_label);
    if (check_label == feature_names.end()) exit(1);
    else index = distance(feature_names.begin(), check_label);
    
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "Usage: ./linear_regression <data_file.csv> , <prediction_label>" << endl;
        return 1;
    }
    linear_regresion(argv[1], argv[2]);
    return 0;
}

