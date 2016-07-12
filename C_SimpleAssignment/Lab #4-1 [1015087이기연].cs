using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class MyCalc
    {
        public int Myadd(int a, int b)
        {
            return a + b;
        }
        public int MyProduct(int a, int b)
        {
            return a * b;
        }

        class Program
        {
            static void Main(string[] args)
            {

                int x, a, b;

                Console.WriteLine("무엇을 계산할까요? (1:덧셈,2:곱셈)");
                //정수 하나를 받는다. 어떠한 계산을 해야할지 정해진 수를 넣는다.
                //그리고 character type을 int type으로 바꾸어 준다. 
                x = Convert.ToInt16(Console.ReadLine());

                Console.WriteLine("하나씩 수를 입력하고 enter 입력하시오.");
                //정수 하나 씩을 입력 받아 정수로 바꾸어 준다. 
                a = Convert.ToInt16(Console.ReadLine());
                b = Convert.ToInt16(Console.ReadLine());

                MyCalc one = new MyCalc();

                switch (x)
                {
                    case 1:
                        Console.WriteLine(a + "+" + b + "은");
                        Console.WriteLine(one.Myadd(a, b));
                        break;
                    case 2:
                        Console.WriteLine(a + "*" + b + "은");
                        Console.WriteLine(one.MyProduct(a, b));
                        break;
                    default:
                        Console.WriteLine("1,2번 중에 선택하시오");
                        break;

                }
            }
        }
    }
}
