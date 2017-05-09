#ifndef CAPPHAT_H
#define CAPPHAT_H

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


#endif
