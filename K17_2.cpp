#include <fstream>
#include <iomanip>
using namespace std;

struct Seka
{
        int zin;
        int kom[30];
};

int main()
{
        int x0, y0,
               x1, y1,
               x, y,
               n,
               w = 0;
        struct Seka seka[10] = {};

        ifstream fd ("U2.txt");
        fd >> x0 >> y0
             >> x1 >> y1
             >> n;

        ofstream fr("U2rez.txt");

        for (int i = 0; i < n; i++)
        {
                int tempKom;
                x = x0;
                y = y0;
                w = 0;
                int k;
                fd >> k;
                for (int j = 0; j < k; j++) {
                        if( x == x1 && y == y1 )
                        {
                                for (j; j < k; j++)
                                        fd >> tempKom;
                                break;
                        }

                        fd >> tempKom;

                        seka[i].zin++;
                        seka[i].kom[w++] = tempKom;
                        if(tempKom == 1) y++;
                        if(tempKom == 2) x++;
                        if(tempKom == 3) y--;
                        if(tempKom == 4) x--;
                }
                if(  x == x1 && y == y1 )
                {
                       fr << setw(20) << left <<  "pasiektas tikslas";
                        for (int q = 0; q < seka[i].zin; q++)
                                fr << seka[i].kom[q] << ' ';
                        fr << seka[i].zin;
                        fr << endl;
               }
                else
                {
                        fr << setw(20) << left << "sekos pabaiga";
                        for(int h = 0; h < seka[i].zin; h++)
                                fr << seka[i].kom[h] << ' ';
                        fr << seka[i].zin;
                        fr << endl;
                }
        }
        fr.close();
        fd.close();
}
