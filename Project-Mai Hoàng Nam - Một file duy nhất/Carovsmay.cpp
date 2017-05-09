#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

#define		CELL_X			1
#define		CELL_O			0
#define     CELL_CLOSE      -1

#define     COLSTART        3       
#define     ROWSTART        10     
 
#define     CELL_CX         4       
#define     CELL_CY         2



class CELL {
	
	public :		
	long TrangThai;
	
};

void MovetoXY(short x, short y){
    COORD xyPos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xyPos);
}

void MovetoCell(long iRow, long iCol){
    MovetoXY(COLSTART + iCol * CELL_CX, ROWSTART + iRow * CELL_CY);
}

void SetConsoleTextColor(WORD wColor)
{
    WORD wAttributes;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    wAttributes = csbi.wAttributes;
    wColor &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= wColor;
    SetConsoleTextAttribute(hConsole, wAttributes);
}

void DrawBoard(long iSize){
    long     j;
    cout << endl;
    for (long i = CELL_O; i < iSize; i++)
    {
        cout << " ";                 
        for (j = CELL_O; j < iSize; j++)
            cout << "+---";
        cout << "+" << endl;           
 
        cout << " ";                    
        for (j = CELL_O; j < iSize; j++)
            cout << "|   ";
        cout << "|" << endl;            
    }

    cout << " ";
    for (j = CELL_O; j < iSize; j++)
        cout << "+---";
    cout << "+" << endl << endl;
    cout << " Di chuyen <Arrow>  Danh Co <Spacebar>   Thoat <ESC>" << endl;
}

void DrawCell(CELL * pCell, long iRow, long iCol){
    char    cChar[2] = { CELL_O };
    WORD    wColor;
 
    switch (pCell->TrangThai)
    {
    case CELL_O:
    	wColor = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        cChar[CELL_O] = 'O';                    
        break;
    case CELL_X:
    	wColor = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
        cChar[0] = 'X';                             
        break;
    case CELL_CLOSE:
    	wColor = FOREGROUND_RED | FOREGROUND_INTENSITY;
		cChar[0] = ' ';    
        break;
    }
    MovetoCell(iRow, iCol);  
	SetConsoleTextColor(wColor);   
    cout << cChar[0];
    MovetoCell(iRow, iCol);  
}

void DrawCells(CELL ** pCell, long iSize){
    for (long row = 0; row < iSize; row++)
    for (long col = 0; col < iSize; col++)
        DrawCell(&pCell[row][col], row, col);
}

CELL ** CreateCellArray(long iSize){
    CELL ** pCell = new CELL*[iSize];
    for (long row = 0; row < iSize; row++)
    {
        pCell[row] = new CELL[iSize];
        for (long col = 0; col < iSize; col++)
        {
            pCell[row][col].TrangThai = CELL_CLOSE;
        }
    }
    return pCell;
}

void DeleteCellArray(CELL ** pCell, long iSize){
    if (pCell)
    {
        for (long i = 0; i < iSize; i++)
            delete[] pCell[i];
        delete[] pCell;
        pCell = NULL;
    }
}

void About(){
    cout << " =======          TRO CHOI CARO          =======\n";
    cout << " =======              2016               =======\n\n";
    
} 

long InputSize(long iMin, long iMax){
    long     nSize;
    do
    {
        cout << " Nhap kich thuoc trong khoang [" << iMin << "," << iMax << "]: ";
        cin >> nSize;
    } while (nSize < iMin || nSize > iMax);
    return nSize;
}

void OnArrow(short sKey, long iSize, long & iRow, long & iCol){
    switch (sKey)
    {
    case 75:    if (iCol > 0) iCol--; else iCol = iSize - 1;    break;    
    case 77:    if (iCol < iSize - 1) iCol++; else iCol = 0;    break;     
    case 72:    if (iRow > 0) iRow--; else iRow = iSize - 1;    break;    
    case 80:    if (iRow < iSize - 1) iRow++; else iRow = 0;    break;    
    }
    MovetoCell(iRow, iCol);
}


//


