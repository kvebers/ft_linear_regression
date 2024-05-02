#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::getline;
using std::cout;
using std::endl;


vector<string> get_feature_names(string line)
{
    stringstream ss(line);
    string feature;
    vector<string> feature_names;
    while(getline(ss, feature, ','))
    {
        feature_names.push_back(feature);
        cout << feature << endl;
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

int linear_regresion()
{
    ifstream file("data.csv");
    string line;
    vector<vector<float> > training_data;
    vector<float> feature_data;
    vector<string> feature_names;
    int i = 0;
    while(getline(file, line))
    {
        std::cout << line << endl;
        if (i == 0) get_feature_names(line);
        else training_data.push_back(get_feature_data(line));
    }
    cout << feature_names.size() << endl;
    return 0;
}




int main()
{
    linear_regresion();
    return 0;
}