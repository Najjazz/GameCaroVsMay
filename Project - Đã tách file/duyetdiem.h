#ifndef DUYETDIEM_H
#define DUYETDIEM_H

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


#endif