long tcDoc (long iRow, long iCol, CELL ** pCell, long iSize){
	
	long MangCong[7] = {0, 3, 24, 192, 1536, 12288, 98304};	
	long MangThu[7] = {0, 1, 9, 81, 729, 6561, 59049};	
	long SoQuanDich= 0, SoQuanTa= 0;
	long tong= 0;
	
	for (long count= 1; count < 6 && count + iRow < iSize; count++){
		
		if (pCell [iRow + count][iCol].TrangThai == CELL_O)
			SoQuanTa ++;
		
		else if (pCell[iRow + count][iCol].TrangThai == CELL_X){
			SoQuanDich++;
			break;
		}
		
		else if (pCell[iRow + count][iCol].TrangThai == CELL_CLOSE)
			break;	
	}
	for (long count= 1; count < 6 && iRow - count >= 0; count++){
		
		if (pCell [iRow - count][iCol].TrangThai == CELL_O)
			SoQuanTa ++;
		
		else if (pCell [iRow - count][iCol].TrangThai == CELL_X){
			SoQuanDich++;
			break;
		}
		
		else if (pCell [iRow - count][iCol].TrangThai == CELL_CLOSE)
			break;	
	}
	if (SoQuanDich == 2)
		return 0;
		
	tong += MangCong[SoQuanTa] ;
	tong -= MangThu[SoQuanDich + 1];
	return tong;
	
}

long tcNgang (long iRow, long iCol, CELL ** pCell, long iSize){
	
	long MangCong[7] = {0, 3, 24, 192, 1536, 12288, 98304};
	long MangThu[7] = {0, 1, 9, 81, 729, 6561, 59049};	
	long SoQuanDich= 0, SoQuanTa= 0;
	long tong= 0;
	
	for (long count= 1; count < 6 && count + iCol < iSize; count++){
		
		if (pCell [iRow][iCol + count].TrangThai == CELL_O)
			SoQuanTa ++;
		
		else if (pCell [iRow][iCol + count].TrangThai == CELL_X){
			SoQuanDich++;
			break;
		}
		
		else if (pCell [iRow][iCol + count].TrangThai == CELL_CLOSE)
			break;	
	}
	for (long count= 1; count < 6 && iCol - count >= 0; count++){
		
		if (pCell [iRow][iCol - count].TrangThai == CELL_O)
			SoQuanTa ++;
		
		else if (pCell [iRow][iCol - count].TrangThai == CELL_X){
			SoQuanDich++;
			break;
		}
		
		else if (pCell [iRow][iCol - count].TrangThai == CELL_CLOSE) 
			break;	
	}
	if (SoQuanDich == 2)
		return 0;
		
	tong += MangCong[SoQuanTa] ;
	tong -= MangThu[SoQuanDich + 1];
	return tong;
	
}


long tcCheoXuoi (long iRow, long iCol, CELL ** pCell, long iSize){
	
	long MangCong[7] = {0, 3, 24, 192, 1536, 12288, 98304};
	long MangThu[7] = {0, 1, 9, 81, 729, 6561, 59049};	
	long SoQuanDich= 0, SoQuanTa= 0;
	long tong= 0;
	
	for (long count= 1; count < 6 && count + iRow < iSize && count + iCol < iSize; count++){
		
		if (pCell [iRow + count][iCol + count].TrangThai == CELL_O)
			SoQuanTa ++;
		
		else if (pCell [iRow + count][iCol + count].TrangThai == CELL_X){
			SoQuanDich++;
			break;
		}
		
	else if (pCell [iRow + count][iCol + count].TrangThai == CELL_CLOSE)
			break;	
	}
	for (long count= 1; count < 6 && iRow - count >= 0 && iCol - count >= 0; count++){
		
		if (pCell [iRow - count][iCol - count].TrangThai == CELL_O)
			SoQuanTa ++;
		
		else if (pCell [iRow - count][iCol - count].TrangThai == CELL_X){
			SoQuanDich++;
			break;
		}
		
	else if (pCell [iRow - count][iCol - count].TrangThai == CELL_CLOSE)
			break;	
	}
	if (SoQuanDich == 2)
		return 0;
		
	tong += MangCong[SoQuanTa] ;
	tong -= MangThu[SoQuanDich + 1];
	return tong;
	
}


