/*
    ID: storm59061
    LANG: C++
    TASK: rect1
*/
#include <fstream>
#include <vector>


using namespace std;


struct RECT
{
    int x[2];
    int y[2];
    int color;
};


RECT intersect (RECT a, RECT b)
{
    RECT rtrn;


    //high left, high bottom, low right, low top
    if (a.x[0] < b.x[0])
        rtrn.x[0] = b.x[0];
    else
        rtrn.x[0] = a.x[0];


    if (a.y[0] < b.y[0])
        rtrn.y[0] = b.y[0];
    else
        rtrn.y[0] = a.y[0];


    if (a.x[1] > b.x[1])
        rtrn.x[1] = b.x[1];
    else
        rtrn.x[1] = a.x[1];


    if (a.y[1] > b.y[1])
        rtrn.y[1] = b.y[1];
    else
        rtrn.y[1] = a.y[1];


    return rtrn;
}


int sub_rect (vector<RECT> *rect, RECT a, RECT b)
{
    RECT add[4];
    int m, n = 0;


    //Test for empty
    if (b.y[1] <= b.y[0] || b.x[1] <= b.x[0])
    {
        rect->push_back (a);
        return 0;
    }


    //Create rectangles
    add[0].x[0] = a.x[0];
    add[0].y[0] = b.y[1];
    add[0].x[1] = a.x[1];
    add[0].y[1] = a.y[1];

    add[1].x[0] = b.x[1];
    add[1].y[0] = b.y[0];
    add[1].x[1] = a.x[1];
    add[1].y[1] = b.y[1];

    add[2].x[0] = a.x[0];
    add[2].y[0] = a.y[0];
    add[2].x[1] = a.x[1];
    add[2].y[1] = b.y[0];

    add[3].x[0] = a.x[0];
    add[3].y[0] = b.y[0];
    add[3].x[1] = b.x[0];
    add[3].y[1] = b.y[1];


    //Test for <= 0 area, if not, then add
    for (m = 0;m < 4;m++)
    {
        if (add[m].x[1] > add[m].x[0] && add[m].y[1] > add[m].y[0])
        {
            add[m].color = a.color;
            rect->push_back (add[m]);
            n++;
        }
    }


    return n;
}


int main ()
{
    ifstream in;
    ofstream out;
    vector<RECT> rect;
    RECT new_rect;
    int crect, area[2500];
    int a, b, c;


    for (a = 0;a < 2500;a++)
        area[a] = 0;


    in.open ("rect1.in");
    rect.push_back (new_rect);
    rect[0].x[0] = rect[0].y[0] = 0;
    rect[0].color = 1;
    in >> rect[0].x[1] >> rect[0].y[1] >> crect;


    for (a = 1;a <= crect;a++)
    {
        rect.push_back (new_rect);
        in >> rect.back ().x[0] >> rect.back ().y[0] >> rect.back ().x[1] >> rect.back ().y[1] >> rect.back ().color;


        c = rect.size ();
        for (b = 0;b < c - 1;b++)
        {
            sub_rect (&rect, rect.front (), intersect (rect.front (), rect[c - b - 1]));
            rect.erase (rect.begin ());
        }
    }


    in.close ();

    //Calculate area of each and add them
    b = rect.size ();


    for (a = 0;a < b;a++)
        area[rect[a].color - 1] += (rect[a].x[1] - rect[a].x[0]) * (rect[a].y[1] - rect[a].y[0]);


    out.open ("rect1.out");


    for (a = 0;a < 2500;a++)
    {
        if (area[a] != 0)
            out << a + 1 << " " << area[a] << "\n";
    }


    out.close ();


    return 0;
}
