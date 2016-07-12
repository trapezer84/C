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
            //2차원 배열 A를 nested for 루프를 사용하여 저장하도록 한다. 
            int[,] A = new int[4, 5];
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    A[i, j] = (i*10) + (2*j+1);
                    
                }  
            }
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