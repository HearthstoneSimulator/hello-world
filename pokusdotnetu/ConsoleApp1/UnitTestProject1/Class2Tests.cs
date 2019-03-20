using Microsoft.VisualStudio.TestTools.UnitTesting;
using ConsoleApp1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1.Tests
{
    [TestClass()]
    public class Class2Tests
    {
        [TestMethod()]
        public void FailTest()
        {
            var ook = new Class2();
            bool j = ook.Fail(69);
            Assert.AreEqual(j, true);
        }

        [TestMethod()]
        public void FailTestwillPass()
        {

            var ook = new Class2();
            bool j = ook.Fail(1488);
            Assert.AreEqual(j, true);
        }
    }
}