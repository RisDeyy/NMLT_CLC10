#include<iostream>
// #include"PhanSo.h"
// #include"SoPhuc.h"
#include"ChuongTrinh.h"
#include <chrono>

using namespace std;

void nhapPhuongTrinhSoThuc(float &A, float &B, float &C, float &D){
    cout << "\n -------------------------------------------";
    cout << "\n|      CHON DANG PHUONG TRINH CAN NHAP      |";
    cout << "\n|                                           |";
    cout << "\n| Dang 1: Ax + B = 0                        |";
    cout << "\n| Dang 2: Ax + B = Cx + D                   |";
    cout << "\n -------------------------------------------";

    int choice;
    cout << "\nBan lua chon dang: ";
    cin >> choice;
    switch (choice)
    {
    case 1:{
        cout << "\nNhap A: ";
        cin >> A;
        cout << "Nhap B: ";
        cin >> B;
        break;
    }

    case 2:{
        cout << "\nNhap A: ";
        cin >> A;
        cout << "Nhap B: ";
        cin >> B;
        cout << "Nhap C: ";
        cin >> C;
        cout << "Nhap D: ";
        cin >> D;
        break; 
    }
    
    default:
        cout << "\n{ERROR: INVALID}";
        break;
    }
}

void nhapPhuongTrinhPhanSo(PhanSo &A, PhanSo &B, PhanSo &C, PhanSo &D){
    cout << "\n -------------------------------------------";
    cout << "\n|      CHON DANG PHUONG TRINH CAN NHAP      |";
    cout << "\n|                                           |";
    cout << "\n| Dang 1: Ax + B = 0                        |";
    cout << "\n| Dang 2: Ax + B = Cx + D                   |";
    cout << "\n -------------------------------------------";

    int choice;
    cout << "\nBan lua chon dang: ";
    cin >> choice;
    switch (choice)
    {
    case 1:{
        cout << "\nNhap phan so A: ";
        cout << "\n- Nhap tu so: ";
        cin >> A.tuSo;
        cout << "- Nhap mau so: ";
        cin >> A.mauSo;
        cout << "\nNhap phan so B: ";
        cout << "\n- Nhap tu so: ";
        cin >> B.tuSo;
        cout << "- Nhap mau so: ";
        cin >> B.mauSo;
        break;
    }

    case 2:{
        cout << "\nNhap phan so A: ";
        cout << "\n- Nhap tu so: ";
        cin >> A.tuSo;
        cout << "- Nhap mau so: ";
        cin >> A.mauSo;
        cout << "\nNhap phan so B: ";
        cout << "\n- Nhap tu so: ";
        cin >> B.tuSo;
        cout << "- Nhap mau so: ";
        cin >> B.mauSo;
        cout << "\nNhap phan so C: ";
        cout << "\n- Nhap tu so: ";
        cin >> C.tuSo;
        cout << "- Nhap mau so: ";
        cin >> C.mauSo;
        cout << "\nNhap phan so D: ";
        cout << "\n- Nhap tu so: ";
        cin >> D.tuSo;
        cout << "- Nhap mau so: ";
        cin >> D.mauSo;
        break; 
    }
    
    default:
        cout << "\n{ERROR: INVALID}";
        break;
    }
}

