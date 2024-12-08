#include "detect.h"

void test( std::string name )
{
    Detect d;
    DetectR R;
    d.show( name, R );
}

int main()
{
    test( "red.mp4" );
    return 0;
}