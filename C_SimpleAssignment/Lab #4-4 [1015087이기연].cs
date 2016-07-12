using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            int i, m;
            //정수 10개로 된 임의의 배열을 지정해준다. 
            int[] A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
            //입력된 배열을 출력시킨다.
            Console.WriteLine("입력된 정수 10개의 배열은 : ");
            for (i = 0; i < 10; i++)
            {
                Console.Write(A[i] + " ");
            }
            Console.WriteLine();

            Console.WriteLine("Shift Left 할 만큼 수를 입력하시오. :");

            //입력된 수를 받아 정수로 바꾸어준다. 
            m = Convert.ToInt32(Console.ReadLine());
            //새로운 배열을 할 배로운 배열 B를 생성한다. 
            int[] B = new int[10];

            //입력된 수 이후부터의 A배열을 B에 먼저 입력시킨다. 
            //입력된 수가 1~10일때만 실행하도록 한다.
            if (1 <= m && m <= 10)
            {
                for (i = 0; i <= 9 - m; i++)
                {
                    B[i] = A[i + m];
                }
                //입력된 수 까지의 A배열을 B에 입력 시킨다. 
                for (i = 0; i <= m - 1; i++)
                {
                    B[10 - m + i] = A[i];
                }
                //그리고 완성된 배열 B를 출력시킨다. 
                for (i = 0; i < 10; i++)
                {
                    Console.Write(B[i] + " ");
                }
            }
            //아닐 경우 아니라는 문구를 출력시킨다. 
            else
            {
                Console.WriteLine("Shift Left를 할 범위를 넘었습니다. ");
            }
        }
    }
}
