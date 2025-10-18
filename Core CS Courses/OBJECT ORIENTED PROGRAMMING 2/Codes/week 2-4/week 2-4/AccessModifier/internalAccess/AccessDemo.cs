using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace internalAccess
{
    public class AccessDemo
    {
        ~AccessDemo()
        {
            Console.WriteLine("Destructor calling");
        }
        private void PrivateDemo()
        {

        }
        private protected void PrivateProtectedDemo()
        {

        }
        protected void ProtectedDemo()
        {

        }
        protected internal void ProtectedInternalDemo()
        {

        }
        internal void InternalDemo()
        {

        }
        public void PublicDemo()
        {

        }
        static void Main(string[] args)
        {

        }
    }
}
