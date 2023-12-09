struct SoPhuc{
    double phanThuc;
    double phanAo;
};

void nhapPhuongTrinhSoPhuc(SoPhuc &A, SoPhuc &B, SoPhuc &C, SoPhuc &D, int choice);
void xuatSoPhuc(const SoPhuc &c);
SoPhuc nghiemSoPhuc(const SoPhuc &A, const SoPhuc &B, const SoPhuc &C, const SoPhuc &D, int choice);
void xuatNghiemPhuc(const SoPhuc &A, const SoPhuc &B, const SoPhuc &C, const SoPhuc &D, int choice);