using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class assignment_statements

    {
        static void Main(string[] args)
        {
            /*화씨 온도를 섭씨 온도로 변환하여 그 결과를 화면에 출력하는 프로그램. 
            변환할 화씨 온도는 키보드에서 입력받으며, 입출력은 사용자가 프로그램을 편리하게 사용할 수 있도록 한다.*/
 
            double f; //입력된 화씨 온도를 받는 변수
            double c; //변환된 섭씨온도의 변수 
            Console.Write("섭씨 온도로 변환할 화씨 온도를 입력하세요 :");
            f = Convert.ToDouble(Console.ReadLine()); //입력된 값이 string type이므로 double type으로 변환해준다. 
            c = 5.0 / 9.0 * (f - 32.0); //화씨 온도를 섭씨 온도로 변환하는 공식.
            Console.Write("변환된 섭씨온도 입니다 : ");
            Console.WriteLine("{0:#.###}", c); // 입력된 화씨 온도 f를 섭씨 온도 c로 변환 한다. 이때, {0:#.###}는 소수점 밑의 3자리까지 표시하도록 해준다. 

        }
    }
}
