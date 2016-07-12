using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class for_statements
    {
        static void Main(string[] args)
        {
            /* 양의 정수 1개를 읽은 후 이 숫자가 소수 (prime number) 인지 아닌지 점검하여 그 결과를 화면에 출력하는 프로그램. */

            double a, b;

            for (a = 2; a <= 50; a++) // 1부터 50까지의 양의 정수 중 소수를 찾기 위해 범위를 정해준다. 
            {
                for (b = 2.0; b <= a; b++) // 양의 정수 a를 나눌 정수. 
                {
                    if (a % b == 0) // 나머지가 0이 될 경우는 2가지 경우가 있다. 
                    {
                        if (a == 2 && a == b) // 소수인 경우에는 자기 자신을 나누었을 때 나머지가 0이 된다. 
                        {
                            Console.WriteLine(a + "는 소수다."); // 따라서 a는 소수다. 
                            break;
                        }
                        else // 소수가 아니다. 중간에 다른 수로 나누어 떨어지므로.
                            break;
                    }
                    else
                        continue;
                }
            }
        }
    }
}