long tcCheoNguoc (long iRow, long iCol, CELL ** pCell, long iSize){

	long MangCong[7] = {0, 3, 24, 192, 1536, 12288, 98304};
	long MangThu[7] = {0, 1, 9, 81, 729, 6561, 59049};	
	long SoQuanDich= 0, SoQuanTa= 0;
	long tong= 0;
	
	for (long count= 1; count < 6 && count + iRow < iSize && iCol - count >= 0; count++){
		
		if (pCell [iRow + count][iCol - count].TrangThai == CELL_O)
			SoQuanTa ++;
		
		else if (pCell [iRow + count][iCol - count].TrangThai == CELL_X){
			SoQuanDich++;
			break;
		}
		
	else if (pCell [iRow + count][iCol - count].TrangThai == CELL_CLOSE) 
			break;	
	}
	for (long count= 1; count < 6 && iRow - count >= 0 && iCol + count < iSize; count++){
		
		if (pCell [iRow - count][iCol + count].TrangThai == CELL_O)
			SoQuanTa ++;
		
		else if (pCell [iRow - count][iCol + count].TrangThai == CELL_X){
			SoQuanDich++;
			break;
		}
		
		else if (pCell [iRow - count][iCol + count].TrangThai == CELL_CLOSE) 
			break;	
	}
	if (SoQuanDich == 2)
		return 0;
		
	tong += MangCong[SoQuanTa] ;
	tong -= MangThu[SoQuanDich + 1];
	return tong;
	
}



//////////////////////////////////////////////////////////////////////////////////////////////



long pnDoc (long iRow, long iCol, CELL ** pCell, long iSize){
	
	long MangThu[7] = {0, 1, 9, 81, 729, 6561, 59049};	
	
	long SoQuanDich= 0, SoQuanTa= 0;
	long tong= 0;
	
	for (long count= 1; count < 6 && count + iRow < iSize; count++){
		
		if (pCell [iRow + count][iCol].TrangThai == CELL_O){
			SoQuanTa ++;
			break;
		}
		else if (pCell [iRow + count][iCol].TrangThai == CELL_X)
			SoQuanDich++;
		
		else if (pCell [iRow + count][iCol].TrangThai == CELL_CLOSE)
			break;	
	}
	for (long count= 1; count < 6 && iRow - count >= 0; count++){
		
		if (pCell [iRow - count][iCol].TrangThai == CELL_O){
			SoQuanTa ++;
			break;
		}
		else if (pCell [iRow - count][iCol].TrangThai == CELL_X)
			SoQuanDich++;
		
		else if (pCell [iRow - count][iCol].TrangThai == CELL_CLOSE)
			break;		
	}	
	if (SoQuanTa == 2)
		return 0;
		
	tong += MangThu [SoQuanDich];
	return tong;
	
}

long pnNgang (long iRow, long iCol, CELL ** pCell, long iSize){

	long MangThu[7] = {0, 1, 9, 81, 729, 6561, 59049};
	
	long SoQuanDich= 0, SoQuanTa= 0;
	long tong= 0;
	
	for (long count= 1; count < 6 && count + iCol < iSize; count++){
		
		if (pCell [iRow][iCol + count].TrangThai == CELL_O){
			SoQuanTa ++;
			break;
		}
		else if (pCell [iRow][iCol + count].TrangThai == CELL_X)
			SoQuanDich++;
		
		else if (pCell [iRow][iCol + count].TrangThai == CELL_CLOSE)
			break;	
	}
	for (long count= 1; count < 6 && iCol - count >= 0; count++){
		
		if (pCell [iRow][iCol - count].TrangThai == CELL_O){
			SoQuanTa ++;
			break;
		}
		else if (pCell [iRow][iCol - count].TrangThai == CELL_X)
			SoQuanDich++;
		
		else if (pCell [iRow][iCol + count].TrangThai == CELL_CLOSE)
			break;	
	}
	if (SoQuanTa == 2)
		return 0;
		
	tong += MangThu [SoQuanDich];
	return tong;
	
}


