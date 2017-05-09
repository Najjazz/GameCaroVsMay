#ifndef ODIEMCAONHAT_H
#define ODIEMCAONHAT_H

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

#endif
