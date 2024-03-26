#include <iostream>
#include <fstream>
#include <iomanip>

double map(double x, int a0, int b0, int a1, int b1)
{

    double xMap = ((x-1)*(b1-a1)/(b0-a0))-1;
    return xMap;

}

int main()
{
    std::string fileName = "data.csv"; // file name
    std::ifstream ifstr(fileName); // create ifstream object and open file

    if(ifstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    int a0 = 1;
    int b0 = 5;
    int a1 = -1;
    int b1 = 2;

    double xOld = 0;
    double xNew = 0;
    double sum = 0;
    double mean = 0;
    unsigned int countVal = 0;

    std::ofstream fout;
    fout.open("result.csv");
    fout << std::setprecision(16)<<std::scientific;
    fout << "# N Mean" << std::endl;

    while(ifstr >> xOld)
    {
        xNew = map(xOld, a0, b0, a1, b1);
        sum += xNew;
        countVal ++;
        mean = sum/countVal;
        fout << countVal <<"  "<<mean<<std::endl;
    }

    ifstr.close();
    fout.close();

    return 0;
}
