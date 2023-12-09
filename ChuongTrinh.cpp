#include<iostream>
// #include"PhanSo.h"
// #include"SoPhuc.h"
#include"ChuongTrinh.h"
#include <chrono>
#include <vector>

using namespace std;

void nhapPhuongTrinhSoThuc(double &A, double &B, double &C, double &D, int choice) {
    switch (choice) {
        case 1: {
            cout << "\nNhap A: ";
            cin >> A;
            cout << "Nhap B: ";
            cin >> B;
            break;
        }

        case 2: {
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

void nhapPhuongTrinhPhanSo(PhanSo &A, PhanSo &B, PhanSo &C, PhanSo &D, int choice) {
    switch (choice) {
        case 1: {
            cout << "\nNhap phan so A: ";
            cout << "\n- Nhap tu so: ";
            cin >> A.tuSo;
            cout << "- Nhap mau so (mau so != 0): ";
            cin >> A.mauSo;
            cout << "\nNhap phan so B: ";
            cout << "\n- Nhap tu so: ";
            cin >> B.tuSo;
            cout << "- Nhap mau so (mau so != 0): ";
            cin >> B.mauSo;
            break;
        }

        case 2: {
            cout << "\nNhap phan so A: ";
            cout << "\n- Nhap tu so: ";
            cin >> A.tuSo;
            cout << "- Nhap mau so (mau so != 0): ";
            cin >> A.mauSo;
            cout << "\nNhap phan so B: ";
            cout << "\n- Nhap tu so: ";
            cin >> B.tuSo;
            cout << "- Nhap mau so (mau so != 0): ";
            cin >> B.mauSo;
            cout << "\nNhap phan so C: ";
            cout << "\n- Nhap tu so: ";
            cin >> C.tuSo;
            cout << "- Nhap mau so (mau so != 0): ";
            cin >> C.mauSo;
            cout << "\nNhap phan so D: ";
            cout << "\n- Nhap tu so: ";
            cin >> D.tuSo;
            cout << "- Nhap mau so (mau so != 0): ";
            cin >> D.mauSo;
            break;
        }

        default:
            cout << "\n{ERROR: INVALID}";
            break;
    }
}

void nhapPhuongTrinhSoPhuc(SoPhuc &A, SoPhuc &B, SoPhuc &C, SoPhuc &D, int choice) {
    switch (choice) {
        case 1: {
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

        case 2: {
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

void xuatPhanSo(const PhanSo &f) {
    cout << f.tuSo << "/" << f.mauSo;
}

void xuatSoPhuc(const SoPhuc &c) {
    cout << c.phanThuc << " + " << c.phanAo << "i";
}

double nghiemThuc(double A, double B, double C, double D, int choice) {
    double result = 0;

    if (choice == 1) {    //Ax + B = 0
        result = -B / A;
    } else if (choice == 2) {  //Ax + B = Cx + D
        result = (D - B) / (A - C);
    }

    return result;
}

PhanSo nghiemPhanSo(const PhanSo &A, const PhanSo &B, const PhanSo &C, const PhanSo &D, int choice) {
    PhanSo result;

    if (choice == 1) {    //Ax + B = 0
        result.tuSo = -B.tuSo * A.mauSo;
        result.mauSo = B.mauSo * A.tuSo;
    } else if (choice == 2) {  //Ax + B = Cx + D
        result.tuSo = ((D.tuSo * B.mauSo) - (D.mauSo * C.tuSo)) * (A.mauSo * C.mauSo);
        result.mauSo = (D.mauSo * B.mauSo) * ((A.tuSo * C.mauSo) - (A.mauSo * C.tuSo));
    }

    return result;
}

SoPhuc nghiemSoPhuc(const SoPhuc &A, const SoPhuc &B, const SoPhuc &C, const SoPhuc &D, int choice) {
    SoPhuc result;

    if (choice == 1) {    //Ax + B = 0
        result.phanThuc = ((-B.phanThuc * A.phanThuc) + (-B.phanAo * C.phanAo)) / (A.phanThuc * A.phanThuc + A.phanAo * A.phanAo);
        result.phanAo = ((-B.phanAo * A.phanThuc) + (B.phanThuc * A.phanAo)) / (A.phanThuc * A.phanThuc + A.phanAo * A.phanAo);
    } else if (choice == 2) {  //Ax + B = Cx + D
        result.phanThuc = ((D.phanThuc - B.phanThuc) * (A.phanThuc - C.phanThuc) + (D.phanAo - B.phanAo) * (A.phanAo - C.phanAo)) / ((A.phanThuc - C.phanThuc) * (A.phanThuc - C.phanThuc) + (A.phanAo - C.phanAo) * (A.phanAo - C.phanAo));
        result.phanAo = ((D.phanAo - B.phanAo) * (A.phanThuc - C.phanThuc) - (D.phanThuc - B.phanThuc) * (A.phanAo - C.phanAo)) / ((A.phanThuc - C.phanThuc) * (A.phanThuc - C.phanThuc) + (A.phanAo - C.phanAo) * (A.phanAo - C.phanAo));
    }

    return result;
}

void xuatNghiemThuc(double A, double B, double C, double D, int choice) {
    if (choice == 1) {
        cout << "\nPhuong trinh " << A << "x + " << B << " = 0 co nghiem x = " << nghiemThuc(A, B, C, D, choice);
    } else if (choice == 2) {
        cout << "\nPhuong trinh " << A << "x + " << B << " = " << C << "x + " << D << " co nghiem x = " << nghiemThuc(A, B, C, D, choice);
    }
}

void xuatNghiemPhanSo(const PhanSo &A, const PhanSo &B, const PhanSo &C, const PhanSo &D, int choice) {
    if (choice == 1) {
        cout << "\nPhuong trinh (" << A.tuSo << "/" << A.mauSo << ")x + " << B.tuSo << "/" << B.mauSo << " = 0 co nghiem x = ";
        xuatPhanSo(nghiemPhanSo(A, B, C, D, choice));
    } else if (choice == 2) {
        cout << "\nPhuong trinh (" << A.tuSo << "/" << A.mauSo << ")x + " << B.tuSo << "/" << B.mauSo << " = (" << C.tuSo << "/" << C.mauSo << ")x + " << D.tuSo << "/" << D.mauSo << " co nghiem x = ";
        xuatPhanSo(nghiemPhanSo(A, B, C, D, choice));
    }
}

void xuatNghiemPhuc(const SoPhuc &A, const SoPhuc &B, const SoPhuc &C, const SoPhuc &D, int choice) {
    if (choice == 1) {
        cout << "\nPhuong trinh (" << A.phanThuc << " + " << A.phanAo << "i)x + (" << B.phanThuc << " + " << B.phanAo << "i) = 0 co nghiem x = ";
        xuatSoPhuc(nghiemSoPhuc(A, B, C, D, choice));
    } else if (choice == 2) {
        cout << "\nPhuong trinh (" << A.phanThuc << " + " << A.phanAo << "i)x + (" << B.phanThuc << " + " << B.phanAo << "i) = (" << C.phanThuc << " + " << C.phanAo << "i)x + (" << D.phanThuc << " + " << D.phanAo << "i) co nghiem x = ";
        xuatSoPhuc(nghiemSoPhuc(A, B, C, D, choice));
    }
}

void xuatPhuongTrinh(char choice, int _choice, const double &A_r, const double &B_r, const double &C_r, const double &D_r, const PhanSo &A_f, const PhanSo &B_f, const PhanSo &C_f, const PhanSo &D_f,
                      const SoPhuc &A_c, const SoPhuc &B_c, const SoPhuc &C_c, const SoPhuc &D_c) {
    if (choice == 'R' || choice == 'r'){
        if (_choice == 1){
            if (A_r == 0 && B_r != 0){
                cout << "\nPhuong trinh " << A_r << "x + " << B_r << " = 0 vo nghiem";
            }else{
                xuatNghiemThuc(A_r, B_r, C_r, D_r, 1);
            }
        }else {
            if (A_r == C_r && B_r != D_r){
                cout << "\nPhuong trinh " << A_r << "x + " << B_r << " = " << C_r << "x + " << D_r << " vo nghiem";
            }else if(A_r == C_r && B_r == D_r){
                cout << "\nPhuong trinh " << A_r << "x + " << B_r << " = " << C_r << "x + " << D_r << " co vo so nghiem";
            }else {
                xuatNghiemThuc(A_r, B_r, C_r, D_r, 2);
            }
        }
    }else if(choice == 'F' || choice == 'f'){
        if (_choice == 1){
            if (A_f.tuSo == 0 && B_f.tuSo != 0){
                cout << "\nPhuong trinh (" << A_f.tuSo << "/" << A_f.mauSo << ")x + " << B_f.tuSo << "/" << B_f.mauSo << " = 0 vo nghiem ";
            }else {
                xuatNghiemPhanSo(A_f, B_f, C_f, D_f, 1);
            }
        }else {
            if ((A_f.tuSo / A_f.mauSo == C_f.tuSo / C_f.mauSo) && (B_f.tuSo/B_f.mauSo != D_f.tuSo / D_f.mauSo)){
                cout << "\nPhuong trinh (" << A_f.tuSo << "/" << A_f.mauSo << ")x + " << B_f.tuSo << "/" << B_f.mauSo << " = (" << C_f.tuSo << "/" << C_f.mauSo << ")x + " << D_f.tuSo << "/" << D_f.mauSo << " vo nghiem";
            }else if ((A_f.tuSo / A_f.mauSo == C_f.tuSo / C_f.mauSo) && (B_f.tuSo/B_f.mauSo == D_f.tuSo / D_f.mauSo)){
                cout << "\nPhuong trinh (" << A_f.tuSo << "/" << A_f.mauSo << ")x + " << B_f.tuSo << "/" << B_f.mauSo << " = (" << C_f.tuSo << "/" << C_f.mauSo << ")x + " << D_f.tuSo << "/" << D_f.mauSo << " vo so nghiem";
            }else {
                xuatNghiemPhanSo(A_f, B_f, C_f, D_f, 2);
            }
        }
    }else if (choice == 'C' || choice == 'c'){
        if (_choice == 1){
            if (A_c.phanThuc == 0 &&  A_c.phanAo == 0 && (B_c.phanThuc != 0 || B_c.phanAo != 0)){
                cout << "\nPhuong trinh (" << A_c.phanThuc << " + " << A_c.phanAo << "i)x + (" << B_c.phanThuc << " + " << B_c.phanAo << "i) = 0 vo nghiem";
            }else {
                xuatNghiemPhuc(A_c, B_c, C_c, D_c, 1);
            }
        }else {
            if (A_c.phanThuc - C_c.phanThuc == 0 && A_c.phanAo - C_c.phanAo == 0 && (B_c.phanThuc - D_c.phanThuc != 0 || B_c.phanAo - D_c.phanAo != 0)){
                cout << "\nPhuong trinh (" << A_c.phanThuc << " + " << A_c.phanAo << "i)x + (" << B_c.phanThuc << " + " << B_c.phanAo << "i) = (" << C_c.phanThuc << " + " << C_c.phanAo << "i)x + (" << D_c.phanThuc << " + " << D_c.phanAo << "i) vo nghiem";
            }else if (A_c.phanThuc - C_c.phanThuc == 0 && A_c.phanAo - C_c.phanAo == 0 && B_c.phanThuc - D_c.phanThuc == 0 && B_c.phanAo - D_c.phanAo == 0){
                cout << "\nPhuong trinh (" << A_c.phanThuc << " + " << A_c.phanAo << "i)x + (" << B_c.phanThuc << " + " << B_c.phanAo << "i) = (" << C_c.phanThuc << " + " << C_c.phanAo << "i)x + (" << D_c.phanThuc << " + " << D_c.phanAo << "i) vo so nghiem";
            }else {
                xuatNghiemPhuc(A_c, B_c, C_c, D_c, 2);
            }
        }
    }
}

void ChuongTrinh() {
    bool check = true;
    char choice;
    int _choice;

    vector<double> A_r_vec, B_r_vec, C_r_vec, D_r_vec;
    vector<PhanSo> A_f_vec, B_f_vec, C_f_vec, D_f_vec;
    vector<SoPhuc> A_c_vec, B_c_vec, C_c_vec, D_c_vec;
    vector<int> __choice;
    vector<char> choice_type;

    int equationsSolved = 0;
    auto start = chrono::high_resolution_clock::now();

    while (equationsSolved < 10) {
        auto now = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::minutes>(now - start);
        if (duration.count() >= 10 || check == false) {
            for (int i = 0; i < equationsSolved; i++) {
                xuatPhuongTrinh(choice_type[i], __choice[i], A_r_vec[i], B_r_vec[i], C_r_vec[i], D_r_vec[i],
                                 A_f_vec[i], B_f_vec[i], C_f_vec[i], D_f_vec[i],
                                 A_c_vec[i], B_c_vec[i], C_c_vec[i], D_c_vec[i]);
            }
            cout << "\n\nChuong trinh dung. Ket thuc nhap." << endl;
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
                cout << "\n -------------------------------------------";
                cout << "\n|      CHON DANG PHUONG TRINH CAN NHAP      |";
                cout << "\n|                                           |";
                cout << "\n| Dang 1: Ax + B = 0                        |";
                cout << "\n| Dang 2: Ax + B = Cx + D                   |";
                cout << "\n -------------------------------------------";
                cout << "\nBan lua chon dang: ";
                cin >> _choice;
                double A_r, B_r;
                double C_r = 0;
                double D_r = 0;
                nhapPhuongTrinhSoThuc(A_r, B_r, C_r, D_r, _choice);
                A_r_vec.push_back(A_r);
                B_r_vec.push_back(B_r);
                C_r_vec.push_back(C_r);
                D_r_vec.push_back(D_r);
                choice_type.push_back('R');
                __choice.push_back(_choice);
                if (A_r == 0 && B_r == 0 && C_r == 0 && D_r == 0) {
                    check = false;
                }
                cout << "\n=====================================================";
                equationsSolved++;
                break;
            }
            case 'f':
            case 'F': {
                cout << "\n -------------------------------------------";
                cout << "\n|      CHON DANG PHUONG TRINH CAN NHAP      |";
                cout << "\n|                                           |";
                cout << "\n| Dang 1: Ax + B = 0                        |";
                cout << "\n| Dang 2: Ax + B = Cx + D                   |";
                cout << "\n -------------------------------------------";
                cout << "\nBan lua chon dang: ";
                cin >> _choice;
        
                int C_f_tuSo = 0;
                int D_f_tuSo = 0;
                
                PhanSo A_f, B_f;
                PhanSo C_f = {C_f_tuSo, 1};
                PhanSo D_f = {D_f_tuSo, 1};
                nhapPhuongTrinhPhanSo(A_f, B_f, C_f, D_f, _choice);
                A_f_vec.push_back(A_f);
                B_f_vec.push_back(B_f);
                C_f_vec.push_back(C_f);
                D_f_vec.push_back(D_f);
                choice_type.push_back('F');
                __choice.push_back(_choice);
                if (A_f.tuSo == 0 && B_f.tuSo == 0 && C_f.tuSo == 0 && D_f.tuSo == 0) {
                    check = false;
                }
                cout << "\n=====================================================";
                equationsSolved++;
                break;
            }
            case 'c':
            case 'C': {
                cout << "\n -------------------------------------------";
                cout << "\n|      CHON DANG PHUONG TRINH CAN NHAP      |";
                cout << "\n|                                           |";
                cout << "\n| Dang 1: Ax + B = 0                        |";
                cout << "\n| Dang 2: Ax + B = Cx + D                   |";
                cout << "\n -------------------------------------------";
                cout << "\nBan lua chon dang: ";
                cin >> _choice;
                double C_c_phanThuc = 0;
                double C_c_phanAo = 0;
                
                double D_c_phanThuc = 0;
                double D_c_phanAo = 0;
                
                SoPhuc A_c, B_c;
                SoPhuc C_c = {C_c_phanThuc, C_c_phanAo};
                SoPhuc D_c = {D_c_phanThuc, D_c_phanAo};
                
                nhapPhuongTrinhSoPhuc(A_c, B_c, C_c, D_c, _choice);
                A_c_vec.push_back(A_c);
                B_c_vec.push_back(B_c);
                C_c_vec.push_back(C_c);
                D_c_vec.push_back(D_c);
                choice_type.push_back('C');
                __choice.push_back(_choice);
                if (A_c.phanThuc == 0 && A_c.phanAo == 0 && B_c.phanThuc == 0 && B_c.phanAo == 0 &&
                    C_c.phanThuc == 0 && C_c.phanAo == 0 && D_c.phanThuc == 0 && D_c.phanAo == 0) {
                    check = false;
                }
                cout << "\n=====================================================";
                equationsSolved++;
                break;
            }
            case 'q':
            case 'Q':
                cout << "\nDang thoat chuong trinh..." << endl;
                check = false;
                break;
            default:
                cout << "\nLua chon khong hop le. Vui long thu lai!" << endl;
        }
    }
}