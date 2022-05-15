#include <iostream>
#define N 9
using namespace std;
int grid[N][N] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};
bool isPresentInCol(int col, int num){ // checar si el numero esta en la fila
   for (int row = 0; row < N; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool isPresentInRow(int row, int num){ // checar si el numero esta en la columna
   for (int col = 0; col < N; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool isPresentInBox(int boxStartRow, int boxStartCol, int num){
// checar si el numero esta en el bloque de 3x3
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}
void sudokuGrid(){ //print the sudoku grid after solve imprime el 
   for (int row = 0; row < N; row++){
      for (int col = 0; col < N; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<N; i++)
            cout << "---";
      }
      cout << endl;
   }
}
bool findEmptyPlace(int &row, int &col){ // obtiene la localizacion y actualiza la fila y columna
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (grid[row][col] == 0) // se marca con un 0 vacio
            return true;
   return false;
}
bool isValidPlace(int row, int col, int num){
   // el elemento no se encuentra en la columna, fila o el bloque
   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 ,
col - col%3, num);
}
bool solveSudoku(){
   int row, col;
   if (!findEmptyPlace(row, col))
      return true; // cuando todos los espacios estan llenos
   for (int num = 1; num <= 9; num++){ // numeros validos entre 1 - 9
      if (isValidPlace(row, col, num)){ // valida si el numero esta en la iniciacion
         grid[row][col] = num;
         if (solveSudoku()) //utuliza la recursividad para ir a otros bloques
            return true;
         grid[row][col] = 0; // se convierte en un espacio de unassigned cuando no cumple las condiciocnes
      }
   }
   return false;
}
int main(){
   if (solveSudoku() == true)
      sudokuGrid();
   else
      cout << "No existe una solucion";
}