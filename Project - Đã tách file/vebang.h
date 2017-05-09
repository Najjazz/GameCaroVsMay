#ifndef VEBANG_H
#define VEBANG_h

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



#endif
