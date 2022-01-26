#include <iostream>
#include <string>
#include<cmath>
#include<vector>                                                                //for vector

using namespace std;
int x=0;
using vec1i = vector<string>;                                                      //using of vector integer one dimensional
using vec1d = vector<double>;                                                      //using of vector integer one dimensional

void per2(vec1i,int, int, vec1d);
int factorial(int n);
double maxi = 0.0;
int main()
{
    cout << "Enter the string: \t\t press y for stop\n";
    int max_of_number = 101;
    vec1i s2(max_of_number);                                                            //create vg vectore 1d with size step 1999 
    for (int i = 0; i < max_of_number; i++) {
        s2[i] = "00";
    }

    int number_of_node = 0;
    string iff = "n";
    while (iff == "n") {
        cin >> s2[number_of_node];
        if (s2[number_of_node] == "y")break;
        number_of_node++;
    }
    cout << "Size=" << number_of_node << endl;
    vec1d s3(number_of_node);                                                            //create vg vectore 1d with size step 1999 
    for (int i = 0; i < number_of_node; i++) {
        maxi += abs(stod(s2[i]));
        s3[i] = stod(s2[i]);
    }
    maxi = maxi * 2;
    double sum = 0;
    int last = number_of_node - 1;
    for (int i = 0; i < number_of_node; i++) {
        sum += abs(stod(s2[last]) + stod(s2[i]));
        last--;
    }
    cout << "Min:" << "\t formola: 1-(" << maxi << "/" << maxi << ")\t Delta W:" << (1 - double(maxi) / double(maxi)) << endl;
    cout << "Max:"<<"\t formola: 1-("<< sum<<"/"<< maxi  << ")\t Delta W:" <<(1- double(sum) / double(maxi) )<<endl<< endl<< endl;
    
    //cin >> s2[o];


    per2(s2, 0, number_of_node - 1, s3);
    cout << "Size=" << number_of_node << endl;
    cout << "_________________done"<<endl;
    return 0;
}

void per2(vec1i s2, int k, int n, vec1d spell)
{
    if (k == n)
    {

        x++;
        double sum = 0;
        for (int i = 0; i <= n; i++) {
            cout << s2[i]<<'\t';
            sum += abs(spell[i] + stoi(s2[i]));
        }
        cout <<"formola: 1-("<< sum << "/" << maxi  << ")\t Delta W:" << (1 - double(sum) / double(maxi)) << endl;
    }
    else
    {

        for (int i = k; i <= n; i++)
        {
            string c2="00";
            c2 = s2[i];
            s2[i] = s2[k];
            s2[k] = c2;
            per2(s2, k + 1, n, spell);

        }
    }
}
int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}
