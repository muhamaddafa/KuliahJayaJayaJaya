var senin = parseInt(prompt("Masukkan Kehadiran Mahasiswa di Hari Senin: "));
var selasa = prompt("Masukkan Kehadiran Mahasiswa di Hari Selasa: ");
var rabu = prompt("Masukkan Kehadiran Mahasiswa di Hari Rabu: ");
var kamis = prompt("Masukkan Kehadiran Mahasiswa di Hari Kamis: ");
var jumat = prompt("Masukkan Kehadiran Mahasiswa di Hari Jumat: ");

function kehadiran(hari, jmlh) {
    document.write(hari);
    for (var j = 1; j <= jmlh; j++) {
        document.write("X");       
    }
    document.write("<br>");
}

document.write("<b>GRAFIK JUMLAH KEHADIRAN MAHASISWA</b><br>");
kehadiran("SENIN: ", senin);
kehadiran("SELASA: ", selasa);
kehadiran("RABU: ", rabu);
kehadiran("KAMIS: ", kamis);
kehadiran("JUMAT: ", jumat);