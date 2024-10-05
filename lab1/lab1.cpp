#include <iostream>
#include <vector>
using namespace std;

double SPI(vector <double> grades, vector<double> credits)
{
    double spi = 0;
    for(int i = 0; i<grades.size(); i++)
    {
        spi += (grades[i]*credits[i]);
    }
    return spi;
}

void CPI(int sems)
{
    vector <double> grades; vector<double> credits;
    double cpi = 0.0;
    for(int i = 1; i<=sems;i++)
    {
        int temp;
        cout << "Sem " << i << " : " << endl;
        cout << "Enter grades seperated by space : ";
        for(int j = 0; i<sems;i++)
        {
            cin >> temp;
            grades.push_back(temp);
        }
        cout << endl;
        cout << "Enter credits seperated by space : ";
        for(int j = 0; i<sems;i++)
        {
            cin >> temp;
            grades.push_back(temp);
        }
        double spi = SPI(grades,credits);
        cout << "SPI : " << spi << endl;
        cpi += spi;
        cout << endl;
    }
    cout << "CPI : " << cpi/sems;
}

int main()
{
    cout << "Enter number of sems : " ;
    int sems;
    cin >> sems;
    CPI(sems);
}