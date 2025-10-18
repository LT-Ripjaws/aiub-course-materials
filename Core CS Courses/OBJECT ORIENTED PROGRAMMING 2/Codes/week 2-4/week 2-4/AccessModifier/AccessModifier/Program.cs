using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using internalAccess;

namespace AccessModifier
{
    public class Program: internalAccess.AccessDemo
    {
        static void Main(string[] args)
        {
           AccessDemo obj = new AccessDemo();
           obj.PublicDemo();
           Program obj2 = new Program();
           obj2.ProtectedInternalDemo();
            
        }
    }
}
