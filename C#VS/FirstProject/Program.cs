using System;

namespace FirstProject
{
    class Program
    {
        static void Main(string[] args)
        {
            string theName = "This is a name";
            Console.WriteLine(theName);
            object anyType = "This is an object which can take any time";
            Console.WriteLine(anyType);
            object anyType2 = 3000;
            Console.WriteLine(anyType2);

            object? theObj = 10;
            int? theInt = null;
            theInt = (int)theObj;

            Console.WriteLine(theObj);
            Console.WriteLine(theInt);

        }
    }
}
