#include <iostream>
#include <string>
#include<cmath>
#include<vector>                                                                //for vector

using namespace std;
int x=0;
using vec1i = vector<string>;                                                      //using of vector integer one dimensional

int** per2(vec1i,int, int, int**);
int factorial(int n);

int main()
{
    cout << "Enter the string: \t\t press y for stop\n";
    int max = 100;
    vec1i s2(max);                                                            //create vg vectore 1d with size step 1999 
    for (int i = 0; i < max; i++) {
        s2[i] = "00";
    }

    int o = 0;
    string iff = "n";
    while (iff == "n") {
        cin >> s2[o];
        if (s2[o] == "y")break;
        o++;
    }
    cout << "Size=" << o << endl;
    int** spell = new int* [o];
    for (int i = 0; i < o; i++)
        spell[i] = new int[factorial(o)]{ 0 };
    //int** spell = new int[factorial(o)]; //Making Array
    spell =per2(s2, 0, o - 1, spell);
    cout << "Size=" << o << endl;
    //cout << "Permutation=" << spell[0][2] << endl;//[->][|]


    

    int maxi = 0;
    for (int i = 0; i < o; i++) {
        maxi += abs(spell[i][0]);
    }
    maxi = maxi * 2;
    double Pro = 0.0;

    for (int j = 0; j < factorial(o); j++)
    {
        cout << "node:" << j + 1 << '\t';
        int sum = 0;
        for (int i = 0; i < o; i++) {

            cout <<spell[i][j] << '\t';  //[shomare jaigesht][adad]  for123 [0,5][0,2]      
            sum += abs(spell[i][0]-spell[i][j]);
        }
        Pro = double(sum)/ double(maxi);
        cout << "sum:"<<sum<<'\t'<<"max:"<<maxi<<'\t' << "P:" << Pro;
        cout << endl;

    }

    cout << "_________________done"<<endl;

    return 0;
}

int** per2(vec1i s2, int k, int n, int** spell)
{
    if (k == n)
    {

        x++;

        //string dd;
        for (int i = 0; i <= n; i++) {
            //cout << s2[i];
            //dd += s2[i];
            spell[i][x - 1] = stoi(s2[i]);
        }
        //cout << endl;

        //spell[x] = stoi(dd);


    }
    else
    {

        for (int i = k; i <= n; i++)
        {
            string c2="00";

            c2 = s2[i];
            s2[i] = s2[k];
            s2[k] = c2;

            spell = per2(s2, k + 1, n, spell);

        }
    }
    return spell;
}
int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}
