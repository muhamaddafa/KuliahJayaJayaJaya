var jmlhMahasiswa = prompt("Jumlah Mahasiswa: ");
var nilaiAkhir;

for (i = 1; i<=jmlhMahasiswa; i++) {
    var nama = prompt("Nama: ");
    var tugas = parseFloat(prompt("Nilai Tugas: "));
    var uts = parseFloat(prompt("Nilai UTS: "));
    var uas = parseFloat(prompt("Nilai UTS: "));

    document.write(i + ". " + nama);
    document.write("<br> Tugas: " + tugas);
    document.write("<br> UTS: " + uts);
    document.write("<br> UAS: " + uas);
    document.write("<br> Nilai Akhir: " + hitungNilaiAkhir(tugas, uts, uas).toFixed(2));
    document.write("<br> Grade: " + hitungGrade(nilaiAkhir) + "<br> <br>");

}

function hitungNilaiAkhir (tugas, uts, uas) {
    nilaiAkhir = parseFloat((tugas + uts + uas) / 3);
    return nilaiAkhir;
}

function hitungGrade (nilaiAkhir) {
    if (nilaiAkhir >= 85) {
        grade = "A";
    } else if (nilaiAkhir >= 80) {
        grade = "A-";
    } else if (nilaiAkhir >= 75) {
        grade = "B+";
    } else if (nilaiAkhir >= 70) {
        grade = "B";
    } else if (nilaiAkhir >= 65) {
        grade = "B-";
    } else if (nilaiAkhir >= 60) {
        grade = "C+";
    } else if (nilaiAkhir >= 55) {
        grade = "C";
    } else {
        grade = "D";
    }
    return grade;
}