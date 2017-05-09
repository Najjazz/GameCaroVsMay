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
