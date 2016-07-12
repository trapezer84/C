using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class if_statements

    {
        static void Main(string[] args)
        {
            /*키보드에서 영문자 1개를 입력받아서 그 문자가 소문자이면 대문자로, 
             대문자이면 소문자로 화면에 변환하여 출력하는 프로그램.*/

            char a, c; // 입력된 문자를 받을 변수 값들 
            int b; // 문자 값을 수로 변환한 값을 받을 변수

            Console.Write("하나의 영문자를 입력하시오 : ");
            a = Convert.ToChar(Console.ReadLine()); //입력된 stirng type 'ToChar'을 이용하여 char type으로 변환시킨다. 
            if ('a' <= a && 'z' >= a) //if문을 이용하여 a부터 z까지 즉, 소문자일경우 실행하도록 해준다. 
            {
                Console.WriteLine("입력된 문자는 소문자 입니다. ");
                b = a - 'a' ;
                c = Convert.ToChar(b+'A'); //char type으로 변환 시킨다. 
                Console.WriteLine("소문자를 대문자로 변환 시킨 문자" + c);
            }

            else //a~z가 아닌경우, 즉 하나의 영문자이므로 그것이 아닌 경우 대문자가 된다. 
            {
                Console.WriteLine("입력된  문자는 대문자 입니다.");
                b = a - 'A';
                c = Convert.ToChar('a' + b); //char type으로 변환 시킨다. 
                Console.WriteLine("대문자를 소문자로 변환 시킨 문자:" + c);
            }




        }
    }
}