long pnCheoXuoi (long iRow, long iCol, CELL ** pCell, long iSize){

	long MangThu[7] = {0, 1, 9, 81, 729, 6561, 59049};
	
	long SoQuanDich= 0, SoQuanTa= 0;
	long tong= 0;
	
	for (long count= 1; count < 6 && count + iRow < iSize && iCol + count < iSize; count++){
		
		if (pCell [iRow + count][iCol + count].TrangThai == CELL_O){
			SoQuanTa ++;
			break;
		}
		else if (pCell [iRow + count][iCol + count].TrangThai == CELL_X)
			SoQuanDich++;
		
		else if (pCell [iRow][iCol + count].TrangThai == CELL_CLOSE)
			break;	
	}
	for (long count= 1; count < 6 && iRow - count >= 0 && iCol - count >= 0; count++){
		
		if (pCell [iRow - count][iCol - count].TrangThai == CELL_O){
			SoQuanTa ++;
			break;
		}
		else if (pCell [iRow - count][iCol - count].TrangThai == CELL_X)
			SoQuanDich++;
		
		else if (pCell [iRow - count][iCol - count].TrangThai == CELL_CLOSE)
			break;	
	}
	if (SoQuanTa == 2)
		return 0;
		
	tong += MangThu [SoQuanDich];
	return tong;
	
}


long pnCheoNguoc (long iRow, long iCol, CELL ** pCell, long iSize){
	
	long MangThu[7] = {0, 1, 9, 81, 729, 6561, 59049};	
	
	long SoQuanDich= 0, SoQuanTa= 0;
	long tong= 0;
	
	for (long count= 1; count < 6 && count + iRow < iSize && iCol - count >= 0; count++){
		
		if (pCell [iRow + count][iCol - count].TrangThai == CELL_O){
			SoQuanTa ++;
			break;
		}
		else if (pCell [iRow + count][iCol - count].TrangThai == CELL_X)
			SoQuanDich++;
		
		else if (pCell [iRow + count][iCol - count].TrangThai == CELL_CLOSE)
			break;	
	}
	for (long count= 1; count < 6 && iRow - count >= 0 && iCol + count < iSize; count++){
		
		if (pCell [iRow - count][iCol + count].TrangThai == CELL_O){
			SoQuanTa ++;
			break;
		}
		else if (pCell [iRow - count][iCol + count].TrangThai == CELL_X)
			SoQuanDich++;
		
		else if (pCell [iRow - count][iCol + count].TrangThai == CELL_CLOSE)
			break;	
	}
	if (SoQuanTa == 2)
		return 0;
		
	tong += MangThu [SoQuanDich];
	return tong;
	
}


//


void Odiemcaonhat (CELL ** pCell, long iSize, long &i, long &j) {
	
	long DiemMax = 0, DiemTam= 0;

	long DiemTC= 0, DiemPN= 0;

	long congDoc= 0, congNgang= 0, congCheoNguoc= 0, congCheoXuoi= 0;
	long thuDoc= 0, thuNgang= 0, thuCheoNguoc= 0, thuCheoXuoi= 0;
	
	for (long iRow= 0; iRow< iSize; iRow++)
		for (long iCol= 0; iCol< iSize; iCol++){
			
			if (pCell[iRow][iCol].TrangThai == CELL_CLOSE) {
			
				congDoc = tcDoc(iRow, iCol, pCell, iSize); 
				congNgang = tcNgang(iRow, iCol, pCell, iSize); 
				congCheoNguoc = tcCheoNguoc(iRow, iCol, pCell, iSize); 
				congNgang  = tcCheoXuoi(iRow, iCol, pCell, iSize);
				
				thuDoc = pnDoc(iRow, iCol, pCell, iSize); 
				thuNgang = pnNgang(iRow, iCol, pCell, iSize); 
				thuCheoNguoc = pnCheoNguoc(iRow, iCol, pCell, iSize); 
				thuCheoXuoi = pnCheoXuoi(iRow, iCol, pCell, iSize);
				
				DiemTC = congDoc + congNgang + congCheoNguoc + congCheoXuoi;
				DiemPN = thuDoc + thuNgang + thuCheoNguoc + thuCheoXuoi;

				if (DiemTC <= DiemPN)
					DiemTam = DiemPN;
				else	
					DiemTam = DiemTC;
			
				if (DiemMax <= DiemTam) {
					DiemMax = DiemTam;
					i= iRow;
					j= iCol;
				}
			
			}
			
		}
}


