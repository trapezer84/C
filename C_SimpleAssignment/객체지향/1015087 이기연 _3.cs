using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class switch_statements
    {
        static void Main(string[] args)
        {
            /* 키보드에서 a, b, c, d, e 중의 한 문자를 입력받아서 대문자로 변환하여 화면에 출력하는 프로그램오.
             입력한 문자가 a~e 사이의 문자가 아닌 경우는 그렇다고 출력한다. */

            char a, c; // 입력된 문자를 받을 변수 값들 
            int b; // 문자 값을 수로 변환한 값을 받을 변수
            Console.WriteLine("키보드에서 a, b, c, d, e 중의 한 문자를 입력받아서 대문자로 변환하여 화면에 출력하는 프로그램");
            a = Convert.ToChar(Console.ReadLine()); //string으로 변수를 받아 char type으로 변환하여 변수 a에 저장한다. 
            switch (a){  //swith문을 이용하여 a,b,c,d,e에 해당할 경우 실행될 프로그램을 입력해준다. 
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e': //모두 동일하게 실행하도록 break없이 계속 내려오도록 하였다. 
                    Console.WriteLine("input letter is a,b,c,d,e");
                    b = a - 'a';
                    c = Convert.ToChar(b + 'A');
                    Console.WriteLine(c);
                    break; // 조건을 만족 하면 이제 swith문을 빠져나오도록 한다. 
                default: // 위 조건을 아무것도 만족 하지 않는 경우 
                    Console.WriteLine("입력된 값은 a,b,c,d,e의 문자가 아니다. 입력된 문자는" + a + "이다"); // 그냥 a값이 값을 출력시킨다. 
                    break;

            }
        }
    }
}