void nhapPhuongTrinhSoPhuc(SoPhuc &A, SoPhuc &B, SoPhuc &C, SoPhuc &D){
    cout << "\n -------------------------------------------";
    cout << "\n|      CHON DANG PHUONG TRINH CAN NHAP      |";
    cout << "\n|                                           |";
    cout << "\n| Dang 1: Ax + B = 0                        |";
    cout << "\n| Dang 2: Ax + B = Cx + D                   |";
    cout << "\n -------------------------------------------";

    int choice;
    cout << "\nBan lua chon dang: ";
    cin >> choice;
    switch (choice)
    {
    case 1:{
        cout << "\nNhap so phuc A: ";
        cout << "\n- Nhap phan thuc: ";
        cin >> A.phanThuc;
        cout << "- Nhap phan ao: ";
        cin >> A.phanAo;
        cout << "\nNhap so phuc B: ";
        cout << "\n- Nhap phan thuc: ";
        cin >> B.phanThuc;
        cout << "- Nhap phan ao: ";
        cin >> B.phanAo;
        break;
    }

    case 2:{
        cout << "\nNhap so phuc A: ";
        cout << "\n- Nhap phan thuc: ";
        cin >> A.phanThuc;
        cout << "- Nhap phan ao: ";
        cin >> A.phanAo;
        cout << "\nNhap so phuc B: ";
        cout << "\n- Nhap phan thuc: ";
        cin >> B.phanThuc;
        cout << "- Nhap phan ao: ";
        cin >> B.phanAo;
        cout << "\nNhap so phuc C: ";
        cout << "\n- Nhap phan thuc: ";
        cin >> C.phanThuc;
        cout << "- Nhap phan ao: ";
        cin >> C.phanAo;
        cout << "\nNhap so phuc D: ";
        cout << "\n- Nhap phan thuc: ";
        cin >> D.phanThuc;
        cout << "- Nhap phan ao: ";
        cin >> D.phanAo;
        break; 
    }
    
    default:
        cout << "\n{ERROR: INVALID}";
        break;
    }
   
}

void nhapChuongTrinh(){
    char choice;
    int equationsSolved = 0;
    auto start = chrono::high_resolution_clock::now();

    while (equationsSolved < 10) {
        auto now = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::minutes>(now - start);
        if (duration.count() >= 10) {
            cout << "Het thoi gian cho. Ket thuc nhap." << endl;
            break;
        } 
        //show menu (chọn 1 trong 3 loại R, F, C hoặc kết thúc Q)
        cout << "\n -------------------------------------------";
        cout << "\n|      CHON LOAI PHUONG TRINH CAN NHAP      |";
        cout << "\n|                                           |";
        cout << "\n| R/r: So Thuc                              |";
        cout << "\n| F/f: Phan So                              |";
        cout << "\n| C/c: So Phuc                              |";
        cout << "\n| Q/q: Thoat                                |";
        cout << "\n -------------------------------------------";
        cout << "\nNhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 'r':
            case 'R': {
                float A, B, C, D;
                nhapPhuongTrinhSoThuc(A, B, C, D);
                cout << "\n=====================================================";
                break;
            }
            case 'f':
            case 'F': {
                PhanSo A, B, C, D;
                nhapPhuongTrinhPhanSo(A, B, C, D);
                cout << "\n=====================================================";
                break;
            }
            case 'c':
            case 'C': {
                SoPhuc A, B, C, D;
                nhapPhuongTrinhSoPhuc(A, B, C, D);
                cout << "\n=====================================================";
                break;
            }
            case 'q':
            case 'Q':
                cout << "\nDang thoat chuong trinh..." << endl;
                break;
            default:
                cout << "\nLua chon khong hop le. Vui long thu lai!" << endl;
        }
    }
}

void xuatPhanSo(const PhanSo &f){
    cout << f.tuSo << "/" << f.mauSo;
}

void xuatSoPhuc(const SoPhuc &c){
    cout << c.phanThuc << " + " << c.phanAo << "i";
}

float nghiemThuc(float A, float B, float C, float D, int choice){
    float result;

    if (choice == 1){    //Ax + B = 0
        result = - B/A;
    }else if(choice == 2){  //Ax + B = Cx + D
        result = (D - B)/(A - C);
    }

    return result;
}

PhanSo nghiemPhanSo(PhanSo A, PhanSo B, PhanSo C, PhanSo D, int choice){
    PhanSo result;

    if (choice == 1){    //Ax + B = 0
        result.tuSo = - B.tuSo * A.mauSo;
        result.mauSo = B.mauSo * A.tuSo;
    }else if(choice == 2){  //Ax + B = Cx + D
        result.tuSo = ((D.tuSo * B.mauSo) - (D.mauSo * C.tuSo)) * (A.mauSo * C.mauSo);
        result.mauSo = (D.mauSo * B.mauSo) * ((A.tuSo * C.mauSo) - (A.mauSo * C.tuSo));
    }

    return result;

}