long CheckWin (CELL **pCell, long iSize) {
	
	for (long iRow= 0; iRow< iSize; iRow++)
		for (long iCol= 0; iCol< iSize; iCol++){
			
			long demDocX= 0, demNgangX= 0, demCheoNguocX= 0, demCheoXuoiX= 0;
			
			if (pCell[iRow][iCol].TrangThai == CELL_X) {
			
				for (long count= 1; count < 5 && count + iRow < iSize; count++){
		
					if (pCell [iRow + count][iCol].TrangThai != CELL_X)
						break;
					if (pCell [iRow + count][iCol].TrangThai == CELL_X)
						demDocX++;	
				
				if (demDocX == 4)	
					return CELL_X;
					
				}
			
				for (long count= 1; count < 5 && count + iCol < iSize; count++){
		
					if (pCell [iRow][iCol + count].TrangThai != CELL_X)
						break;
					if (pCell [iRow][iCol + count].TrangThai == CELL_X)
						demNgangX++;	
				
				if (demNgangX == 4)	
					return CELL_X;
					
				}
			
				for (long count= 1; count < 5 && count + iRow < iSize && iCol + count < iSize; count++){
		
					if (pCell [iRow + count][iCol + count].TrangThai != CELL_X)
						break;
					if (pCell [iRow + count][iCol + count].TrangThai == CELL_X)
						demCheoXuoiX++;	
				
				if (demCheoXuoiX == 4)	
					return CELL_X;
					
				}
			
				for (long count= 1; count < 6 && count + iRow < iSize && iCol - count >= 0; count++){
		
					if (pCell [iRow + count][iCol - count].TrangThai != CELL_X)
						break;
					if (pCell [iRow + count][iCol - count].TrangThai == CELL_X)
						demCheoNguocX++;	
				
				if (demCheoNguocX == 4)	
					return CELL_X;
					
				}
			}
			
		//
			
		long demDocO= 0, demNgangO= 0, demCheoNguocO= 0, demCheoXuoiO= 0;	
			
		if (pCell[iRow][iCol].TrangThai == CELL_O) {
			
				for (long count= 1; count < 5 && count + iRow < iSize; count++){
		
					if (pCell [iRow + count][iCol].TrangThai != CELL_O)
						break;
					if (pCell [iRow + count][iCol].TrangThai != CELL_O)
						demDocO++;	
				
				if (demDocO == 4)	
					return CELL_O;
					
				}
			
				for (long count= 1; count < 5 && count + iCol < iSize; count++){
		
					if (pCell [iRow][iCol + count].TrangThai != CELL_O)
						break;
					if (pCell [iRow][iCol + count].TrangThai == CELL_O)
						demNgangO++;	
				
				if (demNgangO == 4)	
					return CELL_O;
					
				}
			
				for (long count= 1; count < 5 && count + iRow < iSize && iCol + count < iSize; count++){
		
					if (pCell [iRow + count][iCol + count].TrangThai != CELL_O)
						break;
					if (pCell [iRow + count][iCol + count].TrangThai == CELL_O)
						demCheoXuoiO++;	
				
				if (demCheoXuoiO == 4)	
					return CELL_O;
					
				}
			
				for (long count= 1; count < 6 && count + iRow < iSize && iCol - count >= 0; count++){
		
					if (pCell [iRow + count][iCol].TrangThai != CELL_O)
						break;
					if (pCell [iRow + count][iCol].TrangThai == CELL_O)
						demCheoNguocO++;	
				
				if (demCheoNguocO == 4)	
					return CELL_O;
					
				}
			}
			
				
	}
}

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

