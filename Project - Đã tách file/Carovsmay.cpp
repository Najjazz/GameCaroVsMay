
class CELL {
	
	public :		
	long TrangThai;
	
};

#define		CELL_X			1
#define		CELL_O			0
#define     CELL_CLOSE      -1

#define     COLSTART        3       
#define     ROWSTART        10     
 
#define     CELL_CX         4       
#define     CELL_CY         2

 
#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

#include "dichuyen.h"
#include "capphat.h"
#include "duyetdiem.h"
#include "thongbao.h"
#include "vebang.h"
#include "checkwin.h"
#include "odiemcaonhat.h"

// Main //



int main(){
	
	About();
	
	long iSize = InputSize (5, 20);
	long iCol = iSize / 2, iRow = iSize / 2;    

    system("cls");
    About();
    cout << " Kich thuoc : " << iSize << " x " << iSize << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
 
    CELL ** pCells = CreateCellArray(iSize);   
    DrawBoard(iSize);                           
    DrawCells(pCells, iSize);  
              
    MovetoCell(iRow, iCol);    
		
	pCells[iRow][iCol].TrangThai = CELL_O;
    DrawCell(&pCells[iRow][iCol], iRow, iCol);
    MovetoCell(iRow, iCol);
                        
 
    short ch;
    long comRow, comCol;
    
    do                                         
    {
    	while (1) {
		
        	ch = _getch();
        	if (ch == 32 && pCells[iRow][iCol].TrangThai != CELL_O)                           
        	{
        		pCells[iRow][iCol].TrangThai = CELL_X;
            	DrawCell(&pCells[iRow][iCol], iRow, iCol);
           		MovetoCell(iRow, iCol);
            	break;
    		}
    	
        	else if (ch == 75 || ch == 77 || ch == 72 || ch == 80)
            OnArrow(ch, iSize, iRow, iCol);
            
      	}
      	
      	if (CheckWin(pCells, iSize) == CELL_X){
			MovetoXY(5,5);
			cout << "Nguoi Thang";
			getch();
			break;
		}
      	
  		Odiemcaonhat (pCells, iSize, comRow, comCol);
	
			
    	pCells[comRow][comCol].TrangThai = CELL_O;
    	DrawCell(&pCells[comRow][comCol], comRow, comCol);
    	MovetoCell(comRow, comCol);
             		
		if (CheckWin(pCells, iSize) == CELL_O){
			MovetoXY(5,5);
			cout << "May Thang";
			getch();
			break;
		}
	
		long demOtrong =0;	
		
		for (long i= 0; i< iSize; i++)
			for (long j= 0; j< iSize; j++){
				
				if (pCells[i][j].TrangThai == CELL_CLOSE)
					demOtrong++;
				
			}
		
		if (demOtrong == 0){
			MovetoXY(5,5);
			cout << "Hoa co";
			getch();
			break;
		}
				
	
    } while (ch != 27);            
	        
    DeleteCellArray(pCells, iSize);             
	
	return 0;
}

