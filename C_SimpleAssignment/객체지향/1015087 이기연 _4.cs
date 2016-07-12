using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class For_Statements
    {
        static void Main(string[] args)
        {
            /* 양의 정수 1개를 읽은 후 이 숫자가 소수 (prime number) 인지 아닌지 점검하여 그 결과를 화면에 출력하는 프로그램. */

            double a, b;

            Console.Write("양의 정수를 입력 하시오:");
            a = Convert.ToDouble(Console.ReadLine()); // 입력한 값을 double type로 변환해준다.

            for (b = 2.0; b <= a; b++) // a를 2부터 a까지 하나하나씩 나누어 주기 위해 수를 정한다. 
            {
                if (a % b == 0) // 나머지가 0이 될 경우는 2가지 경우가 있다. 
                {
                    if (a == 2 && a == b) // 소수인 경우에는 자기 자신을 나누었을 때 나머지가 0이 된다. 
                    {
                        Console.WriteLine(a + "는 소수다."); // 따라서 a는 소수다. 
                        break;
                    }
                    else // 소수가 아니다. 중간에 다른 수로 나누어 떨어지므로.
                    {
                        Console.WriteLine(a + "는 소수가 아니다.");
                        break;
                    }
                }
                else
                    continue;
            }
        }
    }
}