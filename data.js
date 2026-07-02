const Sanpham = [
    {
        maSP: "SP001",
        tenSP: "iPhone 15 Pro",
        giaSP: 30000000,
        moTa: "Điện thoại cao cấp Apple",
        mauSac: [
            {
                maMau: "BLACK",
                tenMau: "Titan Đen",
                hinhAnh: "images/ip2.webp"
            },
            {
                maMau: "WHITE",
                tenMau: "Trắng",
                hinhAnh: "images/ip1.jfif"
            }
        ]
    },
    {
        maSP: "SP002",
        tenSP: "iPhone 16 Pro",
        giaSP: 32000000,
        moTa: "Điện thoại cao cấp Apple",
        mauSac: [
            {
                maMau: "BLACK",
                tenMau: "Titan Đen",
                hinhAnh: "images/ip3.png"
            },
            {
                maMau: "GOLD",
                tenMau: "Vàng",
                hinhAnh: "images/ip4.webp"
            }
        ]
    },
    {
        maSP: "SP003",
        tenSP: "Nothing Phone 2A",
        giaSP: 8000000,
        moTa: "Điện thoại tầm trung của Nothing",
        mauSac: [
            {
                maMau: "BLACK",
                tenMau: "Đen",
                hinhAnh: "images/nt1.webp"
            },
            {
                maMau: "WHITE",
                tenMau: "Trắng",
                hinhAnh: "images/ip1.jfif"
            }
        ]
    },
    {
        maSP: "SP004",
        tenSP: "Nothing Phone 3A",
        giaSP: 9800000,
        moTa: "Điện thoại cận cao cấp của Nothing",
        mauSac: [
            {
                maMau: "BLACK",
                tenMau: "Đen",
                hinhAnh: "images/nt1.webp"
            },
            {
                maMau: "WHITE",
                tenMau: "Trắng",
                hinhAnh: "images/ip1.jfif"
            }
        ]
    },
    {
        maSP: "SP005",
        tenSP: "Nothing Phone 4A",
        giaSP: 12000000,
        moTa: "Điện thoại cao cấp của Nothing",
        mauSac: [
            {
                maMau: "BLACK",
                tenMau: "Đen",
                hinhAnh: "images/nt1.webp"
            },
            {
                maMau: "WHITE",
                tenMau: "Trắng",
                hinhAnh: "images/ip1.jfif"
            }
        ]
    }
];


function timkiemsp(tukhoa) {
    const keyword = tukhoa.toLowerCase().trim();
    return Sanpham.filter(sp => sp.tenSP.toLowerCase().includes(keyword));
}


function hienthiketqua(sanphamList) {
    const result = document.getElementById('result');
    if (!result) return;

    result.innerHTML = '';
    if (sanphamList.length === 0) {
        result.innerHTML = `<div class="col-12">Không tìm thấy sản phẩm</div>`;
        return;
    }

    sanphamList.forEach(sp => {
        const anhMacDinh = sp.mauSac[0].hinhAnh;
        const optionMau = sp.mauSac
            .map(mau => `<option value="${mau.hinhAnh}">${mau.tenMau}</option>`)
            .join('');

        const cardHTML = `
            <div class="col-12 col-md-6 col-lg-4">
                <div class="card h-100 shadow">
                    <img src="${anhMacDinh}"
                        class="card-img-top"
                        alt="${sp.tenSP}"
                        id="anh-${sp.maSP}">
                    <div class="card-body">
                        <h5 class="card-title">${sp.tenSP}</h5>
                        <p class="card-text">Mã sản phẩm: ${sp.maSP}</p>
                        <p class="card-text">Giá: ${sp.giaSP.toLocaleString()} VNĐ</p>
                        <p class="card-text">${sp.moTa}</p>
                        <select class="form-select mb-2"
                                onchange="doimausanpham(this, '${sp.maSP}')">
                            ${optionMau}
                        </select>
                    </div>
                </div>
            </div>`;

        result.innerHTML += cardHTML;
    });
}

document.addEventListener('DOMContentLoaded', () => {
    const searchbox = document.getElementById('search-box');
    const btnsearch = document.getElementById('btn-search');

    if (!searchbox || !btnsearch) return;

    btnsearch.addEventListener('click', function (e) {
        e.preventDefault();
        const tukhoa = searchbox.value;
        const ketqua = timkiemsp(tukhoa);
        hienthiketqua(ketqua);
    });

    hienthiketqua(Sanpham);
});
function doimausanpham(selectElement, maSP) {
    const anhMoi = selectElement.value;
    const anhElement = document.getElementById(`anh-${maSP}`);
    if (anhElement) {
        anhElement.src = anhMoi;
    }
}
