using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Labtask2
{
    class Matrix
    {
        public int[,] MultiplyMatrices(int[,] matrixA, int[,] matrixB)
        {
            int rowsA = matrixA.GetLength(0);
            int colsA = matrixA.GetLength(1);
            int rowsB = matrixB.GetLength(0);
            int colsB = matrixB.GetLength(1);

            int[,] result  = new int[rowsA, colsA];
            for (int i = 0; i < rowsA; i++)
            {
                for (int j = 0; j < colsB; j++)
                {
                    result[i, j] = 0;
                    for (int k = 0; k < colsA; k++)
                    {
                        result[i, j] += matrixA[i, k] * matrixB[k, j];
                    }
                }
            }
            return result;
        }

        public void PrintMatrix(int[,] matrix)
        {
            int rows = matrix.GetLength(0);
            int cols = matrix.GetLength(1);

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0;j < cols; j++)
                {
                    Console.Write(matrix[i, j] + "\t");

                }
                Console.WriteLine();
            }
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            //1.C# Linear array.
            //int[] arr1 = new int[5] { 1, 2, 3, 4, 5 }; 

            //foreach (int item in arr1)
            //{
            //    Console.WriteLine(item);
            //}



            //2.C# 2D Array.
            //int[ , ] multiarr = new int[2, 4] { { 1, 2, 3, 4 }, { 5, 6, 7, 8 } };

            //for (int i = 0; i < 2; i++)
            //{
            //    for (int j = 0; j < 4; j++)
            //    {
            //        Console.Write(multiarr[i, j] + "\t");
            //    }
            //    Console.WriteLine();
            //}



            //3.C# Jagged Array with 5 arrays inside.
            //int[][] jaggedArray = new int[5][];

            //jaggedArray[0] = new int[3] { 1, 2, 3 };
            //jaggedArray[1] = new int[4] { 4, 5, 6, 7 };
            //jaggedArray[2] = new int[5] { 8, 9, 10, 11, 12};
            //jaggedArray[3] = new int[2] { 13, 14 };
            //jaggedArray[4] = new int[4] { 15, 16, 17, 18 };

            //foreach (int[] arra in jaggedArray)
            //{
            //    foreach (int item in arra)
            //    {
            //        Console.Write(item + "\t");
            //    }
            //    Console.WriteLine();
            //}


            //4.C# program to initialize 3 2D array and multiply them.
            //int[,] matrix1 = { { 1, 2 }, { 3, 4 } };
            //int[,] matrix2 = { {5,6 }, { 7, 8 } };
            //int[,] matrix3 = { {9, 10 }, { 11, 12 } };

            //Matrix obj = new Matrix();
            //int[,] result = obj.MultiplyMatrices(obj.MultiplyMatrices(matrix1, matrix2),matrix3);
            //obj.PrintMatrix(result);



            Console.ReadKey();
        }
    }
}
