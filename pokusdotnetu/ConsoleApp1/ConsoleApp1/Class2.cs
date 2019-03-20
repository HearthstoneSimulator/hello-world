using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Class2
    {
        public bool Fail(int i)
        {

            if(i == 69) throw new Exception("fook ya");
            return true;
        }
    }
}