SoPhuc nghiemSoPhuc(SoPhuc A, SoPhuc B, SoPhuc C, SoPhuc D, int choice){
    SoPhuc result;

    if (choice == 1){    //Ax + B = 0
        result.phanThuc = ((-B.phanThuc * A.phanThuc) + (-B.phanAo * C.phanAo))/(A.phanThuc*A.phanThuc + A.phanAo * A.phanAo);
        result.phanAo = ((-B.phanAo * A.phanThuc) + (B.phanThuc *A.phanAo))/(A.phanThuc*A.phanThuc + A.phanAo * A.phanAo);
    }else if(choice == 2){  //Ax + B = Cx + D
        result.phanThuc = ((D.phanThuc - B.phanThuc)*(A.phanThuc - C.phanThuc) + (D.phanAo - B.phanAo)*(A.phanAo - C.phanAo))/((A.phanThuc - C.phanThuc)*(A.phanThuc - C.phanThuc) + (A.phanAo - C.phanAo)*(A.phanAo - C.phanAo));
        result.phanAo = ((D.phanAo - B.phanAo)*(A.phanThuc - C.phanThuc) - (D.phanThuc - B.phanThuc)*(A.phanAo - C.phanAo))/((A.phanThuc - C.phanThuc)*(A.phanThuc - C.phanThuc) + (A.phanAo - C.phanAo)*(A.phanAo - C.phanAo));
    }

    return result;
}

void xuatNghiemThuc(float A, float B, float C, float D, int choice){
    if (choice == 1){
        cout << "\nPhuong trinh " << A << "x + " << B << " = 0 co nghiem x = " << nghiemThuc(A, B, C, D, choice);
    } else if (choice == 2){
        cout << "\nPhuong trinh " << A << "x + " << B << " = " << C << "x + " << D << " co nghiem x = " << nghiemThuc(A, B, C, D, choice);
    }
}

void xuatNghiemPhanSo(PhanSo A, PhanSo B, PhanSo C, PhanSo D, int choice){
    if (choice == 1){
        cout << "\nPhuong trinh (" << A.tuSo << "/" << A.mauSo << ")x + " << B.tuSo << "/" << B.mauSo << " = 0 co nghiem x = "; 
        xuatPhanSo(nghiemPhanSo(A, B, C, D, choice)); 
    }else if (choice == 2){
        cout << "\nPhuong trinh (" << A.tuSo << "/" << A.mauSo << ")x + " << B.tuSo << "/" << B.mauSo << " = (" << C.tuSo << "/" << C.mauSo << ")x + " << D.tuSo << "/" << D.mauSo << " co nghiem x = "; 
        xuatPhanSo(nghiemPhanSo(A, B, C, D, choice)); 
    }
}

void xuatNghiemPhuc(SoPhuc A, SoPhuc B, SoPhuc C, SoPhuc D, int choice){
    if (choice == 1){
        cout << "\nPhuong trinh (" << A.phanThuc << " + " << A.phanAo << "i)x + (" << B.phanThuc << " + " << B.phanAo << "i) = 0 co nghiem x = "; 
        xuatSoPhuc(nghiemSoPhuc(A, B, C, D, choice)); 
    }else if (choice == 2){
        cout << "\nPhuong trinh (" << A.phanThuc << " + " << A.phanAo << "i)x + (" << B.phanThuc << " + " << B.phanAo << "i) = (" << C.phanThuc << " + " << C.phanAo << "i)x + (" << D.phanThuc << " + " << D.phanAo << "i) co nghiem x = "; 
        xuatSoPhuc(nghiemSoPhuc(A, B, C, D, choice)); 
    }   
}

void xuatChuongTrinh(){
    
}