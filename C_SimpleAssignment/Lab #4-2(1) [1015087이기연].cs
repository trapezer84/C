using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int i, j;
            //메인 메소드에서 2차원 배열 A를 생성한다. 
            //배열 초기화를 통해서 A열에 정해진 정수를 배열한다. 
            int[,] A = {
                       {1,3,5,7,9},{11,13,15,17,19},{21,23,25,27,29},{31,33,35,37,39}};

            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    Console.Write(A[i, j]+" ");
                }
                //행 단위로 출력하기 위해 행과 행사이 간격을 주었다.
                Console.WriteLine();
            }

        }
    }
}