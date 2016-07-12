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
            int m, n, i, j;
            // 임의로 정한 정수 20개로 이루어진 배열을 정하여 준다. 
            int[] nums = { -123, 24, 40,     2, 21, -67, 100, 0, 11,  98,
                            1023, 1, -1, 12312, 6, -645, 222, 9, 10, 800};

            //미리 정한 배열 nums를 보여준다. 
            Console.WriteLine(" 미리 정해진 정수 20개로 이루어진 배열은 : ");
            for (i = 0; i < 19; i++)
            {
                Console.Write(nums[i] + " ");
            }
            Console.WriteLine();

            //배열 정렬을 하기위한 for 루프를 생성한다. 
            for (n = 19; n > 0; n--)
            {
                for (i = 0; i < n; i++)
                {
                    j = i + 1;
                    //앞뒤로 두개씩 비교하면서 큰것이 뒤로 가도록 하게 순서를 뒤바꾸어준다. 
                    if (nums[i] >= nums[j])
                    {
                        m = nums[i];
                        nums[i] = nums[j];
                        nums[j] = m;
                    }
                }
            }
            //바꾸어진 배열을 차례대로 출력시킨다.
            Console.WriteLine();
            Console.WriteLine(" 오름차순으로 배열 된 배열은 이렇게 됩니다. :");
            for (i = 0; i < 19; i++)
            {
                Console.Write(nums[i] + " ");
            }

        }
    }
}
