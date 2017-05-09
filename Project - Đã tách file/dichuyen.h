#ifndef DICHUYEN_H
#define DICHUYEN_H

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

#endif
