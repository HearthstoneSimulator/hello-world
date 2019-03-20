using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class SecondClass
    {
        int a;

        public bool pravda(int i)
        {
            if (i > 0)
            {
                return true;
            }
            return false;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Hello World!");
            Console.WriteLine("Oh no a new version!!??");
            Class1 c1 = new Class1();
            Console.WriteLine(c1.sayHello());
            Class2 c2 = new Class2();
            //this is still fine..
             
                //now we fail
         
        }
    }
}
