using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace internalAccess
{
    class CallingAccess
    {
        private void Makecall()
        {
            AccessDemo demo = new AccessDemo();
            demo.InternalDemo();
            demo.ProtectedInternalDemo();
            demo.PublicDemo();
        }
        
    }
}
