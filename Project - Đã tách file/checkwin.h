#ifndef CHECKWIN_H
#define CHECKWIN_H

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


#endif
