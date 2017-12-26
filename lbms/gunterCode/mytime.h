#include<stdio.h>
#include <ctime.h>
#include <Cstring.h> 
class Timer
{
 private:
    static const int size = 50;
    std::time_t time;
    std::tm localTime;
    char Ascll[size];
    char flag;
 public:
    Timer() 
    {
       std::time(&time);
       flag = 0;
    }
    ~Timer() {}
    const char* printTime()
    {
       if(!flag)
       {
          localTime = *std::localtime(&time);
          std::strcpy(Ascll, std::asctime(&localTime));
       }
       flag++;
       return Ascll;
    }
    double timeDiff(Timer* time2) const
    {
       return difftime(time, time2 -> time);
    }
} ; 

*/
/*
void main()
{
    Timer t1;
    for(int i = 0; i < 10000; i++ )
    {
       cout << i;
    }
    Timer t2;
    std::cout << t1.printTime() << std::endl;
    std::cout << t2.printTime() << std::endl;
    std::cout << t2.timeDiff(&t1) << std::endl;
	
}
*/