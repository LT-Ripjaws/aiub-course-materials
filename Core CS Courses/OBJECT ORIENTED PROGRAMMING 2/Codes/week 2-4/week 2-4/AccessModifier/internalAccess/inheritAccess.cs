using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace internalAccess
{
    class inheritAccess: AccessDemo
    {
        public void test()
        {
            ProtectedDemo();
            ProtectedInternalDemo();
            PublicDemo();
            InternalDemo();
            PrivateProtectedDemo();
        }
    }
}
